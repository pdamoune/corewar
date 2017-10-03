/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/03 17:18:28 by wescande         ###   ########.fr       */
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

#include <vm.h>

int		op_st(t_vm *vm, t_process *p, unsigned int *args)
{
	int		addr;

	verbose(vm, MSG_DEBUG, "%s", __func__);
	analyze_value(vm, p, args, 1);
	if (p->op.params[1] == T_REG)
		p->r[args[1] - 1] = args[0];
	else
	{
		addr = calc_addr(p->pc + (int)args[1] % IDX_MOD);
		if (IS_SET(vm->flag, GRAPHIC))
			px_change_owner(vm, addr, REG_SIZE, p->id_player);
		set_value_in_area(vm, addr, args[0], REG_SIZE);
	}
	return (0);
}
