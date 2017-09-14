/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/14 19:32:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_cliopts	g_read_opts[] =
{
	{'d', "dump", DUMP, 0, init_dump, 1},
	{'n', "number", 0, 0, init_number, 2},
	{'g', "graphic", GRAPHIC, 0, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

static int	init_area(t_vm *vm)
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
		pc = vm->file[i].pc;
		prog_size = vm->file[i].header.prog_size;
		ft_memcpy(&(vm->area[pc]), vm->file->header.prog, prog_size);
		j = -1;
		while (++j < (int)vm->file[i].header.prog_size)
			if (init_px(vm, vm->file[i].pc + j, i))
				return (1);
	}
	return (0);
}

static int	init_process_players(t_vm *vm, t_file *file, int players)
{
	int			id_player;
	int			i;
	t_process	*new_process;

	id_player = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		if (file[i].is_used)
		{
			file[i].pc = id_player++ * MEM_SIZE / players;
			if (!(new_process = ft_memalloc(sizeof(t_process))))
				return (ERR_COR("malloc failed"));
			new_process->pc = file[i].pc;
			new_process->name = file[i].header.prog_name;
			new_process->id_player = -i;// or should we use -id_player ? i guess not because if we set the number by cli, we have to pass somes
			add_process(vm, new_process);
			// list_add(&(new_process->lx), &(vm->process));
		}
	return (0);
}

int			init_vm(t_vm *vm, int *ac, char ***av)
{
	ft_bzero(vm, sizeof(t_vm));
	if ((cliopts_get(*av, g_read_opts, vm)))
		return (ft_perror("corewar") && usage("corewar"));
	if (vm->av_data)
		while (*vm->av_data)
			if (init_file(vm, -1, *vm->av_data++))
				return (1);
	vm->cycle_to_die = CYCLE_TO_DIE;
	INIT_LIST_HEAD(&(vm->process));
	if (IS_SET(vm->flag, GRAPHIC))
		gtk_init_env(ac, av, vm);
	if (init_process_players(vm, vm->file, vm->nb_player))
		return (1);
	if (list_empty(&vm->process))
		return (ERR_COR("at least one player is needed."));
	if (init_area(vm))
		return (1);
	if (IS_UNSET(vm->flag, GRAPHIC))
		display(vm);
	return (0);
}
