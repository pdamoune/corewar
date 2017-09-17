/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:29:14 by wescande          #+#    #+#             */
/*   Updated: 2017/09/18 00:23:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		gtk_init_env(int *ac, char ***av, t_vm *vm)
{
	vm->gtk.speed = ft_pow(INIT_SPEED, 2);
	vm->gtk.god_players = -1;
	SET(vm->flag, PAUSE);
	gtk_init(ac, av);
	create_gtk(vm);
}