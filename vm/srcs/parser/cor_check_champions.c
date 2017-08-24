/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_check_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:29:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/24 17:41:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int 	cor_read(int fd, void *ptr, int size)
{
	int ret;

	ret = read(fd, ptr, size);
	ft_printf("  ret = %5d %5x | \n", ret, ret);
	return (ret);
	// ft_printf("magic     = %x \n", ptr);
	// E_TITLE
}

int		cor_get_data(int fd, header_t *header)
{
	if (cor_read(fd, &header->magic, 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if ((header->magic = INTREV32(header->magic)) != COREWAR_EXEC_MAGIC)
		DG("\nError : Bad header, bad magic number\n");
	else if (cor_read(fd, header->prog_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		DG("\nError : Bad header, bad name\n");
	else if (cor_read(fd, &header->prog[0], 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if (cor_read(fd, &header->prog_size, 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if ((header->prog_size = INTREV32(header->prog_size)) > CHAMP_MAX_SIZE)
		DG("\nError : Bad header, program size is too long\n");
	else if (cor_read(fd, header->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		DG("\nError : Bad header, bad comment\n");
	else if (cor_read(fd, &header->prog[0], 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if (cor_read(fd, header->prog, CHAMP_MAX_SIZE + 1) != (int)header->prog_size)
		DG("\nError : Bad header, program size differs from what its header says\n");
	else
		return (1);
	return (0);
}


int		cor_check_champions(int ac, char **av, int index)
{
	TITLE
	header_t	header;
	int 		fd;

	// DG("\nac = %d | index = %d | av[index] = %s\n", ac, index, av[index]);
	ft_bzero(&header, sizeof(header_t));
	if ((fd = open(av[index], O_RDONLY)) == -1)
		exit (DG("\nBad champion file : fd = %d\n", fd));
	(void)&ac;
	if (!cor_get_data(fd, &header))
		DG("\nError : get_data\n");


	ft_printf("prog_name  : %.10s(...)\n", header.prog_name);
	ft_printf("prog_size  : %x\n", header.prog_size);
	ft_printf("comment    : %.10s(...)\n", header.comment);
	ft_printf("prog       : %08x(...)\n", INTREV32(header.prog[0]));
	ft_printf("magic      : %x\n", header.magic);

	E_TITLE
	return (1);
}
