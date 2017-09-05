/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:14:29 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 17:15:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static t_itof	g_draw_px[] = 
{
	// {LIVE | MOUSE, draw_px_live_mouse},
	{LIVE, draw_px_live},
	// {MOUSE, draw_px_mouse},
	{0, 0}
};

int		calcul_px(t_vm *vm, int at)
{
	int		i;

	SET(vm->flag, REDRAW);
	if (IS_UNSET(vm->gtk.px[at].flag, USED))
		return (erase_px(vm, at));
	i = -1;
	while (g_draw_px[++i].id)
		if (IS_SET(vm->gtk.px[at].flag, g_draw_px[i].id))
			return (g_draw_px[i].f(vm, at));
	return (draw_px(vm, at));
}