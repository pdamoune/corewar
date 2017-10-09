/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:18 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 16:27:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_and(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int		val[MAX_ARGS_NUMBER];

// DG();
	ft_memcpy(val, args, sizeof(unsigned int) * 2);
	analyze_value(vm, p, val, 2);
	// DG("ARGS: %u| %u| %u", args[0], args[1], args[2]);
	// DG("VAL: %u| %u", val[0], val[1]);
	// DG("this is my pc: %u", p->pc);
	// DG("%d", get_value_at(vm, p->pc + args[0] %IDX_MOD, REG_SIZE));
	// int i = -1;
	// while (++i < 45)
		// DG("%d: %d &&& %d &&&& %d", i, get_value_at(vm, i, REG_SIZE), get_value_at(vm, i, 2), get_value_at(vm, i, 1));
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | and %d %d r%d", p->id, val[0], val[1], args[2]);
	p->r[args[2] - 1] = val[0] & val[1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
