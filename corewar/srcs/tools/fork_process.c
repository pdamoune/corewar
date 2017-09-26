/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:43:23 by wescande          #+#    #+#             */
/*   Updated: 2017/09/26 16:51:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		fork_process(t_vm *vm, t_process *p, unsigned int pc)
{
	t_process		*new_process;

	if (!(new_process = ft_memalloc(sizeof(t_process))))
		return (ERR_COR("malloc failed"));
	ft_memcpy(new_process, p, sizeof(t_process));
	new_process->pc = pc;
	new_process->nb_cycle_before_exec = 0;
	add_process(vm, new_process);
	return (0);
}