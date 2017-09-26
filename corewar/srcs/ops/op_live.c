/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/26 19:37:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(t_vm *vm, t_process *p, unsigned int *args)
{
	args[0] = -args[0] - 1;
	if (args[0] > MAX_PLAYERS || !vm->file[args[0]].is_used)
		return (ERR_COR("Bad player number: %u", args[0]));
	if (p->op.params[0] != T_DIR)
		return (ERR_COR("Bad OCP"));
	// pour l'instant, on considère qu'un live par un process sur un mauvais id n'est pas un live
	++vm->file[args[0]].live;
	vm->file[args[0]].last_live = vm->cycle;
	p->id_player = args[0];
	p->last_live = vm->cycle;
	update_players(vm, args[0]);
	DG("\nLe joueur %d est en vie au cycle %d\n", args[0], vm->cycle);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		SET(vm->gtk.px[p->pc].flag, LIVE);
		vm->gtk.px[p->pc].is_new = CYCLE_CHANGED;
		calcul_px(vm, p->pc);
	}
	return (0);
}
