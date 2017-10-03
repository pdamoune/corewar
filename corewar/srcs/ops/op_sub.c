/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:37 by philippe          #+#    #+#             */
/*   Updated: 2017/10/03 17:18:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_sub(t_vm *vm, t_process *p, unsigned int *args)
{
	verbose(vm, MSG_DEBUG, "%s", __func__);
	p->r[args[2] - 1] = p->r[args[0] - 1] - p->r[args[1] - 1];
	p->carry = !p->r[args[2] - 1];
	return (0);
}
