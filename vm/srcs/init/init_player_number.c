/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 01:42:08 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 12:05:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		exit_init(char **tab, char *msg)
{
	ft_tabdel(&tab);
	ERR_MSG("corewar", msg);
	return (1);
}

int		init_player_number(char *opt_arg, t_vm *vm, int n_args)
{
	char	**args;
	int		player_number;
	int		ret;

	if (!opt_arg || !vm)
		return (1);
	if (!(args = ft_strsplit(opt_arg, ',')))
		return (1);
	if (ft_tablen(args) != n_args)
		return(exit_init(args, "option need two arguments format as 'n,name'"));
	if (!ft_strisnumeral(args[0]))
		return(exit_init(args, "argument must be numeral value"));
	player_number = ft_atoi(args[0]);
	if (player_number < 1 || player_number > 4)
		return(exit_init(args, "argument must be 1 ≤ n ≤ 4"));
	ret = init_player(player_number, args[1]);
	ft_tabdel(&args);
	return (ret);
}
