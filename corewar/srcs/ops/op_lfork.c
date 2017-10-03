/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:50 by philippe          #+#    #+#             */
/*   Updated: 2017/10/03 17:17:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lfork(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int	new_pc;

	verbose(vm, MSG_DEBUG, "%s", __func__);
	new_pc = calc_addr(p->pc + args[0]);
	return (fork_process(vm, p, new_pc));
}
