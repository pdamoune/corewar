/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:29:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/09 14:01:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		analyze_header(t_vm *vm, t_header *header)
{
	if ((header->magic = INTREV32(header->magic)) != COREWAR_EXEC_MAGIC)
		return (verbose(vm, MSG_ERROR,
				"Invalid magic: %x: Magic number should be %x",
				header->magic, COREWAR_EXEC_MAGIC));
	else if (header->prog_name[PROG_NAME_LENGTH])
		return (verbose(vm, MSG_ERROR,
				"Invalid name: Should be null terminated '%c' (%d)",
				header->prog_name[PROG_NAME_LENGTH],
				header->prog_name[PROG_NAME_LENGTH]));
	else if ((header->prog_size = INTREV32(header->prog_size)) > CHAMP_MAX_SIZE)
		return (verbose(vm, MSG_ERROR,
				"Invalid program size: %u: Max program size is %d",
				header->prog_size, CHAMP_MAX_SIZE));
	else if (!header->prog_size)
		return (verbose(vm, MSG_ERROR,
				"Invalid program size: Program cannot be empty", NULL));
	else if (header->comment[COMMENT_LENGTH])
	{
		return (verbose(vm, MSG_ERROR,
				"Invalid comment: Should be null terminated '%c' (%d)",
				header->comment[COMMENT_LENGTH],
				header->comment[COMMENT_LENGTH]));
	}
	return (0);
}

int				init_data(t_vm *vm, int fd, t_file *file)
{
	int		n_read;

	if ((n_read = read(fd, &(file->header), sizeof(t_header)))
				!= sizeof(t_header))
	{
		return (verbose(vm, MSG_ERROR,
				"Invalid header: %d: Failed to read full header (%d)",
				n_read, sizeof(t_header)));
	}
	if (analyze_header(vm, &(file->header)))
		return (1);
	else if ((n_read = read(fd, file->prog, CHAMP_MAX_SIZE + 1))
					!= (int)file->header.prog_size)
	{
		return (verbose(vm, MSG_ERROR,
				"Invalid program: %d: Program size expected is %u",
				n_read, file->header.prog_size));
	}
	return (0);
}
