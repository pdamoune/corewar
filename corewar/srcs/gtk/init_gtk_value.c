/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gtk_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:28:15 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 12:56:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		init_gtk_value(t_vm *vm)
{
	ft_bzero(vm->gtk.px, sizeof(t_px) * MEM_SIZE);
	vm->gtk.speed = ft_pow(INIT_SPEED, 2);
	vm->gtk.god_players = -1;
	SET(vm->flag, PAUSE);
	SET(vm->flag, NEVER_START);
}
