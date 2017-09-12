/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/12 16:18:38 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Instruction st
** opcode 0x03
**
**
**
** Take a registry and a registry or an indirect
** and store the value of the registry toward a second argument.
** For example, st r1, 42
** store the value of r1 at the address (PC + (42 % IDX_MOD))
*/

#include "vm.h"

int		op_st(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)&vm;(void)&process;(void)&args;
	DG("\nargs 0 = %d\n", args[0]);
	DG("\nargs 1 = %d\n", args[1]);
	DG("\nargs 2 = %d\n", args[2]);

	args[1] = (IS_SET(process->op.params[1], T_REG) ? process->r[args[1]] : args[1]);
	set_value_in_area(vm, process->pc + ((int)args[1] % IDX_MOD), args[0], 4);
	process->carry = !args[0] ? 1 : 0;  // Pas sur
	DG("");
	return (0);
}
