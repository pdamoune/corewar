/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:01 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 17:39:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_add(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)vm;
	process->r[args[2] - 1] = process->r[args[0] - 1] + process->r[args[1] - 1];
	process->carry = !process->r[args[2] - 1];
	return (0);
}
