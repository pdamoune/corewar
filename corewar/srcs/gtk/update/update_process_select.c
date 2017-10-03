/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_process_select.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:45:01 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 19:18:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		update_process_select(t_vm *vm, unsigned int process_id)
{
	t_process		*process;

	LIST_FOR_EACH_ENTRY_0(process, &vm->process, lx);
	while (LIST_FOR_EACH_ENTRY_1(process, &vm->process, lx))
	{
		if (process_id == process->id)
		{
			vm->gtk.panel.process = process;
			update_process(vm, process, 0);
			return (TRUE);
		}
	}
	return (FALSE);
}
