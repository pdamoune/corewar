/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:09 by philippe          #+#    #+#             */
/*   Updated: 2017/09/25 17:39:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_aff(t_vm *vm, t_process *process, unsigned int *args)
{
	(void)vm;
	//TODO aff in graphical mode ?
	ft_putchar(process->r[args[0] - 1] % 256);
	return (0);
}
