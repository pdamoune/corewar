/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gtk_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:29:14 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 17:10:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		handler(int sig)
{
	DG("WHY I'M HERE ?");
	(void)sig;
	exit(0);
	//TODO remove this
}

void		init_gtk_memory(int *ac, char ***av, t_vm *vm)
{
	SET(vm->flag, GRAPHIC);
	signal(SIGABRT, handler);
	init_gtk_value(vm);
	gtk_init(ac, av);
	create_gtk(vm);
}
