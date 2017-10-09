/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:15 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 16:37:18 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_or(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int		val[MAX_ARGS_NUMBER];

	ft_memcpy(val, args, sizeof(unsigned int) * 2);
	analyze_long_value(vm, p, val, 2);
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | or %d %d r%d", p->id, val[0], val[1], args[2]);
	p->r[args[2] - 1] = val[0] | val[1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
