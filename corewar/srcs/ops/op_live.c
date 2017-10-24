/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/24 10:48:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	(void)pc_inc;
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | live %d", p->id, args[0]);
	args[0] = -args[0] - 1;
	p->last_live = vm->cycle;
	++vm->livetmp;
	if (args[0] > MAX_PLAYERS || !vm->file[args[0]].is_used)
		return (verbose(vm, MSG_WARNING, "Bad player number: %u", args[0]));
	++vm->file[args[0]].live;
	vm->file[args[0]].last_live = vm->cycle;
	p->id_player = args[0];
	vm->winner = args[0];
	verbose(vm, MSG_STD, "Player %d (%s) is said to be alive",
				args[0] + 1, vm->file[args[0]].header.prog_name);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		update_players(vm, args[0]);
		SET(vm->gtk.px[p->pc].flag, LIVE);
		vm->gtk.px[p->pc].is_new = CYCLE_CHANGED;
		calcul_px(vm, p->pc);
	}
	return (0);
}
