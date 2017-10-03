/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:06:05 by wescande          #+#    #+#             */
/*   Updated: 2017/09/17 11:27:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		remove_all_process(t_vm *vm)
{
	t_process *process;
	t_process *tmp;

	LIST_FOR_EACH_ENTRY_SAFE(process, tmp, &vm->process, lx)
	{
		del_process(vm, process, 0);
	}
}