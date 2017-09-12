/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:43 by philippe          #+#    #+#             */
/*   Updated: 2017/09/12 18:36:52 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ldi(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)&vm;(void)&process;(void)&args;
	args[0] = (IS_SET(p->op.params[0], T_REG) ? p->r[args[0]] : args[0]);
	args[1] = (IS_SET(p->op.params[1], T_REG) ? p->r[args[1]] : args[1]);
	// args[2] = (IS_SET(p->op.params[2], T_REG) ? p->r[args[2]] : args[2]);
	args[2] = get_value_from_area(vm, p->pc + ((int)(args[0] + args[1]) % IDX_MOD), 4, 0);
	process->carry = !process->r[args[2]] ? 1 : 0;
	DG("");
	return (0);
}
