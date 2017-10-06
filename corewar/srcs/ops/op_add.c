/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:01 by philippe          #+#    #+#             */
/*   Updated: 2017/10/06 22:18:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_add(t_vm *vm, t_process *p, unsigned int *args)
{
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | add r%d r%d r%d", p->id, args[0], args[1], args[2]);
	p->r[args[2] - 1] = p->r[args[0] - 1] + p->r[args[1] - 1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
