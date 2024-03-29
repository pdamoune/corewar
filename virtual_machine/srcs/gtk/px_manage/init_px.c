/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 09:09:43 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 17:07:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_px(t_vm *vm, int at, int player)
{
	if (IS_SET(vm->gtk.px[at].flag, USED))
	{
		return (verbose(vm, 3, "Can't write at pos %d. Px is already used",
				at));
	}
	SET(vm->gtk.px[at].flag, USED);
	vm->gtk.px[at].player = player;
	vm->gtk.px[at].is_new = CYCLE_CHANGED;
	return (calcul_px(vm, at));
}
