/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:29:14 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 18:32:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			gtk_init_area(t_vm *vm)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		if (!vm->file[i].is_used)
			continue ;
		j = -1;
		while (++j < (int)vm->file[i].header.prog_size)
			if (init_px(vm, vm->file[i].pc + j, i))
				return (1);
		init_pc(vm, vm->file[i].pc);
	}
	return (0);
}

void		gtk_init_env(int *ac, char ***av, t_vm *vm)
{
	vm->gtk.speed = ft_pow(INIT_SPEED, 2);
	SET(vm->flag, PAUSE);
	gtk_init(ac, av);
	create_gtk(vm);
}