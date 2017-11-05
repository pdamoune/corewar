/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:07 by philippe          #+#    #+#             */
/*   Updated: 2017/11/05 17:14:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Hi Corrector, In a perfect world, we will call analyze_long_value instead
** of analyze_value. Thanks to Zaz and to his vm, we are making diff output.
** So we let analyze_value in our code.
** Kiss Xoxoxoxoxoxox
*/

int		op_lldi(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	unsigned int		val[MAX_ARGS_NUMBER];
	unsigned int		addr;

	(void)pc_inc;
	ft_memcpy(val, args, sizeof(unsigned int) * 2);
	analyze_value(vm, p, val, 2);
	addr = p->pc + (int)(val[0] + val[1]);
	if (IS_SET(vm->flag, OPERATION))
	{
		verbose(vm, MSG_STD,
		"P %4d | lldi %d %d r%d\n"
		"       | -> load from %d + %d = %d (with pc %d)",
		p->id, val[0], val[1], args[2],
		val[0], val[1], val[0] + val[1], addr);
	}
	p->r[args[2] - 1] = get_value_at(vm, calc_addr(addr), REG_SIZE);
	p->carry = !p->r[args[2] - 1];
	return (0);
}
