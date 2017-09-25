/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_on_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 22:21:28 by wescande          #+#    #+#             */
/*   Updated: 2017/09/25 16:52:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	iter_on_px(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (vm->gtk.px[i].is_new)
		{
			if (!(--vm->gtk.px[i].is_new))
			{
				calcul_px(vm, i);
				UNSET(vm->gtk.px[i].flag, LIVE);
			}
		}
	}
}