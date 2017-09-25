/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:58 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 16:47:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lld(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)&vm;(void)&process;(void)&args;
	DG("\nargs 0 = %d\n", args[0]);
	DG("\nargs 1 = %d\n", args[1]);
	DG("\nargs 2 = %d\n", args[2]);
	DG("");
	process->r[args[1] - 1] = get_value_from_area(vm, process, process->pc + (args[0] % IDX_MOD), 0);
	process->carry = !args[0] ? 1 : 0;
	DG("");
	return (0);
}
