/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_contestant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:53:30 by wescande          #+#    #+#             */
/*   Updated: 2017/10/06 13:51:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void			write_players(t_vm *vm, int i)
{
	if (IS_SET(vm->flag, ZAZ))
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
		i + 1, vm->file[i].header.prog_size,
		vm->file[i].header.prog_name, vm->file[i].header.comment);
	else
		ft_printf("* {yel}Player %d, {eoc}weighing %u bytes, \"{red}%s{eoc}\""
		" (\"%s\") !\n", i + 1, vm->file[i].header.prog_size,
		vm->file[i].header.prog_name, vm->file[i].header.comment);
}

static int			prepare_text(t_vm *vm, int i)
{
	char	*str;

	ft_asprintf(&str, "Player %d, %s (%s)", i + 1,
					vm->file[i].header.prog_name, vm->file[i].header.comment);
	if (text_to_speech(vm, str))
	{
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	return (0);
}

int					init_contestant(t_vm *vm)
{
	int		i;

	if (IS_SET(vm->flag, INTRO))
	{
		if (IS_SET(vm->flag, ZAZ))
			ft_printf("Introducing contestants...\n");
		else
			ft_printf("{pur}Introducing contestants...\n{eoc}");
	}
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (vm->file[i].is_used)
		{
			if (IS_SET(vm->flag, INTRO))
				write_players(vm, i);
			if (IS_SET(vm->flag, VOICE))
				if (prepare_text(vm, i))
					return (1);
		}
	}
	return (0);
}
