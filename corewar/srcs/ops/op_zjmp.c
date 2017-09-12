/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:51 by philippe          #+#    #+#             */
/*   Updated: 2017/09/12 18:36:21 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(t_vm *vm, t_process *process, unsigned int *args)
{
	DG("\nargs 0 = %d\n", args[0]);
	DG("\nargs 1 = %d\n", args[1]);
	DG("\nargs 2 = %d\n", args[2]);
	DG("\npc = %d\n", process->pc);
	DG("\npc - arg = %d\n", process->pc + args[0]);
	DG("\ncarry = %d\n", process->carry);
	if (process->carry == 1)
		process->pc = move_pc(vm, process->pc, ((int)args[0]) % IDX_MOD - 3);
	return (0);
}
