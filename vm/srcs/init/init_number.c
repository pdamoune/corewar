/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 01:42:08 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 14:02:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_number(char **opt_arg, t_vm *vm, int n_args)
{
	char	**args;
	int		player_number;
	int		ret;

	if (!opt_arg || !vm)
		return (1);
	args = opt_arg;
	if (ft_tablen(args) < n_args)
		return(ERR_COR("option needs more arguments"));
	if (!ft_strisnumeral(args[0]))
		return(ERR_COR("argument must be numeral value"));
	player_number = ft_atoi(args[0]);
	if (player_number < 1 || player_number > 4)
		return(ERR_COR("argument must be 1 ≤ n ≤ 4"));
	ret = init_file(vm, player_number - 1, args[1]);
	return (ret);
}
