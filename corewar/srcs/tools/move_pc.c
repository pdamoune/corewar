/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:43:16 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 11:29:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		verbose_pc(t_vm *vm, int origin, int len)
{
	int		i;
	char	*str;
	char	*strtmp;

	str = ft_strdup("");
	i = -1;
	while (++i < len)
	{
		ft_asprintf(&strtmp, "%s%02hhx ", str,
			vm->area[(origin + i) % MEM_SIZE]);
		ft_strdel(&str);
		str = strtmp;
	}
	verbose(vm, MSG_INFO, "ADV %d (0x%04x -> 0x%04x) %s",
						len, origin, origin + len, str);
	ft_strdel(&str);
}

int				move_pc(t_vm *vm, int origin, int len, int display)
{
	int		dest;

	if (!len)
		return (origin);
	dest = ((origin + len) % MEM_SIZE);
	if (display && IS_SET(vm->flag, ZAZ))
		verbose_pc(vm, origin, len);
	if (dest < 0)
		dest += MEM_SIZE;
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
