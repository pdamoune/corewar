/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:42:01 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/05 22:10:22 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(t_vm *vm, t_process *process, t_op op, int *args)
{
	if ((unsigned)args[0] > MAX_PLAYERS || op.params[0] != T_DIR)
		return (DG("Bad player number || Bad OCP"));
	vm->players[args[0]].live++;
	vm->players[args[0]].last_live = vm->cycle;
	process->id_player = args[0];
	process->last_live = vm->cycle;
	DG("\nLe joueur %d est en vie au cycle %d\n", args[0], vm->cycle);
	return (0);
}
