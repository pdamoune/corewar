/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:50 by philippe          #+#    #+#             */
/*   Updated: 2017/10/07 01:02:00 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lfork(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int	addr;
	int				val;

	val = args[0];
	addr = p->pc + val;
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | lfork %d (%d)", p->id, val, p->pc + val);
	addr = calc_addr(addr);
	return (fork_process(vm, p, addr));
}