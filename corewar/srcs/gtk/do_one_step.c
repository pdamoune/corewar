/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_one_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:50:43 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 12:11:31 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		do_one_step(t_vm *vm)
{
	if (IS_SET(vm->flag, END))
		return (1);
	else if (IS_UNSET(vm->flag, PAUSE))
		return (1);
	SET(vm->flag, STEP);
	return (0);
}
