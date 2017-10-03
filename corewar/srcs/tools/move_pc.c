/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:43:16 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 16:59:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		move_pc(t_vm *vm, int origin, int len)
{
	int		dest;

	verbose(vm, MSG_DEBUG, "pc move: from %d to %d", origin, origin + len);
	dest = ((origin + len) % MEM_SIZE);
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