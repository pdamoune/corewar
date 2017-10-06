/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:09 by philippe          #+#    #+#             */
/*   Updated: 2017/10/07 01:01:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_aff(t_vm *vm, t_process *p, unsigned int *args)
{
	//TODO log as zaz
	DG("TO BE IMPLEMENTED");
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD, "HEHO", NULL);
	unsigned char	c;

	verbose(vm, MSG_DEBUG, "%s", __func__);
	c = p->r[args[0] - 1] % 256;
	if (IS_UNSET(vm->flag, QUIET))
	{
		if (IS_SET(vm->flag, ZAZ))
			ft_printf("%c", c);
		else
			ft_printf("{PUR}{gre}%c{eoc}", c);
	}
	return (0);
}
