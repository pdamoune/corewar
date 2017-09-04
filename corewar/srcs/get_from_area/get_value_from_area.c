/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_area.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:01:09 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 21:18:07 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		get_int_from_area(t_vm *vm, t_process *p, int size, int *pc_inc)
{
	int		ret;
	int		i;

	ret = vm->area[p->pc + *pc_inc];
	i = 0;
	while (++i < size)
		ret = (ret << 8) | vm->area[p->pc + *pc_inc + i];
	*pc_inc += size;
	// TODO - 1 because pc_inc is to jump to next cmd
	// ret = vm->area[p->pc + *pc_inc - 1];// - 1 because pc_inc is to jump to next cmd
	// i = 0;//i put 0 to iter one less because first value is already get
	// while (++i < size)
	// 	ret = (ret << 8) | vm->area[p->pc + *pc_inc + i - 1];
	return (ret);
}

int				get_value_from_area(t_vm *vm, t_process *p, int type, int *pc_inc)
{
	if (type == T_REG)
		return (get_int_from_area(vm, p, 1, pc_inc));
	if (type == T_IND)
		return (get_int_from_area(vm, p, 2, pc_inc));
	if (type == T_DIR && p->op.index)
		return (get_int_from_area(vm, p, 2, pc_inc));
	if (type == T_DIR)
		return (get_int_from_area(vm, p, 4, pc_inc));
	return (0);
}
