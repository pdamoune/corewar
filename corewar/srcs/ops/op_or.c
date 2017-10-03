/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:15 by philippe          #+#    #+#             */
/*   Updated: 2017/10/03 17:18:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_or(t_vm *vm, t_process *p, unsigned int *args)
{
	verbose(vm, MSG_DEBUG, "%s", __func__);
	analyze_value(vm, p, args, 2);
	p->r[args[2] - 1] = args[0] | args[1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
