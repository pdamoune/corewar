/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/24 10:57:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_st(t_vm *vm, t_process *p, unsigned int *args, int *pc_inc)
{
	unsigned int		val[MAX_ARGS_NUMBER];
	unsigned int		addr;

	(void)pc_inc;
	ft_memcpy(val, args, sizeof(unsigned int) * 2);
	analyze_value(vm, p, val, 2);
	if (IS_SET(vm->flag, OPERATION))
		verbose(vm, MSG_STD,
		"P %4d | st r%d %d", p->id, args[0], args[1]);
	if (p->op.params[1] == T_REG)
		p->r[args[1] - 1] = val[0];
	else
	{
		addr = calc_addr(p->pc + (int)args[1] % IDX_MOD);
		if (IS_SET(vm->flag, GRAPHIC))
			px_change_owner(vm, addr, REG_SIZE, p->id_player);
		set_value_in_area(vm, addr, val[0], REG_SIZE);
	}
	return (0);
}
