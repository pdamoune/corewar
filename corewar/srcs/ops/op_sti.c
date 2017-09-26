/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:30 by philippe          #+#    #+#             */
/*   Updated: 2017/09/26 19:35:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_sti(t_vm *vm, t_process *p, unsigned int *args)
{
	// int		address;

	// DG("\nargs 0 = %d\n", args[0]);
	// DG("\nargs 1 = %d\n", args[1]);
	// DG("\nargs 2 = %d\n", args[2]);

	// args[0] = (IS_SET(p->op.params[0], T_REG) ? p->r[args[0] - 1] : args[0]);
	// args[1] = (IS_SET(p->op.params[1], T_REG) ? p->r[args[1] - 1] : args[1]);
	// args[2] = (IS_SET(p->op.params[2], T_REG) ? p->r[args[2] - 1] : args[2]);
	// set_value_in_area(vm, p->pc + ((int)(args[1] + args[2]) % IDX_MOD), args[0], 4);
	analyze_value(vm, p, args, 3);
	set_value_in_area(vm, p->pc + ((int)(args[1] + args[2]) % IDX_MOD), args[0], 4);
	return (0);
}
