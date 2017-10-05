/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:07 by philippe          #+#    #+#             */
/*   Updated: 2017/10/05 16:36:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lldi(t_vm *vm, t_process *p, unsigned int *args)
{
	verbose(vm, MSG_DEBUG, "%s", __func__);
	analyze_long_value(vm, p, args, 2);
	p->r[args[2] - 1] = get_value_at(vm,
						calc_addr(p->pc + (args[0] + args[1]) % IDX_MOD),
						REG_SIZE);
	return (0);
}
