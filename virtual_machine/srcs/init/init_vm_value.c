/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:26:26 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:27:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			init_vm_value(t_vm *vm)
{
	int		i;

	ft_bzero(vm->area, MEM_SIZE);
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_check = 0;
	vm->check_count = 0;
	vm->cycle = 0;
	vm->winner = -1;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		vm->file[i].live = 0;
		vm->file[i].last_live = 0;
	}
	if (IS_SET(vm->flag, GRAPHIC))
		init_gtk_value(vm);
	if (init_process_list(vm))
		return (1);
	if (init_area(vm))
		return (1);
	if (init_contestant(vm))
		return (verbose(vm, MSG_ERROR, "Failed to present contestant", NULL));
	return (0);
}
