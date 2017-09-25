/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:15 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 16:47:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_or(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)&vm;(void)&process;(void)&args;
	args[0] = process->op.params[0] & T_REG ? process->r[args[0] - 1] : args[0];
	args[1] = process->op.params[1] & T_REG ? process->r[args[1] - 1] : args[1];
	process->r[args[2] - 1] = args[0] | args[1];
	process->carry = !process->r[args[2] - 1] ? 1 : 0;
	DG("\nargs 0 = %d\n", args[0]);
	DG("\nargs 1 = %d\n", args[1]);
	DG("\nargs 2 = %d\n", args[2]);
	DG("\ncarry = %d\n", process->carry);
	DG("");
	return (0);
}
