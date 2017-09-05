/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:18 by philippe          #+#    #+#             */
/*   Updated: 2017/09/05 22:12:18 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_and(t_vm *vm, t_process *process, t_op op, int *args)
{
	(void)&op;(void)&vm;(void)&process;(void)&args;
	process->r[args[2]] = args[0] & args[1];
	process->carry = process->r[args[2]] ? 1 : 0; // TODO not sure
	DG("");
	return (0);
}
