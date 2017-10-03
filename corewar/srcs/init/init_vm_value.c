/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:26:26 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 17:13:42 by wescande         ###   ########.fr       */
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
	if (list_empty(&vm->process))
		return (verbose(vm, MSG_ERROR ,
				"At least one player is needed.", NULL));
	if (init_area(vm))
		return (1);
	// if (IS_UNSET(vm->flag, GRAPHIC))
		// display(vm);
	return (0);
}