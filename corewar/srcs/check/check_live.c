/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:30:35 by wescande          #+#    #+#             */
/*   Updated: 2017/08/29 22:56:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		check_live(t_vm *vm)
{
	t_process *process;

	process = vm->process;
	while (process)
	{
		if (process->last_live <= vm->last_check)
			remove_one_process(vm, process);//TODO check return func to avance ptr
		else
			process = process->next;
	}
	(void)vm;
	DG("not yet implemented");
}