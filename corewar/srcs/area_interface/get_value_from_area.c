/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_area.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:01:09 by wescande          #+#    #+#             */
/*   Updated: 2017/09/12 14:48:43 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		get_int_from_area(t_vm *vm, t_process *p, int size, int *pc_inc)
{
	unsigned int		ret;
	int					i;

	ret = 0;
	i = -1;
	while (++i < size)
		ret = (ret << 8) | vm->area[p->pc + *pc_inc + i];
	*pc_inc += size;
	return (ret);
}

int				get_value_from_area(t_vm *vm, t_process *p, unsigned int type, int *pc_inc)
{
	if (IS_SET(type, T_REG))
		return (get_int_from_area(vm, p, 1, pc_inc));
	if (IS_SET(type, T_IND))
		return (get_int_from_area(vm, p, 2, pc_inc));
	if (IS_SET(type, T_DIR) && p->op.index)
		return (get_int_from_area(vm, p, 2, pc_inc));
	if (IS_SET(type, T_DIR))
		return (get_int_from_area(vm, p, 4, pc_inc));
	return (0);
}
