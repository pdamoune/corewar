/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:23:08 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/17 23:37:48 by pdamoune         ###   ########.fr       */
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

 int		check_args(t_asm_r *asm_r, t_op op, unsigned int *type, unsigned int *args)
{
	int		i;

	i = -1;
	while (++i < op.nb_params)
	{
		if (IS_UNSET(op.params[i], type[i]) || !type[i])
		{
			verbose(asm_r, MSG_WARNING, "%b: Invalid type (allowed %b)", type[i], op.params[i]);
			return (1);
		}
		if (type[i] == T_REG && args[i] > REG_NUMBER)
		{
			verbose(asm_r, MSG_WARNING, "%u: max register is %d", args[i], REG_NUMBER);
			return (1);
		}
		if (type[i] == T_REG && args[i] == 0)
		{
			verbose(asm_r, MSG_WARNING, "%u: register min is %d", args[i], 1);
			return (1);
		}
		op.params[i] = type[i];
	}
	return (0);
}

static unsigned char	get_char_at(char *prog, int at)
{
	if (at < 0)
		at += MEM_SIZE;
	if (at >= MEM_SIZE)
		at %= MEM_SIZE;
	return (prog[at]);
}

static unsigned int		get_int_from_area(char *prog, char size, int *pc_inc)
{
	unsigned int		ret;
	char				i;

	ret = 0;
	i = -1;
	while (++i < size)
		ret = (ret << 8) | get_char_at(prog, *pc_inc + i);
	*pc_inc += size;
	return (ret);
}

unsigned int	get_value_from_area(char *prog, t_op op, unsigned int type, int *pc_inc)
{
	if (IS_SET(type, T_REG))
		return ((char)get_int_from_area(prog, 1, pc_inc));
	if (IS_SET(type, T_IND))
		return ((short)get_int_from_area(prog, 2, pc_inc));
	if (IS_SET(type, T_DIR) && op.index)
		return ((short)get_int_from_area(prog, 2, pc_inc));
	if (IS_SET(type, T_DIR))
		return ((int)get_int_from_area(prog, 4, pc_inc));
	return (0);
}

void		get_type_from_area(unsigned char ocp, int nb_params, unsigned int *type)
{
	int				i;
	unsigned char	bit;

	i = -1;
	while (++i < nb_params)
	{
		bit = (ocp >> (6 - 2 * i));
		if (bit & 1)
		{
			if ((bit >> 1) & 1)
				type[i] = T_IND;
			else
				type[i] = T_REG;
		}
		else if (bit & 2)
			type[i] = T_DIR;
		else
			type[i] = 0;
	}
}

int		write_instru(int fd, t_op op, unsigned int *type, unsigned int *args)
{
	char	*str;
	char	line[128];
	int		nb_arg;

	nb_arg = 0;
	ft_bzero(line, 128);
	str = line;
	*str++ = '\t';
	str += ft_strlen(ft_strcpy(str, op.label));
	*str++ = '\t';
	while (nb_arg < op.nb_params)
	{
		if (T_REG & type[nb_arg])
			*str++ = 'r';
		else if (!(T_IND & type[nb_arg]))
			*str++ = '%';
		ft_itoa_nomalloc(args[nb_arg], str);
		while (*str)
			str++;
		*str++ = ++nb_arg < op.nb_params ? ',' : '\n';
		*(str - 1) == ',' ?	*str++ = ' ' : 0;
	}
	if (ft_dprintf(fd, "%s", line) != str - line)
		return (1);
	return (0);
}

int		instru(t_asm_r *asm_r, int fd, t_op op, char **prog)
{
	unsigned int	type[MAX_ARGS_NUMBER];
	unsigned int	args[MAX_ARGS_NUMBER];
	int				pc_inc;
	int				i;

	pc_inc = op.ocp ? 2 : 1;
	type[0] = T_DIR;
	if (op.ocp)
		get_type_from_area(prog[0][1], op.nb_params, type);
	i = -1;
	while (++i < op.nb_params)
		args[i] = get_value_from_area(*prog, op, type[i], &pc_inc);
	if (check_args(asm_r, op, type, (unsigned *)args))
		// *prog += pc_inc; TODO Verifier si c est utile
		verbose(asm_r, MSG_WARNING, "%s: Instruction has invalid type parameters", op.label);
	if (write_instru(fd, op, type, args))
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} Invalid write",
		asm_r->file.filename));
	if (pc_inc)
		*prog += pc_inc;


	return (0);
	// ft_printf("label = |%s|\n", op.label);
	// ft_printf("type[0] = %x\n", type[0]);
	// ft_printf("type[1] = %x\n", type[1]);
	// ft_printf("type[2] = %x\n", type[2]);
	//
	// ft_printf("args[0] = %x\n", args[0]);
	// ft_printf("args[1] = %x\n", args[1]);
	// ft_printf("args[2] = %x\n", args[2]);
	// ft_printf("op.ocp = %x\n", op.ocp);
	// ft_printf("op.ocp = %x\n", op.ocp);

	// else if ()
	(void)op;
	(void)asm_r;
	(void)fd;
	(void)prog;
	return (0);
}

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
	(void)asm_r;
	(void)fd;
	(void)prog;
	return (0);
	// display(file);

}

int		write_header(t_asm_r *asm_r, int fd, char *prog_name, char *comment)
{
	int		ret;

	ret = ft_dprintf(fd, ".name\t\t\"%s\"\n.comment\t\"%s\"\n\n",
	prog_name, comment);
	if (ret == -1)
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} Invalid write",
		asm_r->file.filename));
	return (0);
}

int 	create_file(t_asm_r *asm_r, int *fd, char *filename, int len)
{
	if (len < 4 || ft_strncmp(&filename[len - 4], ".cor", 5))
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} Invalid file name",
			filename));
	if (ft_strlen(FILE_EXT) > 3)
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} Invalid file extension",
			filename));
	ft_strcpy(&filename[len - 3], FILE_EXT);
	if ((*fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} Problem creating file",
			filename));
	return (0);
}

int			create_asm_r(t_asm_r *asm_r, t_file *file)
{
	int		fd;

	if (create_file(asm_r, &fd, file->filename, ft_strlen(file->filename)))
		return (1);
	if (write_header(asm_r, fd, file->header.prog_name, file->header.comment))
		return (1);
	write_prog(asm_r, fd, file->prog, &asm_r->file.header.prog_size);
	close(fd);
	return (0);
}
