/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:18 by philippe          #+#    #+#             */
/*   Updated: 2017/09/26 19:36:24 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_and(t_vm *vm, t_process *p, unsigned int *args)
{
	analyze_value(vm, p, args, 2);
	p->r[args[2] - 1] = args[0] & args[1];
	p->carry = !p->r[args[2] - 1];
	// DG("%32.32b", args[0]);
	// DG("%32.32b", args[1]);
	// DG("%32.32b in %d", process->r[args[2] - 1], args[2] - 1);
	// DG("\nargs 0 = %d\n", args[0]);
	// DG("\nargs 1 = %d\n", args[1]);
	// DG("\nargs 2 = %d\n", args[2]);
	// DG("\ncarry = %d\n", process->carry);
	return (0);
}
