/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_in_area.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:23:03 by wescande          #+#    #+#             */
/*   Updated: 2017/09/25 17:15:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		set_value_in_area(t_vm *vm, int at, unsigned int value, unsigned int size)
{
	if (at < 0)
		at = MEM_SIZE + at;
	while (size--)
	{
		vm->area[at % MEM_SIZE] = (char)((value >> (8 * size)) & 0xff);
		DG();
		if (IS_SET(vm->flag, GRAPHIC))
		{
			vm->gtk.px[at].is_new = CYCLE_CHANGED;
			draw_px(vm, at);
		}
		++at;
	}
	return (0);
}