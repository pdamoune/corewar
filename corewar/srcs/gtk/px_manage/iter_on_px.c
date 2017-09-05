/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_on_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 22:21:28 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 22:28:05 by wescande         ###   ########.fr       */
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
			vm->gtk.px[i].is_new = 0;
			DG();
			calcul_px(vm, i);
		}
	}
}