/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 20:02:45 by wescande         ###   ########.fr       */
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
	int		i;
	int		pc;
	int		prog_size;

	i = -1;
	while (++i < 4)
	{
		if (!file[i].is_used)
			continue ;
		pc = file[i].process->pc;
		prog_size = file->header.prog_size;
		ft_memcpy(&area[pc], file->header.prog, prog_size);
		
		DG("Copie des programmes (visualisateur ?)"); //TODO
	}
	return (1);
}

t_process	*init_process(t_process **process, int id_player, int pc)
{
	t_process	*tmp;
	t_process	*vm_proc;

	vm_proc = *process;
	while (vm_proc && vm_proc->next)
		vm_proc = vm_proc->next;
	if (!(tmp = ft_memalloc(sizeof(t_process))))
		DG("Probleme malloc");
	tmp->id_player = id_player;
	tmp->pc = pc;
	if (!*process)
		*process = tmp;
	else
		(vm_proc)->next = tmp;
	return (tmp);
}

int		init_process_players(t_vm *vm, t_file *file, int players, int pc)
{
	int	id_player;
	int i;

	id_player = 0;
	i = 0;
	while (i < 4)
	{
		if (file[i].is_used)
		{
			pc = id_player * MEM_SIZE / players;
			file[i].id_player = ++id_player;
			file[i].process = init_process(&vm->process, id_player, pc);
		}
		i++;
	}
	return (1);
}

void	init_gtk(int *ac, char ***av, t_vm *vm)
{
	vm->gtk.speed = ft_pow(INIT_SPEED, 2);
	SET(vm->flag, PAUSE);
	gtk_init(ac, av);
	create_gtk(vm);
}

int		init_vm(t_vm *vm, int *ac, char ***av)
{
	ft_bzero(vm, sizeof(t_vm));
	if ((cliopts_get(*av, g_read_opts, vm)))
		return (ft_perror("corewar") && usage("corewar"));
	if (vm->av_data)
		while (*vm->av_data)
			if (init_file(vm, -1, *vm->av_data++))
				return (1);
	vm->cycle_to_die = CYCLE_TO_DIE;
	init_process_players(vm, vm->file, vm->nb_player, 0);
	//TODO check if no process , so quit with error
	if (IS_SET(vm->flag, GRAPHIC))
		init_gtk(ac, av, vm);
	init_area(vm->file, vm->area);
	if (IS_UNSET(vm->flag, GRAPHIC))
	display(vm);
	return (0);
}
