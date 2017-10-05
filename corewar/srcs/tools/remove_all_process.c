/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:41:47 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:41:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		remove_all_process(t_vm *vm)
{
	t_process	*process;
	t_process	*tmp;

	LIST_FOR_EACH_ENTRY_SAFE_0(process, tmp, &vm->process, lx);
	while (LIST_FOR_EACH_ENTRY_SAFE_1(process, tmp, &vm->process, lx))
	{
		del_process(vm, process, 0);
	}
}
