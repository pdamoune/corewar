/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:30:35 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 13:56:05 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		check_live(t_vm *vm)
{
	t_process *process;
	t_process *tmp;

	LIST_FOR_EACH_ENTRY_SAFE(process, tmp, &vm->process, lx)
	{
		if (process->last_live <= vm->last_check)
			process_del(vm, process);
	}
}