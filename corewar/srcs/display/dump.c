/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:42:19 by wescande          #+#    #+#             */
/*   Updated: 2017/10/06 12:40:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		dump(t_vm *vm)
{
	int		i;

	if (IS_UNSET(vm->flag, PAUSE))
	{
		if (IS_SET(vm->flag, GRAPHIC))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause),
										IS_SET(vm->flag, PAUSE));
		else
			SET(vm->flag, PAUSE);
	}
	UNSET(vm->flag, DUMP);
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i)
				ft_printf("\n0x%04x : ", i);
			else
				ft_printf("0x%04x : ", i);
		}
		ft_printf("%02hhx ", vm->area[i]);
	}
	ft_putchar('\n');
	return (0);
}
