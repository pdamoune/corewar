/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/30 16:14:45 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	console_run(t_vm *vm)
{
	int ret;

	if (!vm)
		return (ERR_COR("WHAT THE FUCK IS NULL??"));
	ret = 0;
	DG("START");
	while (IS_UNSET(vm->flag, STOP))
	{
		display(vm);
		sleep (1);
		ret = do_one_cycle(vm);
		// display(vm);
		if (ret)
			break;
	}
	DG("END at cycle %d", vm->cycle);
	if (!ret)
		ret = display_win(vm);
	return (free_vm(vm) || ret);
}

int		main(int ac, char **av)
{
	t_vm	vm;

	if (init_vm(&vm, ac, av))
		return (1);
	if (IS_SET(vm.flag, GRAPHIC))
		return (DG("graphic not yet implemented"));//return (gtk_run(&vm));
	else
		return (console_run(&vm));
	return (0);
	// t_champions	champions;

	// if (ac < 2)
	// 	return (usage(av[0]));
	// cor_display_data();
	// ft_bzero(&champions, sizeof(t_champions));
	// cor_parser(&champions, ac, av);
	return (0);
}
