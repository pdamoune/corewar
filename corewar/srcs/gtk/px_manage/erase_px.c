/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_px.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:58:05 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 16:33:28 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		erase_px(t_vm *vm, int at)
{
	(void)vm;
	(void)at;
	//TODO this. if this func is called and there is a pc, color the box in grey
// 	DG("not implemented");
	
// 	t_ivec2		pos;
// 	int			px_pos;
// 	const int	px_width = (SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_WIDTH);
// 	const int	px_height = (SQUARE_SPA + 2 * SQUARE_BORDER + SQUARE_HEIGHT);

// //TODO check if optim is possible
// 	pos.x = ((at % BOX_BY_LINE) * px_width + SQUARE_SPA);
// 	pos.y = ((at / BOX_BY_LINE) * px_height + SQUARE_SPA);
// 	px_pos = pos.x * N_CHANNELS + pos.y * vm->gtk.rowstride;
// 	draw_rect(vm->gtk.pixels + px_pos, vm->gtk.rowstride,
// 		(t_ivec2){SQUARE_WIDTH, SQUARE_HEIGHT}, COLOR_WHITE);
	return (0);
}