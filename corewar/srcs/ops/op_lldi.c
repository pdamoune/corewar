/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:07 by philippe          #+#    #+#             */
/*   Updated: 2017/09/26 19:39:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lldi(t_vm *vm, t_process *p, unsigned int *args)
{
	analyze_long_value(vm, p, args, 2);
	p->r[args[2] - 1] = get_value_at(vm, calc_addr(p->pc + (args[0] + args[1]) % IDX_MOD), REG_SIZE);
	// if (process->op.params[0] == T_IND)
	// 	args[0] = get_value_at(vm, calc_addr(p->pc + args[0]), REG_SIZE);
	// else
	// 	args[0] = process->op.params[0] == T_REG ? process->r[args[0] - 1] : args[0];
	// args[1] = process->op.params[1] == T_REG ? process->r[args[1] - 1] : args[1];
	// process->r[args[2] - 1] = get_value_at(vm, calc_addr(p->pc + (args[0] + args[1])), REG_SIZE);
	return (0);
}
