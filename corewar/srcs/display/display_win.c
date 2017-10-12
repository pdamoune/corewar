/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:29:10 by wescande          #+#    #+#             */
/*   Updated: 2017/10/11 19:13:32 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		who_is_the_winner(t_vm *vm)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
		if (vm->file[i].is_used
			&& (vm->winner == -1
				|| vm->file[i].last_live >= vm->file[vm->winner].last_live))
		{
			vm->winner = i;
		}
}
// {
// 	int		i;
// 	int		id;

// 	*winner = &(vm->file[vm->winner]);
// 	return (vm->winner);
// 	*winner = NULL;
// 	id = -1;
// 	i = -1;
// 	while (++i < MAX_PLAYERS)
// 		if (vm->file[i].is_used && vm->file[i].last_live
// 			&& (!(*winner) || vm->file[i].last_live >= (*winner)->last_live))
// 		{
// 			*winner = &(vm->file[i]);
// 			id = i;
// 		}
// 	if (*winner == NULL && IS_SET(vm->flag, ZAZ))
// 	{
// 		i = -1;
// 		while (++i < MAX_PLAYERS)
// 			if (vm->file[i].is_used
// 				&& (!(*winner) || vm->file[i].last_live >= (*winner)->last_live))
// 			{
// 				*winner = &(vm->file[i]);
// 				id = i;
// 			}
// 	}
// 	return (id);
// }

int				display_win(t_vm *vm)
{
	// t_file	*winner;
	// int		id_win;
	
	
	
	//TODO RECHECK THIS
	char	*str;
	char	*strtmp;

	if (IS_SET(vm->flag, ZAZ))
	{
		str = "Contestant %d, \"%s\", has won !";
		strtmp = "Contestant %d, \"%s\", has won !";
		if (vm->winner == -1)
			who_is_the_winner(vm);
	}
	else if (vm->winner != -1)
	{
		str = "Contestant %d, \"{red}%s{gre}\", has won !";
		strtmp = "Contestant %d, \"%s\", has won !";
	}
	else
	{
		str = "There is no winner.";
		strtmp = "There is no winner.";
	}
	verbose(vm, MSG_SUCESS, str, vm->winner + 1, vm->file[vm->winner].header.prog_name);
	if (IS_SET(vm->flag, VOICE))
	{
		ft_asprintf(&str, strtmp, vm->winner + 1, vm->file[vm->winner].header.prog_name);
		text_to_speech(vm, str);
		ft_strdel(&str);
	}
	if (IS_SET(vm->flag, GRAPHIC))
		verbose(vm, MSG_STD_G, strtmp, vm->winner + 1, vm->file[vm->winner].header.prog_name);
	
	// if ((id_win = who_is_the_winner(vm, &winner)) == -1)
	// 	verbose(vm, MSG_SUCESS, "There is no winner.", NULL);
	// else
	// {
	// 	if (IS_SET(vm->flag, ZAZ))
	// 		str = "Contestant %d, \"%s\", has won !";
	// 	else
	// 		str = "Contestant %d, \"{red}%s{gre}\", has won !";
	// 	verbose(vm, MSG_SUCESS, str, id_win + 1, winner->header.prog_name);
	
	return (0);
}
