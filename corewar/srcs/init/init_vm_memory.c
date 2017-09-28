/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/28 17:40:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_cliopts	g_read_opts[] =
{
	{'d', "dump", DUMP, GRAPHIC, init_dump, 1},
	{'n', "number", 0, 0, init_number, 2},
	{'g', "graphic", GRAPHIC, DUMP, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int			init_vm_memory(t_vm *vm, int *ac, char ***av)
{
	ft_bzero(vm, sizeof(t_vm));
	if ((cliopts_get(*av, g_read_opts, vm)))
		return (ft_perror("corewar") && usage("corewar"));
	if (vm->av_data)
		while (*vm->av_data)
			if (init_file(vm, -1, *vm->av_data++))
				return (1);
	INIT_LIST_HEAD(&(vm->process));
	if (IS_SET(vm->flag, GRAPHIC))
		init_gtk_memory(ac, av, vm);
	return (0);
}
