/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gtk_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:29:14 by wescande          #+#    #+#             */
/*   Updated: 2017/09/19 20:34:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		init_gtk_memory(int *ac, char ***av, t_vm *vm)
{
	init_gtk_value(vm);
	gtk_init(ac, av);
	create_gtk(vm);
}