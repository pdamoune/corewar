/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:43:16 by wescande          #+#    #+#             */
/*   Updated: 2017/10/12 15:36:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		move_pc(t_vm *vm, int origin, int len, int display)
{
	int		dest;
	int		i;
	char	*str;
	char	*hextmp;
	char	*strtmp;

	dest = ((origin + len) % MEM_SIZE);
	if (display && IS_SET(vm->flag, ZAZ))
	{
		str = ft_strdup("");
		i = -1;
		while (++i < len)
		{
			ft_asprintf(&hextmp, "%02hhx", vm->area[(origin + i) % MEM_SIZE]);
			ft_asprintf(&strtmp, "%s%s ", str, hextmp);
			ft_strdel(&hextmp);
			ft_strdel(&str);
			str = strtmp;
		}
		verbose(vm, MSG_INFO, "ADV %d (0x%04x -> 0x%04x) %s", len, origin, origin + len, str);
		ft_strdel(&str);
	}
	// ADV 8 (0x0807 -> 0x080f) 06 64 01 00 00 00 01 01
	if (dest < 0)
		dest += MEM_SIZE;
	// verbose(vm, MSG_DEBUG, "pc move: from %d to %d", origin, dest);
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
