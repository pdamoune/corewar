/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:35:49 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 11:35:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		draw_cairo_border(cairo_t *cr, t_ivec2 pos, const t_color color)
{
	cairo_set_source_rgb(cr, color.r, color.g, color.b);
	cairo_rectangle(cr, pos.x, pos.y,
						SQUARE_WIDTH + SQUARE_BORDER, SQUARE_BORDER);
	cairo_rectangle(cr, pos.x + SQUARE_WIDTH + SQUARE_BORDER, pos.y,
						SQUARE_BORDER, SQUARE_HEIGHT + SQUARE_BORDER);
	cairo_rectangle(cr, pos.x, pos.y + SQUARE_BORDER,
						SQUARE_BORDER, SQUARE_HEIGHT + SQUARE_BORDER);
	cairo_rectangle(cr, pos.x + SQUARE_BORDER,
						pos.y + SQUARE_HEIGHT + SQUARE_BORDER,
						SQUARE_WIDTH + SQUARE_BORDER, SQUARE_BORDER);
}

void			draw_border(GtkWidget *widget, t_vm *vm, int at,
							const t_color color)
{
	t_ivec2		pos;
	cairo_t		*cr;

	cr = vm->gtk.cr;
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	draw_cairo_border(cr, pos, color);
	cairo_fill(cr);
	gtk_widget_queue_draw_area(widget, pos.x, pos.y,
									SQUARE_WIDTH + 2 * SQUARE_BORDER,
									SQUARE_HEIGHT + 2 * SQUARE_BORDER);
}
