/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:32:51 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 23:05:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	calcul_border(t_vm *vm, int at)
{
	static int			previous = -1;

	if (at == previous)
		return ;
	if (previous != -1)
	{
		draw_border(vm, previous, COLOR_WHITE);
		UNSET(vm->gtk.px[previous].flag, MOUSE);
		previous = -1;
	}
	if (at != -1)
	{
		draw_border(vm, at, COLOR_GREEN);
		SET(vm->gtk.px[at].flag, MOUSE);
		previous = at;
	}
	SET(vm->flag, REDRAW);
	
	
	// pos.x = cur.x % (SQUARE_WIDTH + 2 * SQUARE_SPA);
	// pos.y = cur.y % (SQUARE_HEIGHT + 2 * SQUARE_SPA);
	// if (pos.x >= SQUARE_SPA && pos.x <= SQUARE_WIDTH + SQUARE_SPA + SQUARE_SPA / 2)
	// 	if (pos.y >= SQUARE_SPA && pos.y <= SQUARE_HEIGHT + SQUARE_SPA + SQUARE_SPA / 2)
	// 	{
	// 		// if(vm->gtk.px[pos.x + pos.y * BOX_BY_LINE].is_used) //TODO check is px is used
	// 			// DG("USED");
	// 		pos = (t_ivec2){cur.x - pos.x + SQUARE_SPA / 2, cur.y - pos.y + SQUARE_SPA / 2};
	// 		if (pos.x == previous.x && pos.y == previous.y)
	// 			return ;
	// 		draw_border(vm, pos, COLOR_GREEN);
	// 		if (previous.x)
	// 			draw_border(vm, previous, COLOR_WHITE);
	// 		previous = pos;
	// 		SET(vm->flag, REDRAW);
	// 		return ;
	// 	}
	// if (previous.x)
	// {
	// 	draw_border(vm, previous, COLOR_WHITE);
	// 	previous.x = 0;
	// 	SET(vm->flag, REDRAW);
	// }
}

// void	calcul_border(t_vm *vm, t_ivec2 cur)
// {
// 	static t_ivec2		previous = {0, 0};
// 	t_ivec2				pos;
	
// 	pos.x = cur.x % (SQUARE_WIDTH + 2 * SQUARE_SPA);
// 	pos.y = cur.y % (SQUARE_HEIGHT + 2 * SQUARE_SPA);
// 	if (pos.x >= SQUARE_SPA && pos.x <= SQUARE_WIDTH + SQUARE_SPA + SQUARE_SPA / 2)
// 		if (pos.y >= SQUARE_SPA && pos.y <= SQUARE_HEIGHT + SQUARE_SPA + SQUARE_SPA / 2)
// 		{
// 			// if(vm->gtk.px[pos.x + pos.y * BOX_BY_LINE].is_used) //TODO check is px is used
// 				// DG("USED");
// 			pos = (t_ivec2){cur.x - pos.x + SQUARE_SPA / 2, cur.y - pos.y + SQUARE_SPA / 2};
// 			if (pos.x == previous.x && pos.y == previous.y)
// 				return ;
// 			draw_border(vm, pos, COLOR_GREEN);
// 			if (previous.x)
// 				draw_border(vm, previous, COLOR_WHITE);
// 			previous = pos;
// 			SET(vm->flag, REDRAW);
// 			return ;
// 		}
// 	if (previous.x)
// 	{
// 		draw_border(vm, previous, COLOR_WHITE);
// 		previous.x = 0;
// 		SET(vm->flag, REDRAW);
// 	}
// }