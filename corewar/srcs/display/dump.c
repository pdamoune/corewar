/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:42:19 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 12:17:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		dump(t_vm *vm)
{
	int		i;

	SET(vm->flag, END | PAUSE);
	UNSET(vm->flag, DUMP);
	//TODO what if we can't reach the dump cycle
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i)
				ft_printf("\n0x%04x :", i);
			else
				ft_printf("0x%04x :", i);
		}
		ft_printf(" %02hhx", vm->area[i]);
	}
	ft_putchar('\n');
	return (0);
}
