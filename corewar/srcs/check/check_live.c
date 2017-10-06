/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:30:35 by wescande          #+#    #+#             */
/*   Updated: 2017/10/07 00:52:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		check_live(t_vm *vm)
{
	t_process *process;
	t_process *tmp;

	LIST_FOR_EACH_ENTRY_SAFE_0(process, tmp, &vm->process, lx);
	while (LIST_FOR_EACH_ENTRY_SAFE_1(process, tmp, &vm->process, lx))
	{
		if (process->last_live <= vm->cycle - vm->cycle_to_die)
			del_process(vm, process, 1);
	}
}
