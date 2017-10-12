/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:51 by philippe          #+#    #+#             */
/*   Updated: 2017/10/12 15:09:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	int		val;

	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | zjmp %d %s", p->id, args[0], p->carry ? "OK" : "FAILED");
	val = (((int)args[0]) % IDX_MOD);
	if (p->carry)
	{
		p->pc = move_pc(vm, p->pc, val, 0);
		*pc_inc = 0;
	}
	return (0);
}
