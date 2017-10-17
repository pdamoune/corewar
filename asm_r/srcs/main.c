/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:26:48 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/17 17:08:53 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

void 	display(t_file *file)
{
	ft_printf("\nfilename     = %s\n", file->filename);
	ft_printf("magic        = %x\n", file->header.magic);
	ft_printf("prog_name    = %.5s [...] len = %d\n", file->header.prog_name, ft_strlen(file->header.prog_name));
	ft_printf("prog_size    = %d\n", file->header.prog_size);
	ft_printf("comment      = %.5s [...] len = %d\n", file->header.comment, ft_strlen(file->header.comment));
	ft_printf("prog         = %02x\n\n", file->prog[0]);

}

int 	usage(void)
{
	DG("USAGE\n");
	return (1);
}

int		main(int ac, char **av)
{
	t_asm_r		asm_r;

	if (ac == 1)
		return (usage());
	ft_bzero(&asm_r, sizeof(t_asm_r));
	if (init_asm_r(&asm_r, &av))
		return (1);
	return (0);
	(void)&ac;
	(void)&av;
}
