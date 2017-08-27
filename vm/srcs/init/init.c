/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:49 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 12:02:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <stdio.h>
t_cliopts	g_read_opts[] =
{
	{'d', "dump", DUMP, 0, init_dump, 1},
	{'n', "number", 0, 0, init_player_number, 2},
	{'g', "graphic", GRAPHIC, 0, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int		init_vm(t_vm *vm, int ac, char **av)
{
	(void)ac;
	ft_bzero(vm, sizeof(t_vm));
	if ((cliopts_get(av, g_read_opts, vm)))
		return (ft_perror("corewar") && usage("corewar"));
	return (0);
}