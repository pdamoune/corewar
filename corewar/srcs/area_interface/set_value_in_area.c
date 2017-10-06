/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_in_area.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:23:03 by wescande          #+#    #+#             */
/*   Updated: 2017/10/07 01:04:51 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		set_value_in_area(t_vm *vm, int at, unsigned int value,
							unsigned int size)
{
	if (at < 0)
		at = MEM_SIZE + at;
	while (size--)
	{
		//TODO check if it's ok for memory
		if (at >= MEM_SIZE)
			at %= MEM_SIZE;
		vm->area[at] = (unsigned char)((value >> (8 * size)) & 0xff);
		if (IS_SET(vm->flag, GRAPHIC))
		{
			vm->gtk.px[at].is_new = CYCLE_CHANGED;
			draw_px(vm, at);
		}
		++at;
	}
	return (0);
}
