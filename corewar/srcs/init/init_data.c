/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:29:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/29 18:03:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int 	init_read(int fd, void *ptr, int size)
{
	int ret;

	ret = read(fd, ptr, size);
	return (ret);
	// ft_printf("magic     = %x \n", ptr);
	// E_TITLE
}

int		init_data(int fd, t_header *header)
{
	if (init_read(fd, &header->magic, 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if ((header->magic = INTREV32(header->magic)) != COREWAR_EXEC_MAGIC)
		DG("\nError : Bad header, bad magic number\n");
	else if (init_read(fd, header->prog_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		DG("\nError : Bad header, bad name\n");
	else if (init_read(fd, &header->prog[0], 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if (init_read(fd, &header->prog_size, 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if ((header->prog_size = INTREV32(header->prog_size)) > CHAMP_MAX_SIZE)
		DG("\nError : Bad header, program size is too long\n");
	else if (init_read(fd, header->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		DG("\nError : Bad header, bad comment\n");
	else if (init_read(fd, &header->prog[0], 4) != 4)
		DG("\nError : Bad header, bad size of file\n");
	else if (init_read(fd, header->prog, CHAMP_MAX_SIZE + 1) != (int)header->prog_size)
		DG("\nError : Bad header, program size differs from what its header says\n");
	else
		return (0);
	return (1);
}
