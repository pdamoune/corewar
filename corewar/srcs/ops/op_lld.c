/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:58 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 16:36:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lld(t_vm *vm, t_process *p, unsigned int *args)
{
	//TODO log as zaz
	DG("TO BE IMPLEMENTED");
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD, "HEHO", NULL);
	verbose(vm, MSG_DEBUG, "%s", __func__);
	analyze_long_value(vm, p, args, 1);
	// analyze_value(vm, p, args, 1);
	p->r[args[1] - 1] = args[0];
	p->carry = !p->r[args[1] - 1];
	return (0);
}
