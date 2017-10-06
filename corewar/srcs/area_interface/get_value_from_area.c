/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_area.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:01:09 by wescande          #+#    #+#             */
/*   Updated: 2017/10/07 00:04:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static unsigned char	get_char_at(t_vm *vm, int at)
{
	if (at < 0)
		at += MEM_SIZE;
	if (at >= MEM_SIZE)
		at %= MEM_SIZE;
	return (vm->area[at]);
}

static int		get_int_from_area(t_vm *vm, unsigned int pos,
										char size, int *pc_inc)
{
	unsigned int		ret;
	char				i;

	ret = 0;
	i = -1;
	while (++i < size)
		ret = (ret << 8) | get_char_at(vm, pos + *pc_inc + i);
	*pc_inc += size;
	return (ret);
}

unsigned int			get_process_value_from_area(t_vm *vm, t_process *p,
											unsigned int type, int *pc_inc)
{
	if (IS_SET(type, T_REG))
		return ((char)get_int_from_area(vm, p->pc, 1, pc_inc));
	if (IS_SET(type, T_IND))
		return ((short)get_int_from_area(vm, p->pc, 2, pc_inc));
	if (IS_SET(type, T_DIR) && p->op.index)
		return ((short)get_int_from_area(vm, p->pc, 2, pc_inc));
	if (IS_SET(type, T_DIR))
		return ((int)get_int_from_area(vm, p->pc, 4, pc_inc));
	return (0);
}

unsigned int			get_value_at(t_vm *vm, unsigned int pos, char size)
{
	int		tmp_inc;

	tmp_inc = 0;
	return (get_int_from_area(vm, pos, size, &tmp_inc));
}
