/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:15:46 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 13:55:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_dump(char **opt_arg, t_vm *vm, int n_args)
{
	(void)n_args;
	if (!opt_arg || !vm)
		return (1);
		
	if (!ft_strisnumeral(*opt_arg))
		return (ERR_COR("dump option require numeral value"));
	vm->cycle_to_dump = ft_atoi(*opt_arg);
	if (vm->cycle_to_dump < 0)
		return (ERR_COR("dump option require positive value"));
	return (0);
}