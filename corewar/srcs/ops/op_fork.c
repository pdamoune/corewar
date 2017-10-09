/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:27 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 15:36:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_fork(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int	addr;
	int				val;

	val = args[0];
	addr = p->pc + (val % IDX_MOD);
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | fork %d (%d)", p->id, val, addr);
	addr = calc_addr(addr);
	// verbose(vm, MSG_ERROR, "pc %u, val %d, val mod %d, pre addr: %u addr %u", p->pc, val, val %IDX_MOD, p->pc + (val % IDX_MOD), addr);
	return (fork_process(vm, p, addr));
}
