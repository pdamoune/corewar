/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:06:05 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 19:08:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		remove_process(t_vm *vm)
{
	t_process *process;
	t_process *tmp;

	process = vm->process;
	while (process)
	{
		tmp = process->next;
		free(process);
		process = tmp;
	}
	vm->process = NULL;
}