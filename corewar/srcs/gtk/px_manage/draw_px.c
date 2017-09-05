/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:31:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 22:09:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <math.h>

static void draw_px_text(t_vm *vm, cairo_t *cr, int at, t_ivec2 pos)
{
	// PangoLayout *layout;
	// PangoAttrList *attr_list;
	double	x,y;
	char 	*txt;
	cairo_text_extents_t extents;
	
	cairo_set_source_rgb(cr, 0., 0., 0.);
	ft_asprintf(&txt, "%02hhx", vm->area[at]);
	cairo_text_extents(cr, txt, &extents);	
	x = pos.x + SQUARE_WIDTH / 2;
	x -= ((int)extents.width / 2 + extents.x_bearing);
	y = pos.y + SQUARE_HEIGHT / 2;
	y -= (((int)extents.height / 2 + (int)extents.y_bearing) - 1);
	cairo_move_to(cr, x, y);
	cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 9.0);
	cairo_show_text(cr, txt);
	free(txt);
	// layout = pango_cairo_create_layout(cr);
	// pango_parse_markup("<span foreground=\"red\" weight=\"light\" size=\"small\"><tt>TT</tt></span>",
	// 				-1, 0, &attr_list, NULL, NULL, NULL);
	// pango_layout_set_attributes (layout,attr_list);
	// pango_layout_set_text(layout, txt, 2);
	// pango_cairo_show_layout(cr, layout);
	// g_object_unref(G_OBJECT(layout));
	// free(txt);


	// cairo_text_extents_t extents;
	
	// const char *utf8 = "cairo";
	// double x,y;
	
	// cairo_select_font_face (cr, "Sans",
	// 	CAIRO_FONT_SLANT_NORMAL,
	// 	CAIRO_FONT_WEIGHT_NORMAL);
	
	// cairo_set_font_size (cr, 52.0);
	// cairo_text_extents (cr, utf8, &extents);
	// x = 128.0-(extents.width/2 + extents.x_bearing);
	// y = 128.0-(extents.height/2 + extents.y_bearing);
	
	// cairo_move_to (cr, x, y);
	// cairo_show_text (cr, utf8);
	
	// /* draw helping lines */
	// cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
	// cairo_set_line_width (cr, 6.0);
	// cairo_arc (cr, x, y, 10.0, 0, 2*M_PI);
	// cairo_fill (cr);
	// cairo_move_to (cr, 128.0, 0);
	// cairo_rel_line_to (cr, 0, 256);
	// cairo_move_to (cr, 0, 128.0);
	// cairo_rel_line_to (cr, 256, 0);
	// cairo_stroke (cr);
}

int		draw_px_live(t_vm *vm, int at)
{
	t_ivec2		pos;
	cairo_t		*cr;

	erase_px(vm, at);
	cr = cairo_create(vm->gtk.surface);
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.x += SQUARE_BORDER ;
	pos.y += SQUARE_BORDER ;
	cairo_set_source_rgb(cr, 0., 1., 0.);	
	cairo_arc(cr, pos.x+ SQUARE_WIDTH / 2, pos.y+ SQUARE_HEIGHT / 2, (SQUARE_HEIGHT > SQUARE_WIDTH ? SQUARE_WIDTH : SQUARE_HEIGHT) / 2, 0, 2*M_PI);
	cairo_fill(cr);
	draw_px_text(vm, cr, at, pos);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area (vm->gtk.draw, pos.x, pos.y,
								SQUARE_WIDTH * 2, SQUARE_HEIGHT * 2);
	return (0);
}

int		draw_px(t_vm *vm, int at)
{
	t_ivec2		pos;
	cairo_t		*cr;
	t_color		color;
	
	color = px_calc_color(vm, at);
	cr = cairo_create(vm->gtk.surface);
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.x += SQUARE_BORDER;
	pos.y += SQUARE_BORDER;
	cairo_set_source_rgb(cr, color.r, color.g, color.b);
	cairo_rectangle(cr, pos.x, pos.y,
						SQUARE_WIDTH, SQUARE_HEIGHT);
	cairo_fill(cr);
	draw_px_text(vm, cr, at, pos);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area(vm->gtk.draw, pos.x, pos.y,
								SQUARE_WIDTH, SQUARE_HEIGHT);
	return (0);
}