/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:09 by philippe          #+#    #+#             */
/*   Updated: 2017/09/26 19:36:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_aff(t_vm *vm, t_process *p, unsigned int *args)
{
	(void)vm;
	//TODO aff in graphical mode ?
	ft_putchar(p->r[args[0] - 1] % 256);
	return (0);
}
