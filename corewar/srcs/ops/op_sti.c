/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:30 by philippe          #+#    #+#             */
/*   Updated: 2017/10/03 17:18:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_sti(t_vm *vm, t_process *p, unsigned int *args)
{
	int		addr;

	verbose(vm, MSG_DEBUG, "%s", __func__);
	analyze_value(vm, p, args, 3);
	addr = calc_addr(p->pc + ((int)(args[1] + args[2]) % IDX_MOD));
	if (IS_SET(vm->flag, GRAPHIC))
		px_change_owner(vm, addr, REG_SIZE, p->id_player);
	set_value_in_area(vm, addr, args[0], REG_SIZE);
	return (0);
}
