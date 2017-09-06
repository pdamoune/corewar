/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/06 14:02:37 by wescande         ###   ########.fr       */
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
	DG("");
	return (0);
}
