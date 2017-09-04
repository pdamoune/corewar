/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_underline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:59:58 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 19:09:31 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		draw_underline(t_vm *vm, int at, t_color color)
{
	t_ivec2		pos;
	cairo_t		*cr;

	cr = cairo_create(vm->gtk.surface);
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.y += SQUARE_HEIGHT + 2 * SQUARE_BORDER;
	cairo_set_source_rgb(cr, color.r, color.g, color.b);
	cairo_rectangle(cr, pos.x, pos.y ,
						SQUARE_WIDTH + 2 * SQUARE_BORDER, SQUARE_BORDER);
	cairo_fill(cr);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area(vm->gtk.draw, pos.x, pos.y,
					SQUARE_WIDTH + 2 * SQUARE_BORDER, SQUARE_BORDER);
	return (0);
}