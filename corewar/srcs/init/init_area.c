/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:24:10 by wescande          #+#    #+#             */
/*   Updated: 2017/09/19 21:02:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			init_area(t_vm *vm)
{
	int		i;
	int		j;
	int		pc;
	int		prog_size;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (!vm->file[i].is_used)
			continue ;
		pc = vm->file[i].start_position;
		prog_size = vm->file[i].header.prog_size;
		ft_memcpy(&(vm->area[pc]), vm->file->header.prog, prog_size);
		j = -1;
		while (++j < (int)vm->file[i].header.prog_size)
			if (init_px(vm, pc + j, i))
				return (1);
	}
	return (0);
}