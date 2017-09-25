/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:50 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 17:55:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lfork(t_vm *vm, t_process *process, unsigned int *args)
{
	unsigned int	new_pc;

	new_pc = (process->pc + args[0]) % MEM_SIZE;
	return (fork_process(vm, process, new_pc));
}
