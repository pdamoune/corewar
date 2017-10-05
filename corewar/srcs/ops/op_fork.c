/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:27 by philippe          #+#    #+#             */
/*   Updated: 2017/10/05 16:36:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_fork(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int	new_pc;

	verbose(vm, MSG_DEBUG, "%s", __func__);
	new_pc = calc_addr(p->pc + (args[0] % IDX_MOD));
	return (fork_process(vm, p, new_pc));
}
