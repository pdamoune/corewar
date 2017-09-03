/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:06:05 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 13:20:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		remove_process(t_vm *vm)
{
	t_process *process;
	t_process *tmp;

	LIST_FOR_EACH_ENTRY_SAFE(process, tmp, &vm->process, lx)
	{
		process_del(vm, process);
	}
}