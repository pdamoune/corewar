/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:45:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/09/26 19:36:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Instruction Load direct
** ld - opcode 0x02
**
**		op	?	valeur		registre
** ex : 02	90	fffffffb	05

	le 90 ne semble pas bouger, que le parametre soit direct ou ind.

**
** Take a random argument and a registry.
** Load the value of the first argument in the registry.
** It will change the carry.
*/

#include "vm.h"

int		op_ld(t_vm *vm, t_process *p, unsigned int *args)
{
	analyze_value(vm, p, args, 1);
	// DG("\nargs 0 = %d\n", args[0]);
	// DG("\nargs 1 = %d\n", args[1]);
	// DG("\nargs 2 = %d\n", args[2]);
	// DG("");
	p->r[args[1] - 1] = args[0];
	p->carry = !p->r[args[1] - 1];
	return (0);
}
