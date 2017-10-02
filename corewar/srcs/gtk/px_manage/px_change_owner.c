/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_change_owner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:20:16 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 16:23:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	px_change_owner(t_vm *vm, unsigned int at, int size, short owner)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		vm->gtk.px[at + i].player = owner;
	}
}
