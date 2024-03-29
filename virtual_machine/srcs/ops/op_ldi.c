/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:43 by philippe          #+#    #+#             */
/*   Updated: 2017/10/24 10:48:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ldi(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	unsigned int		val[MAX_ARGS_NUMBER];
	unsigned int		addr;

	(void)pc_inc;
	ft_memcpy(val, args, sizeof(unsigned int) * 2);
	analyze_value(vm, p, val, 2);
	addr = p->pc + ((int)(val[0] + val[1]) % IDX_MOD);
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | ldi %d %d r%d\n"
		"       | -> load from %d + %d = %d (with pc and mod %d)",
		p->id, val[0], val[1], args[2],
		val[0], val[1], val[0] + val[1], addr);
	addr = calc_addr(addr);
	p->r[args[2] - 1] = get_value_at(vm, addr, REG_SIZE);
	return (0);
}
