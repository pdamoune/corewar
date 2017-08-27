/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 11:53:01 by wescande          #+#    #+#             */
/*   Updated: 2017/08/27 12:06:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_player(int num, char *filename)
{
	header_t	header;
	int			fd;

	(void)num;
	ft_bzero(&header, sizeof(header_t));
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("corewar");
		return (1);
	}
	if (!cor_get_data(fd, &header))
		return (1);
	

	ft_printf("prog_name  : %.10s(...)\n", header.prog_name);
	ft_printf("prog_size  : %x\n", header.prog_size);
	ft_printf("comment    : %.10s(...)\n", header.comment);
	ft_printf("prog       : %08x(...)\n", INTREV32(header.prog[0]));
	ft_printf("magic      : %x\n", header.magic);

	return (0);
}