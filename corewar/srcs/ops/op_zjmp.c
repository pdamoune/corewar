/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:51 by philippe          #+#    #+#             */
/*   Updated: 2017/09/06 14:14:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(t_vm *vm, t_process *process, unsigned int *args)
{
	if (process->carry == 1)
		process->pc = move_pc(vm, process->pc, (args[0] % IDX_MOD) - 3);
	return (0);
}
