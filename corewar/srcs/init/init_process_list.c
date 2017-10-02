/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:20:25 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 15:49:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_process_list(t_vm *vm)
{
	int			id_player;
	int			i;
	t_process	*new_process;

	id_player = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		if (vm->file[i].is_used)
		{
			vm->file[i].start_position = id_player++ * MEM_SIZE / vm->nb_player;
			if (!(new_process = ft_memalloc(sizeof(t_process))))
				return (ERR_COR("malloc failed"));
			new_process->pc = vm->file[i].start_position;
			new_process->id_player = i;
			new_process->r[0] = -(i + 1);// or should we use -id_player ?
			// TODO
			/*
			** ajout de l id player dans le registre r1.
			** Verifier lorsque REG_SIZE est inferieur a 4
			** si cela fonctionne aussi
			*/
			add_process(vm, new_process);
		}
	if (IS_SET(vm->flag, GRAPHIC))
		gtk_combo_box_set_active(GTK_COMBO_BOX(vm->gtk.panel.process_box), 0);
	return (0);
}
