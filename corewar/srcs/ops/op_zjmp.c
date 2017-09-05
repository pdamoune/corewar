/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:51 by philippe          #+#    #+#             */
/*   Updated: 2017/09/05 22:09:21 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(t_vm *vm, t_process *process, t_op op, int *args)
{
	(void)&op;(void)&vm;(void)&process;(void)&args;
	if (!process->carry)
		DG("Carry = 0, next process");
	process->pc = (process->pc + (args[0] % IDX_MOD)) % MEM_SIZE;
	return (0);
}
