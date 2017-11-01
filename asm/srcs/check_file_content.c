/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:09:59 by wescande          #+#    #+#             */
/*   Updated: 2017/11/01 21:43:46 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static const t_op	g_op_tab[] =
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


// int					write_char(t_asm *a, char c, int *cur_len)
// {
// 	if (a->file.header.prog_size + *cur_len > 2 * CHAMP_MAX_SIZE)
// 	{
// 		SET(a->file.flag, LEN_ERROR);
// 		return (verbose(a, MSG_ERROR, "%s: Champion is too big", a->file.filename));
// 	}
// 	if (a->file.header.prog_size + *cur_len > CHAMP_MAX_SIZE && IS_UNSET(a->file.flag, LEN_WARNING))
// 	{
// 		SET(a->file.flag, LEN_WARNING);
// 		verbose(a, MSG_WARNING, "%s: Champion is too big", a->file.filename);
// 	}
// 	a->file.prog[a->file.header.prog_size + *cur_len++] = c;
// 	return (0);
// }

int					get_type_and_value(t_asm *a, t_op *cur_instru, char *arg, t_argument *parsed_args)
{
	if (skip_spa(&arg))
		return (-1);

	parsed_args->type = T_IND;
	parsed_args->value.ind = 65000;
	parsed_args->label = NULL;

	(void)a;
	(void)parsed_args;
	(void)cur_instru;
	return(0);
	//get type, then set t_arguments value corresponding to the type.
	//if label, check label lx to see if label exist
}

int					parse_arguments(t_asm *a, t_op *cur_instru, char *line, t_argument parsed_args[])
{
	char			**arg;
	int				ret;
	int				i;


	if (cur_instru->nb_params != (i = count_nb_args(line)))
		return (verbose(a, MSG_ERROR, "%s: L %d: Incorrect nb of arguments %d on %d expected [%s]", a->file.filename, a->file.line_number, i, cur_instru->nb_params, a->file.line));
	if (!(arg = ft_strsplit(line, SEPARATOR_CHAR)))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	i = -1;
	while (++i < cur_instru->nb_params)
	{
		if (-1 == (ret = get_type_and_value(a, cur_instru, arg[i], &parsed_args[i])))
		{
			verbose(a, MSG_ERROR, "%s: L %d: type not recognized for arg %d", a->file.filename, a->file.line_number, i);
			break;
		}

	}

	if (ret)
		;
		//TODO erase inside t_arguments
	ft_tabdel(&arg);
	return (ret);
}

// int			write_arg_to_prog(char *prog, int *prog_size, int size, int value)
// {
// 	unsigned int		ret;
// 	char				i;
//
// 	ret = 0;
// 	i = -1;
// 	while (++i < size)
//
// 	*pc_inc += size;
// 	return (ret);
// }

int					write_instruction(t_asm *a, t_op *cur_instru, t_argument *parsed_args)
{
	int nb_param;

	DG("prog_size = %d", PROG_SIZE);
	DG("prog = %d", *a->file.prog);
	nb_param = 0;
	//TODO ocp
	while (nb_param < cur_instru->nb_params)
	{
		DG("type : %d", parsed_args[nb_param].type);

		if (IS_SET(parsed_args[nb_param].type, T_REG))
		{
			a->file.prog[PROG_SIZE++] = parsed_args[nb_param].value.reg;
		}

		if (IS_SET(parsed_args[nb_param].type, T_IND))
		{

			*(unsigned short *)(&a->file.prog[PROG_SIZE]) = bswap_16(parsed_args[nb_param].value.ind);
			DG("bin : %d", parsed_args[nb_param].value.ind);
			DG("prog 0 : %hhx", a->file.prog[PROG_SIZE]);
			DG("prog 1 : %hhx", a->file.prog[PROG_SIZE + 1]);
			PROG_SIZE += 2;
		}
			// return ((short)get_int_from_area(vm, p->pc, 2, pc_inc));

		if (IS_SET(parsed_args[nb_param].type, T_DIR) && cur_instru->index)
		{

		}
			// return ((short)get_int_from_area(vm, p->pc, 2, pc_inc));

		if (IS_SET(parsed_args[nb_param].type, T_DIR))
		{

		}
			// return ((int)get_int_from_area(vm, p->pc, 4, pc_inc));

		return (0);
		nb_param++;
	}

	(void)a;
	(void)cur_instru;
	(void)parsed_args;
	return (1);
}

int					parse_instruction(t_asm *a, t_op *cur_instru, char *line)
{
	int				ret;
	t_argument		parsed_args[MAX_ARGS_NUMBER];

	if (skip_spa(&line))
		return (verbose(a, MSG_ERROR, "%s: Unknown error: [%s]", a->file.filename, a->file.line));
		// line++;
	ft_bzero(parsed_args, sizeof(t_argument) * MAX_ARGS_NUMBER);
	ret = parse_arguments(a, cur_instru, line, parsed_args);

	// if (!ret)
	// 	return (ret); // TODO

	if(write_instruction(a, cur_instru, parsed_args))
		return (verbose(a, MSG_ERROR, "Pb intruction: [%s]", cur_instru->instruc));
	//TODO write instruction && avance prog_size
	//todo ELSE REMOVE LABEL, remove memory leaks

	return (ret);
}

static t_op			*is_instruction(t_asm *a, char **line)
{
	int		i;

	i = -1;
	while (++i < 16)
		if (!ft_strncmp(*line, g_op_tab[i].instruc, ft_strlen(g_op_tab[i].instruc)))//TODO BETTER CHECK
		{
			*line += ft_strlen(g_op_tab[i].instruc);
			return ((t_op *)&g_op_tab[i]);
		}
	return (NULL);
	(void)a;
}

int					save_label(t_asm *a, char **line, char *end_of_label)
{
	t_label		*label;
//TODO CHECK IF LABEL EXIST
	//TODO function to free label
	if (!(label = (t_label *)malloc(sizeof(t_label))))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	*end_of_label = 0;
	label->label = ft_strdup(*line);
	*end_of_label = LABEL_CHAR;
	*line = end_of_label + 1;
	label->pos_label = a->file.header.prog_size;
	label->pos_instru = a->file.header.prog_size;
	ft_ld_pushback(&a->file.list_know_label, label);
	return (0);
}


int					check_file_content(t_asm *a, char *line)
{
	t_op		*cur_instru;
	char		*end_of_label;

	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (3);
	if ((end_of_label = is_label(line)))
		if (save_label(a, &line, end_of_label))
			return (-1);
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (3);
	if ((cur_instru = is_instruction(a, &line)))
		return (parse_instruction(a, cur_instru, line));
	return (verbose(a, MSG_ERROR, "%s: Unknown line: [%s]", a->file.filename, a->file.line));
}
