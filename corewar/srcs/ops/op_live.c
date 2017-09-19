/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/19 21:03:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(t_vm *vm, t_process *process, unsigned int *args)
{
	args[0] = -args[0] - 1;
	if (args[0] > MAX_PLAYERS || !vm->file[args[0]].is_used)
		return (ERR_COR("Bad player number"));
	if (process->op.params[0] != T_DIR)
		return (ERR_COR("Bad OCP"));
	// pour l'instant, on considère qu'un live par un process sur un mauvais id n'est pas un live
	++vm->file[args[0]].live;
	vm->file[args[0]].last_live = vm->cycle;
	process->id_player = args[0];
	process->last_live = vm->cycle;
	update_players(vm, args[0]);
	DG("\nLe joueur %d est en vie au cycle %d\n", args[0], vm->cycle);
	return (0);
}
