/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:29:10 by wescande          #+#    #+#             */
/*   Updated: 2017/09/28 17:46:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int	who_is_the_winner(t_vm *vm, t_file **winner)
{
	// t_file	*winner;
	int		i;
	int		id;

	*winner = NULL;
	id = -1;
	i = -1;
	while (++i < MAX_PLAYERS)
		if (vm->file[i].is_used && vm->file[i].last_live && (!(*winner) || vm->file[i].last_live > (*winner)->last_live))
		{
			*winner = &(vm->file[i]);
			id = i;
		}
	return (id);
}

int		display_win(t_vm *vm)
{
	t_file	*winner;
	int		id_win;

	//TODO check if need to dump & has dump or not. act in consequences
	if ((id_win = who_is_the_winner(vm, &winner)) == -1)
		ft_printf("Nobody win the game.\n");
	else
		ft_printf("Congrats to \"%s\" (player %d).\n", winner->header.prog_name, id_win + 1);
	return (0);
}
