/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:15 by philippe          #+#    #+#             */
/*   Updated: 2017/09/12 16:12:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_or(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)&vm;(void)&process;(void)&args;
	args[0] = process->op.params[0] & T_REG ? process->r[args[0]] : args[0];
	args[1] = process->op.params[1] & T_REG ? process->r[args[1]] : args[1];
	process->r[args[2]] = args[0] | args[1];
	process->carry = !process->r[args[2]] ? 1 : 0;
	DG("\nargs 0 = %d\n", args[0]);
	DG("\nargs 1 = %d\n", args[1]);
	DG("\nargs 2 = %d\n", args[2]);
	DG("\ncarry = %d\n", process->carry);
	DG("");
	return (0);
}
