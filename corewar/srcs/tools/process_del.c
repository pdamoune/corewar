/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:11:06 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 16:24:18 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		process_del(t_vm *vm, t_process *process)
{
	(void)vm;
	//TODO play music ?
	list_del(&process->lx);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		--vm->gtk.px[process->pc].pc;
		if (!vm->gtk.px[process->pc].pc)
			erase_pc(vm, process->pc);
	}
	free(process);
}