/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:23:08 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/18 00:29:20 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

t_op	g_op_tab[17] =
{
	{"live", 1,
		{T_DIR},
		1, 10, "alive", 0, 0},
	{"ld", 2,
		{T_DIR | T_IND, T_REG},
		2, 5, "load", 1, 0},
	{"st", 2,
		{T_REG, T_IND | T_REG},
		3, 5, "store", 1, 0},
	{"add", 3,
		{T_REG, T_REG, T_REG},
		4, 10, "addition", 1, 0},
	{"sub", 3,
		{T_REG, T_REG, T_REG},
		5, 10, "soustraction", 1, 0},
	{"and", 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1,
		{T_DIR},
		9, 20, "jump if zero", 0, 1},
	{"ldi", 3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1},
	{"sti", 3,
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1},
	{"fork", 1,
		{T_DIR},
		12, 800, "fork", 0, 1},
	{"lld", 2,
		{T_DIR | T_IND, T_REG},
		13, 10, "long load", 1, 0},
	{"lldi", 3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1},
	{"lfork", 1,
		{T_DIR},
		15, 1000, "long fork", 0, 1},
	{"aff", 1,
		{T_REG},
		16, 2, "aff", 1, 0}
};

int		write_prog(t_asm_r *asm_r, int fd, char *prog, unsigned *prog_size)
{
	while (prog < asm_r->file.prog + *prog_size)
	{
		if (*prog > 0 && *prog < 17)
		{
			if (instru(asm_r, fd, g_op_tab[(int)*prog - 1], &prog))
				return (1);
		}
		else
			prog++;
	}
	return (0);
}

int		write_header(t_asm_r *asm_r, int fd, char *prog_name, char *comment)
{
	int		ret;

	ret = ft_dprintf(fd, ".name\t\t\"%s\"\n.comment\t\"%s\"\n\n",
	prog_name, comment);
	if (ret == -1)
	{
		return (verbose(asm_r, MSG_ERROR,
			"{yel}%s:{red} Invalid write", asm_r->file.filename));
	}
	return (0);
}

int		create_filename(t_asm_r *asm_r, int *fd, char *filename, int len)
{
	if (len < 4 || ft_strncmp(&filename[len - 4], ".cor", 5))
	{
		return (verbose(asm_r, MSG_ERROR,
			"{yel}%s:{red} Invalid file name", filename));
	}
	if (ft_strlen(FILE_EXT) > 3)
	{
		return (verbose(asm_r, MSG_ERROR,
			"{yel}%s:{red} Invalid file extension", filename));
	}
	ft_strcpy(&filename[len - 3], FILE_EXT);
	if ((*fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
	{
		return (verbose(asm_r, MSG_ERROR,
			"{yel}%s:{red} Problem creating file", filename));
	}
	return (0);
}

int		create_file(t_asm_r *asm_r, t_file *file)
{
	int		fd;

	if (create_filename(asm_r, &fd, file->filename, ft_strlen(file->filename)))
		return (1);
	if (write_header(asm_r, fd, file->header.prog_name, file->header.comment))
		return (1);
	if (write_prog(asm_r, fd, file->prog, &asm_r->file.header.prog_size))
		return (1);
	close(fd);
	return (0);
}
