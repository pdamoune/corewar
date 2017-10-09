/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:12:30 by philippe          #+#    #+#             */
/*   Updated: 2017/10/09 16:37:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_sti(t_vm *vm, t_process *p, unsigned int *args)
{
	unsigned int		val[MAX_ARGS_NUMBER];
	unsigned int		addr;

	ft_memcpy(val, args, sizeof(unsigned int) * 3);
	analyze_long_value(vm, p, val, 3);
	addr = p->pc + ((int)(val[1] + val[2]) % IDX_MOD);
	if (IS_SET(vm->flag, OPERATION))
	{
		verbose(vm, MSG_STD,
		"P %4d | sti r%d %d %d\n"
		"       | -> store to %d + %d = %d (with pc and mod %d)",
		p->id, args[0], val[1], val[2],
		val[1], val[2], val[1] + val[2], addr);
	}
	addr = calc_addr(addr);
	if (IS_SET(vm->flag, GRAPHIC))
		px_change_owner(vm, addr, REG_SIZE, p->id_player);
	set_value_in_area(vm, addr, val[0], REG_SIZE);
	return (0);
}
