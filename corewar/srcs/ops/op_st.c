/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/29 19:26:32 by pdamoune         ###   ########.fr       */
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

int		op_st(t_op param)
{
	(void)&param;
	DG("");
	return (0);
}
