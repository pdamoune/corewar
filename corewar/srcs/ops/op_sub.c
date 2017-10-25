/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:37 by philippe          #+#    #+#             */
/*   Updated: 2017/10/12 15:03:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_sub(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	(void)pc_inc;
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | sub r%d r%d r%d", p->id, args[0], args[1], args[2]);
	p->r[args[2] - 1] = p->r[args[0] - 1] - p->r[args[1] - 1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
