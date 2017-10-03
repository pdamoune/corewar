/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 01:42:08 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 17:13:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_number(char **opt_arg, t_vm *vm, int n_args)
{
	char	**args;
	int		player_number;

	if (!opt_arg || !vm)
		return (1);
	args = opt_arg;
	if (ft_tablen(args) < n_args)
		return(verbose(vm, MSG_ERROR, "option needs more arguments", NULL));
	if (!ft_strisnumeral(args[0]))
		return(verbose(vm, MSG_ERROR, "argument must be numeral value", NULL));
	player_number = ft_atoi(args[0]);
	if (player_number < 1 || player_number > MAX_PLAYERS)
		return(verbose(vm, MSG_ERROR,
				"argument must be 1 ≤ n ≤ %d", MAX_PLAYERS));
	return (init_file(vm, player_number - 1, args[1]));
}
