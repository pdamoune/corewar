/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:07 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 19:19:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lldi(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int		val[MAX_ARGS_NUMBER];
	unsigned int		addr;

	ft_memcpy(val, args, sizeof(unsigned int) * 2);
	analyze_long_value(vm, p, val, 2);
	val[0] = 0;//IT's a hack
	addr = p->pc + (int)(val[0] + val[1]);
	DG("args : %d, val %d", args[0], val[0]);
	if (IS_SET(vm->flag, OPERATION))
	{
		verbose(vm, MSG_STD,
		"P %4d | lldi %d %d r%d\n"
		"       | -> load from %d + %d = %d (with pc %d)",
		p->id, val[0], val[1], args[2],
		val[0], val[1], val[0] + val[1], addr);
	}
	//TODO check
	p->r[args[2] - 1] = get_value_at(vm, calc_addr(addr), REG_SIZE);
	p->carry = !p->r[args[2] - 1];
	return (0);
}
