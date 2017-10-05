/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:29:10 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:15:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		who_is_the_winner(t_vm *vm, t_file **winner)
{
	int		i;
	int		id;

	*winner = NULL;
	id = -1;
	i = -1;
	while (++i < MAX_PLAYERS)
		if (vm->file[i].is_used && vm->file[i].last_live
			&& (!(*winner) || vm->file[i].last_live > (*winner)->last_live))
		{
			*winner = &(vm->file[i]);
			id = i;
		}
	return (id);
}

int				display_win(t_vm *vm)
{
	t_file	*winner;
	int		id_win;
	char	*str;

	if ((id_win = who_is_the_winner(vm, &winner)) == -1)
		verbose(vm, MSG_SUCESS, "There is no winner.", NULL);
	else
	{
		verbose(vm, MSG_SUCESS, "Contestant %d, \"{red}%s{gre}\", has won !",
								id_win + 1, winner->header.prog_name);
		if (IS_SET(vm->flag, VOICE))
		{
			ft_asprintf(&str, "Contestant %d, \"%s\", has won !",
								id_win + 1, winner->header.prog_name);
			text_to_speech(vm, str);
			ft_strdel(&str);
		}
		if (IS_SET(vm->flag, GRAPHIC))
			verbose(vm, MSG_STD_G, "Contestant %d, \"%s\", has won !",
								id_win + 1, winner->header.prog_name);
	}
	return (0);
}
