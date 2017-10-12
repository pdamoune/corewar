/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:58 by philippe          #+#    #+#             */
/*   Updated: 2017/10/12 15:02:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lld(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	(void)pc_inc;
	unsigned int		val[MAX_ARGS_NUMBER];
	// static int toto = 0;

	// int i = -1;
	// if (!toto)
	// {
	// 	toto = 1;
	// 	while (++i < MEM_SIZE)
	// 		if (get_value_at(vm, i, REG_SIZE))
	// 			verbose(vm, MSG_STD, "%d: val is %d | %hd | %hhd", i , get_value_at(vm, i, REG_SIZE), get_value_at(vm, i, 2), get_value_at(vm, i ,1));
	// }
//TODO because zaz do nimp
	ft_memcpy(val, args, sizeof(unsigned int) * 1);
	analyze_long_value(vm, p, val, 1);
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | lld %d r%d", p->id, val[0], args[1]);
	p->r[args[1] - 1] = val[0];
	p->carry = !p->r[args[1] - 1];
	return (0);
}
