/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:49 by wescande          #+#    #+#             */
/*   Updated: 2017/08/30 00:08:19 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_cliopts	g_read_opts[] =
{
	{'d', "dump", DUMP, 0, init_dump, 1},
	{'n', "number", 0, 0, init_number, 2},
	{'g', "graphic", GRAPHIC, 0, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int		init_area(t_file *file, char *area)
{
	int		pc;
	int		prog_size;

	while (file)
	{
		if (!file->is_used)
		{
			file++;
			continue ;
		}
		pc = file->pc;
		prog_size = file->header.prog_size;
		ft_memcpy(&area[pc], file->header.prog, prog_size);
		DG("Copie des programmes (visualisateur ?)"); //TODO
		file++;
	}
	return (1);
}

int		init_pc(t_vm *vm, int players, int i)
{
	while (vm->file[i].is_used)
	{
		vm->file[i].pc = i * (MEM_SIZE / players);
		i++;
	}
	return (1);
}

int		init_vm(t_vm *vm, int ac, char **av)
{
	(void)ac;
	ft_bzero(vm, sizeof(t_vm));
	if ((cliopts_get(av, g_read_opts, vm)))
		return (ft_perror("corewar") && usage("corewar"));
	if (vm->av_data)
		while (*vm->av_data)
			if (init_file(vm, -1, *vm->av_data++))
				return (1);
	vm->cycle_to_die = CYCLE_TO_DIE;
	init_pc(vm, vm->nb_player, 0);
	init_area(vm->file, vm->area);
	return (0);
}
