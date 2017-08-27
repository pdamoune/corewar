/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/27 17:15:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 	cor_display_data(void)
{
	ft_printf("\n{red}MEM_SIZE           = %10d | %#x\n", MEM_SIZE, MEM_SIZE);
	ft_printf("CHAMP_MAX_SIZE     = %10d | %#x\n", CHAMP_MAX_SIZE, CHAMP_MAX_SIZE);
	ft_printf("PROG_NAME_LENGTH   = %10d | %#x\n", PROG_NAME_LENGTH, PROG_NAME_LENGTH);
	ft_printf("COMMENT_LENGTH     = %10d | %#x\n", COMMENT_LENGTH, COMMENT_LENGTH);
	ft_printf("COREWAR_EXEC_MAGIC = %10d | %#x\n\n{eoc}", COREWAR_EXEC_MAGIC, COREWAR_EXEC_MAGIC);
}

static int	console_run(t_vm *vm)
{
	int ret;

	if (!vm)
		return (ERR_COR("WHAT THE FUCK IS NULL??"));
	ret = 0;
	DG("START");
	while (IS_UNSET(vm->flag, STOP))
	{
		ret = do_one_cycle(vm);
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
