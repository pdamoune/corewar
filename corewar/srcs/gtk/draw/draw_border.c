/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:35:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 23:08:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	draw_border(t_vm *vm, int at, const t_color color)
{
	t_ivec2		size[2];
	int			rowstride;
	t_ivec2		pos;

	pos.x = ((at % BOX_BY_LINE) * PX_WIDTH + SQUARE_SPA / 2);
	pos.y = ((at / BOX_BY_LINE) * PX_HEIGHT + SQUARE_SPA / 2);
	rowstride = vm->gtk.rowstride;
	size[0] = (t_ivec2){SQUARE_WIDTH + 2 * SQUARE_BORDER, SQUARE_HEIGHT + 2 * SQUARE_BORDER};
	size[1] = (t_ivec2){SQUARE_WIDTH, SQUARE_HEIGHT};
	draw_rect_border(vm->gtk.pixels + pos.x * N_CHANNELS + pos.y * rowstride,
					rowstride, size, color);
}