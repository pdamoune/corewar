/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:41:47 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 15:40:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		remove_all_process(t_vm *vm)
{
	t_process	*process;
	t_process	*tmp;

	process = (t_process *)((char*)(vm->process.next)
			- offsetof(t_process, lx));
	tmp = (t_process *)((char*)(process->lx.next)
				- offsetof(t_process, lx));
	while (&process->lx != &vm->process)
	{
		del_process(vm, process, 0);
		process = tmp;
		tmp = (t_process *)((char*)(process->lx.next)
				- offsetof(t_process, lx));
	}
}
