/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:45:35 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/11 17:24:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ld(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int		val[MAX_ARGS_NUMBER];

	ft_memcpy(val, args, sizeof(unsigned int) * 1);
	analyze_value(vm, p, val, 1);
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | ld %d r%d", p->id, val[0], args[1]);
	p->r[args[1] - 1] = val[0];
	p->carry = !p->r[args[1] - 1];
	return (0);
}
