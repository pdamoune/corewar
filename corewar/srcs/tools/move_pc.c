/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:43:16 by wescande          #+#    #+#             */
/*   Updated: 2017/10/09 13:28:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		move_pc(t_vm *vm, int origin, int len)
{
	int		dest;

	dest = ((origin + len) % MEM_SIZE);
	if (dest < 0)
		dest += MEM_SIZE;
	verbose(vm, MSG_DEBUG, "pc move: from %d to %d", origin, dest);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		--vm->gtk.px[origin].pc;
		if (!vm->gtk.px[origin].pc)
			erase_pc(vm, origin);
		if (!vm->gtk.px[dest].pc)
			draw_pc(vm, dest);
		++vm->gtk.px[dest].pc;
	}
	return (dest);
}
