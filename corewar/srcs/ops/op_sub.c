/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:37 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 16:48:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_sub(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)&vm;(void)&process;(void)&args;
	process->r[args[2] - 1] = process->r[args[0] - 1] - process->r[args[1] - 1];
	process->carry = !process->r[args[2] - 1] ? 1 : 0;
	DG("");
	return (0);
}
