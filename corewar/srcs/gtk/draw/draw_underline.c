/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_underline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:59:58 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 16:14:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		draw_underline(t_vm *vm, int at, t_color color)
{
	t_ivec2		pos;
	int			px_pos;
	const int	px_width = (SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_WIDTH);
	const int	px_height = (SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_HEIGHT);

	pos.x = ((at % BOX_BY_LINE) * px_width + SQUARE_SPA - SQUARE_BORDER);
	pos.y = ((at / BOX_BY_LINE) * px_height + SQUARE_SPA + SQUARE_HEIGHT + SQUARE_BORDER);
	px_pos = pos.x * N_CHANNELS + pos.y * vm->gtk.rowstride;
	draw_rect(vm->gtk.pixels + px_pos, vm->gtk.rowstride,
		(t_ivec2){SQUARE_WIDTH + 2 * SQUARE_BORDER, SQUARE_BORDER}, color);
	SET(vm->flag, REDRAW);
	return (0);
}