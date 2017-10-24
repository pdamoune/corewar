/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:30:35 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 15:40:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		check_live(t_vm *vm)
{
	t_process *process;
	t_process *tmp;

	process = (t_process *)((char*)(vm->process.next)
			- offsetof(t_process, lx));
	tmp = (t_process *)((char*)(process->lx.next)
				- offsetof(t_process, lx));
	while (&process->lx != &vm->process)
	{
		if (process->last_live <= vm->cycle - vm->cycle_to_die)
			del_process(vm, process, 1);
		process = tmp;
		tmp = (t_process *)((char*)(process->lx.next)
				- offsetof(t_process, lx));
	}
}
