/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:30:20 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 16:26:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		do_one_cycle(t_vm *vm)
{




	if (IS_SET(vm->flag, DUMP) && vm->cycle == vm->cycle_to_dump)
		dump(vm);
	check_cycle(vm);
	++vm->cycle;
	return (0);
}