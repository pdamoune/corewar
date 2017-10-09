/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:09 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 15:37:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_aff(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned char	c;

	c = p->r[args[0] - 1] % 256;
	if (IS_UNSET(vm->flag, QUIET))
	{
		if (IS_SET(vm->flag, ZAZ))
			ft_printf("Aff: %c\n", c);
		else
			ft_printf("{pur}Aff: {PUR}{gre}%c{eoc}\n", c);
	}
	return (0);
}
