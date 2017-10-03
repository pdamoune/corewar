/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:51 by philippe          #+#    #+#             */
/*   Updated: 2017/10/03 17:19:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(t_vm *vm, t_process *p, unsigned int *args)
{
	verbose(vm, MSG_DEBUG, "%s", __func__);
	if (p->carry)
		p->pc = move_pc(vm, p->pc, ((int)args[0]) % IDX_MOD - 3);
	return (0);
}
