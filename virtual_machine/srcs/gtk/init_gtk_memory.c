/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gtk_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:29:14 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 11:34:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		init_gtk_memory(int *ac, char ***av, t_vm *vm)
{
	SET(vm->flag, GRAPHIC);
	init_gtk_value(vm);
	gtk_init(ac, av);
	create_gtk(vm);
}
