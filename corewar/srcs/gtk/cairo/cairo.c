/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cairo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 10:15:36 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 22:03:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static const cairo_user_data_key_t pixbuf_key;

/*
** pixbuf_cairo_create:
** @pixbuf: GdkPixbuf that you wish to wrap with cairo context
**
** This function will initialize new cairo context with contents of @pixbuf. You
** can then draw using returned context. When finished drawing, you must call
** pixbuf_cairo_destroy() or your pixbuf will not be updated with new contents!
**
** Return value: New cairo_t context. When you're done with it, call
** pixbuf_cairo_destroy() to update your pixbuf and free memory.
*/

static cairo_t *
pixbuf_cairo_create( GdkPixbuf *pixbuf )
{
   gint             width,        /* Width of both pixbuf and surface */
                height,       /* Height of both pixbuf and surface */
                p_stride,     /* Pixbuf stride value */
                p_n_channels, /* RGB -> 3, RGBA -> 4 */
                s_stride;     /* Surface stride value */
   guchar          *p_pixels,     /* Pixbuf's pixel data */
               *s_pixels;     /* Surface's pixel data */
   cairo_surface_t *surface;      /* Temporary image surface */
   cairo_t         *cr;           /* Final context */

   g_object_ref( G_OBJECT( pixbuf ) );

   /* Inspect input pixbuf and create compatible cairo surface */
   g_object_get( G_OBJECT( pixbuf ), "width",           &width,
                             "height",          &height,
                             "rowstride",       &p_stride,
                             "n-channels",      &p_n_channels,
                             "pixels",          &p_pixels,
                             NULL );
   surface = cairo_image_surface_create( CAIRO_FORMAT_ARGB32, width, height );
   s_stride = cairo_image_surface_get_stride( surface );
   s_pixels = cairo_image_surface_get_data( surface );

   /* Copy pixel data from pixbuf to surface */
   while( height-- )
   {
      gint    i;
      guchar *p_iter = p_pixels,
            *s_iter = s_pixels;

      for( i = 0; i < width; i++ )
      {
         /* Pixbuf:  RGB(A)
          * Surface: BGRA */
            gdouble alpha_factor = p_iter[3] / (gdouble)0xff;

            s_iter[0] = (guchar)( p_iter[2] * alpha_factor + .5 );
            s_iter[1] = (guchar)( p_iter[1] * alpha_factor + .5 );
            s_iter[2] = (guchar)( p_iter[0] * alpha_factor + .5 );
            s_iter[3] =           p_iter[3];
         s_iter += 4;
         p_iter += 4;
      }
      s_pixels += s_stride;
      p_pixels += p_stride;
   }

   /* Create context and set user data */
   cr = cairo_create( surface );
   cairo_surface_destroy( surface );
   cairo_set_user_data( cr, &pixbuf_key, pixbuf, g_object_unref );

   /* Return context */
   return( cr );
}

/*
** pixbuf_cairo_destroy:
** @cr: Cairo context that you wish to destroy
** @create_new_pixbuf: If TRUE, new pixbuf will be created and returned. If
**                     FALSE, input pixbuf will be updated in place.
**
** This function will destroy cairo context, created with pixbuf_cairo_create().
**
** Return value: New or updated GdkPixbuf. You own a new reference on return
** value, so you need to call g_object_unref() on returned pixbuf when you don't
** need it anymore.
*/

static GdkPixbuf *
pixbuf_cairo_destroy( cairo_t  *cr,
                    gboolean  create_new_pixbuf )
{
   gint             width,        /* Width of both pixbuf and surface */
                height,       /* Height of both pixbuf and surface */
                p_stride,     /* Pixbuf stride value */
                p_n_channels, /* RGB -> 3, RGBA -> 4 */
                s_stride;     /* Surface stride value */
   guchar          *p_pixels,     /* Pixbuf's pixel data */
               *s_pixels;     /* Surface's pixel data */
   cairo_surface_t *surface;      /* Temporary image surface */
   GdkPixbuf       *pixbuf,       /* Pixbuf to be returned */
               *tmp_pix;      /* Temporary storage */

   /* Obtain pixbuf to be returned */
   tmp_pix = cairo_get_user_data( cr, &pixbuf_key );
   if( create_new_pixbuf )
      pixbuf = gdk_pixbuf_copy( tmp_pix );
   else
      pixbuf = g_object_ref( G_OBJECT( tmp_pix ) );

   /* Obtain surface from where pixel values will be copied */
   surface = cairo_get_target( cr );

   /* Inspect pixbuf and surface */
   g_object_get( G_OBJECT( pixbuf ), "width",           &width,
                             "height",          &height,
                             "rowstride",       &p_stride,
                             "n-channels",      &p_n_channels,
                             "pixels",          &p_pixels,
                             NULL );
   s_stride = cairo_image_surface_get_stride( surface );
   s_pixels = cairo_image_surface_get_data( surface );

   /* Copy pixel data from surface to pixbuf */
   while( height-- )
   {
      gint    i;
      guchar *p_iter = p_pixels,
            *s_iter = s_pixels;

      for( i = 0; i < width; i++ )
      {
         /* Pixbuf:  RGB(A)
          * Surface: BGRA */
         gdouble alpha_factor = (gdouble)0xff / s_iter[3];

         p_iter[0] = (guchar)( s_iter[2] * alpha_factor + .5 );
         p_iter[1] = (guchar)( s_iter[1] * alpha_factor + .5 );
         p_iter[2] = (guchar)( s_iter[0] * alpha_factor + .5 );
         if( p_n_channels == 4 )
            p_iter[3] = s_iter[3];
         s_iter += 4;
         p_iter += p_n_channels;
      }
      s_pixels += s_stride;
      p_pixels += p_stride;
   }

   /* Destroy context */
   cairo_destroy( cr );

   /* Return pixbuf */
   return( pixbuf );
}

void cairo_pango_draw_text(t_vm *vm, int at, t_ivec2 pos)
{
//    GdkPixbuf   *new_pix;
   PangoLayout *layout;
   cairo_t     *cr;
   char 	*txt;

	ft_asprintf(&txt, "%02hhx", vm->area[at]);
//TODO stupid de copier tout a chaque text input. need to be manage in other way
   cr = pixbuf_cairo_create( gtk_image_get_pixbuf(GTK_IMAGE(vm->gtk.img)));
   cairo_set_source_rgb(cr, 0, 0, 0);//TODO util ?
   cairo_move_to(cr, pos.x, pos.y);
   layout = pango_cairo_create_layout(cr);
   
   PangoAttrList *attr_list;
   pango_parse_markup("<span foreground=\"white\" weight=\"light\" size=\"small\"><tt>TT</tt></span>",
                    -1, 0, &attr_list, NULL, NULL, NULL);
   pango_layout_set_attributes (layout,attr_list);
   pango_layout_set_text(layout, txt, 2);
   pango_cairo_show_layout(cr, layout);
   g_object_unref(G_OBJECT(layout));
   pixbuf_cairo_destroy(cr, FALSE);
//    new_pix = pixbuf_cairo_destroy(cr, FALSE);
   free(txt);
}