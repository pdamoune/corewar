/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/05 16:36:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(t_vm *vm, t_process *p, unsigned int *args)
{
	verbose(vm, MSG_DEBUG, "%s", __func__);
	args[0] = -args[0] - 1;
	p->last_live = vm->cycle;
	++vm->livetmp;
	if (args[0] > MAX_PLAYERS || !vm->file[args[0]].is_used)
		return (verbose(vm, MSG_WARNING, "Bad player number: %u", args[0]));
	++vm->file[args[0]].live;
	vm->file[args[0]].last_live = vm->cycle;
	p->id_player = args[0];
	verbose(vm, MSG_STD, "Le joueur %d est en vie au cycle %d",
				args[0], vm->cycle);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		update_players(vm, args[0]);
		SET(vm->gtk.px[p->pc].flag, LIVE);
		vm->gtk.px[p->pc].is_new = CYCLE_CHANGED;
		calcul_px(vm, p->pc);
	}
	return (0);
}
