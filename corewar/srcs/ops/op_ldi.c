/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:43 by philippe          #+#    #+#             */
/*   Updated: 2017/09/13 13:56:12 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ldi(t_vm *vm, t_process *process, unsigned int *args)
{
	int pc_inc;

	(void)&vm;(void)&process;(void)&args;
	pc_inc = 4;
	args[0] = (IS_SET(process->op.params[0], T_REG) ? process->r[args[0]] : args[0]);
	args[1] = (IS_SET(process->op.params[1], T_REG) ? process->r[args[1]] : args[1]);
	// args[2] = (IS_SET(p->op.params[2], T_REG) ? p->r[args[2]] : args[2]);
	args[2] = get_value_from_area(vm, process, process->pc + ((int)(args[0] + args[1]) % IDX_MOD), &pc_inc);
	process->carry = !process->r[args[2]] ? 1 : 0;
	DG("");
	return (0);
}
