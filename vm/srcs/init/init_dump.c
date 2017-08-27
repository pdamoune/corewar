/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:15:46 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 11:55:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_dump(char *opt_arg, t_vm *vm, int n_args)
{
	(void)n_args;
	if (!opt_arg || !vm)
		return (1);
	if (!ft_strisnumeral(opt_arg))
	{
		ERR_MSG("corewar", "dump option require numeral value");
		return (1);
	}
	vm->cycle_to_dump = ft_atoi(opt_arg);
	if (vm->cycle_to_dump < 0)
	{
		ERR_MSG("corewar", "dump option require a positive value");
		return (1);
	}
	return (0);
}