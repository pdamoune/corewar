/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_underline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:59:58 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 19:18:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		draw_cairo_border(cairo_t *cr, t_ivec2 pos, const t_color color)
{
	cairo_set_source_rgb(cr, color.r, color.g, color.b);
	cairo_rectangle(cr, pos.x, pos.y,
						SQUARE_WIDTH + 3 * SQUARE_BORDER, SQUARE_BORDER);
	cairo_rectangle(cr, pos.x + SQUARE_WIDTH + 3 * SQUARE_BORDER, pos.y,
						SQUARE_BORDER, SQUARE_HEIGHT + 3 * SQUARE_BORDER);
	cairo_rectangle(cr, pos.x, pos.y + SQUARE_BORDER,
						SQUARE_BORDER, SQUARE_HEIGHT + 3 * SQUARE_BORDER);
	cairo_rectangle(cr, pos.x + SQUARE_BORDER,
						pos.y + SQUARE_HEIGHT + 3 * SQUARE_BORDER,
						SQUARE_WIDTH + 3 * SQUARE_BORDER, SQUARE_BORDER);
}

int		draw_underline(t_vm *vm, int at, t_color color)
{
	t_ivec2		pos;
	cairo_t		*cr;

	cr = cairo_create(vm->gtk.surface);
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2) - SQUARE_BORDER;
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2) - SQUARE_BORDER;
	draw_cairo_border(cr, pos, color);
	cairo_fill(cr);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area(vm->gtk.draw, pos.x, pos.y,
			SQUARE_WIDTH + 4 * SQUARE_BORDER, SQUARE_HEIGHT + 4 * SQUARE_BORDER);
	return (0);
}
