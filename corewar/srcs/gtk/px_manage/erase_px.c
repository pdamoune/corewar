/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_px.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:58:05 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 21:50:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		erase_px(t_vm *vm, int at)
{
	t_ivec2		pos;
	cairo_t		*cr;

	cr = cairo_create(vm->gtk.surface);
	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	pos.x += SQUARE_BORDER;
	pos.y += SQUARE_BORDER;
	cairo_set_source_rgb(cr, 1., 1., 1.);
	cairo_rectangle(cr, pos.x, pos.y, SQUARE_WIDTH, SQUARE_HEIGHT);
	cairo_fill(cr);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area(vm->gtk.draw, pos.x, pos.y, SQUARE_WIDTH, SQUARE_HEIGHT);
	return (0);
}