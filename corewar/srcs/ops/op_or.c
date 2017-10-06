/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:15 by philippe          #+#    #+#             */
/*   Updated: 2017/10/06 19:19:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_or(t_vm *vm, t_process *p, unsigned int *args)
{
	//TODO log as zaz
	DG("TO BE IMPLEMENTED");
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD, "HEHO", NULL);
	verbose(vm, MSG_DEBUG, "%s", __func__);
	analyze_value(vm, p, args, 2);
	p->r[args[2] - 1] = args[0] | args[1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
