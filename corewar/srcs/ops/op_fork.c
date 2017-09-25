/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:27 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 17:54:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_fork(t_vm *vm, t_process *process, unsigned int *args)
{
	unsigned int	new_pc;

	new_pc = (process->pc + (args[0] % IDX_MOD)) % MEM_SIZE;
	return (fork_process(vm, process, new_pc));
}