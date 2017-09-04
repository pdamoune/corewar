/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:31:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 19:10:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void cairo_pango_draw_text2(t_vm *vm, cairo_t *cr, int at, t_ivec2 pos)
{
	PangoLayout *layout;
	PangoAttrList *attr_list;
	char 	*txt;

	DG();
	ft_asprintf(&txt, "%02hhx", vm->area[at]);
	cairo_move_to(cr, pos.x, pos.y);
	layout = pango_cairo_create_layout(cr);
	pango_parse_markup("<span foreground=\"red\" weight=\"light\" size=\"small\"><tt>TT</tt></span>",
					-1, 0, &attr_list, NULL, NULL, NULL);
	pango_layout_set_attributes (layout,attr_list);
	pango_layout_set_text(layout, txt, 2);
	pango_cairo_show_layout(cr, layout);
	g_object_unref(G_OBJECT(layout));
	free(txt);
}

int		draw_px_live(t_vm *vm, int at)
{
	(void)vm;
	(void)at;
	DG("NOT YET IMPLEMENTED");
	return (0);
}

int		draw_px(t_vm *vm, int at)
{
	t_ivec2		pos;
	cairo_t		*cr;

	cr = cairo_create(vm->gtk.surface);
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.x += SQUARE_BORDER;
	pos.y += SQUARE_BORDER;
	cairo_rectangle(cr, pos.x, pos.y,
						SQUARE_WIDTH, SQUARE_HEIGHT);
	cairo_fill (cr);
	cairo_pango_draw_text2(vm, cr, at, pos);
	cairo_destroy (cr);
	gtk_widget_queue_draw_area (vm->gtk.draw, pos.x, pos.y,
								SQUARE_WIDTH, SQUARE_HEIGHT);
	return (0);
}