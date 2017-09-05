/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:30 by philippe          #+#    #+#             */
/*   Updated: 2017/09/05 22:12:10 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_sti(t_vm *vm, t_process *process, t_op op, int *args)
{
	int		address;

	args[1] = (op.params[1] & T_REG ? process->r[args[1]] : args[1]);
	args[2] = (op.params[2] & T_REG ? process->r[args[2]] : args[2]);
	address = (args[1] + args[2] + process->pc) % MEM_SIZE;
	ft_memcpy(&vm->area[address], &process->r[args[0]], REG_SIZE);
	process->carry = !process->r[args[0]] ? 1 : 0;
	return (0);
}
