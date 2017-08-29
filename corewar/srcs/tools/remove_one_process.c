/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_one_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:09:00 by wescande          #+#    #+#             */
/*   Updated: 2017/08/28 01:15:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		remove_one_process(t_vm *vm, t_process *process)
{
	t_process *cur;
	t_process *tmp;

	cur = vm->process;
	if (vm->process == process)
	{
		vm->process = process->next;
		process_del(process);
		return ;
	}
	while (cur)
	{
		tmp = cur->next;
		if (tmp == process)
		{
			cur->next = tmp->next;
			process_del(process);
		}
		cur = cur->next;
	}
}