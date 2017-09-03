/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:31:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 11:09:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		draw_px(t_vm *vm, int at)
{
	t_ivec2		pos;
	int			px_pos;
	const int	px_width = (SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_WIDTH);
	const int	px_height = (SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_HEIGHT);

//TODO check if optim is possible
	pos.x = ((at % BOX_BY_LINE) * px_width + SQUARE_SPA);
	pos.y = ((at / BOX_BY_LINE) * px_height + SQUARE_SPA);
	px_pos = pos.x * N_CHANNELS + pos.y * vm->gtk.rowstride;
	draw_rect(vm->gtk.pixels + px_pos, vm->gtk.rowstride,
		(t_ivec2){SQUARE_WIDTH, SQUARE_HEIGHT}, px_calc_color(vm, at));
	cairo_pango_draw_text(vm, at, pos);
	return (0);
}