/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:56 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 17:40:04 by pdamoune         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_champions	champions;

	if (ac < 2)
		return (usage(av[0]));
	cor_display_data();
	ft_bzero(&champions, sizeof(t_champions));
	cor_parser(&champions, ac, av);
	return (0);
}
