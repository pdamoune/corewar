/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_one_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:50:43 by wescande          #+#    #+#             */
/*   Updated: 2017/09/20 19:01:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		do_one_step(t_vm *vm)
{
	DG("enter");
	if (IS_SET(vm->flag, END))
	{
		DG("The game is over");
		return (1);
	}
	else if (IS_UNSET(vm->flag, PAUSE))
	{
		DG("The game is not in pause mode");
		return (1);
	}
	else
	{
		DG("will do one step");
		SET(vm->flag, STEP);
		return (0);
	}
}