/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:09:59 by wescande          #+#    #+#             */
/*   Updated: 2017/11/02 20:06:36 by wescande         ###   ########.fr       */
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

unsigned char		calcul_ocp(int	nb_params, t_argument *parsed_args)
{
	unsigned char		ocp;
	int					i;

	i = -1;
	ocp = 0;
	while (++i < nb_params)
	{
		if (IS_SET(parsed_args[i].type, T_REG))
			ocp |= (1 << (6 - 2 * i));
		if (IS_SET(parsed_args[i].type, T_DIR))
			ocp |= (2 << (6 - 2 * i));
		if (IS_SET(parsed_args[i].type, T_IND))
			ocp |= (3 << (6 - 2 * i));
	}
	return (ocp);
}

int					write_instruction(t_asm *a, t_op *cur_instru, t_argument *parsed_args)
{
	int nb_param;

	DG("prog_size = %d", PROG_SIZE);
	DG("prog = %d", *a->file.prog);
	nb_param = 0;
	//TODO check len < CHAMP_MAX_SIZE
	//TODO write instruction op and ocp
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
	return (0);
}

int		free_arguments(t_op *cur_instru, t_argument *parsed_args)
{
	int				i;
	
	i = -1;
	while (++i < cur_instru->nb_params)
		if (parsed_args[i].type & T_LAB)
		{
			ft_strdel(&parsed_args[i].label->label);
			free(parsed_args[i].label);
		}
	return (-1);
}

int					parse_arguments(t_asm *a, t_op *cur_instru,
									char *line, t_argument *parsed_args)
{
	char			**arg;
	int				ret;
	int				i;

	if (cur_instru->nb_params != (i = count_nb_args(line)))
	{
		return (verbose(a, MSG_ERROR,
				"%s: L %d: Incorrect nb of arguments %d on %d expected [%s]",
				a->file.filename, a->file.line_number, i,
				cur_instru->nb_params, a->file.line));
	}
	if (!(arg = ft_strsplit(line, SEPARATOR_CHAR)))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	ret = analyze_each_arguments(a, cur_instru, arg, parsed_args);
	ft_tabdel(&arg);
	return (ret);
}


int					parse_instruction(t_asm *a, t_op *cur_instru, char *line)
{
	t_argument		parsed_args[MAX_ARGS_NUMBER];
	int				i;

	if (skip_spa(&line))
	{
		return (verbose(a, MSG_ERROR, "%s-L%d: Unknown error: [%s]",
						a->file.filename, a->file.line_number, a->file.line));
	}
	ft_bzero(parsed_args, sizeof(t_argument) * MAX_ARGS_NUMBER);
	if (parse_arguments(a, cur_instru, line, parsed_args))
		return (free_arguments(cur_instru, parsed_args));
	i = -1;
	while (++i < cur_instru->nb_params)
		if (parsed_args[i].type & T_LAB)
			ft_ld_pushfront(&a->file.list_unknow_label, parsed_args[i].label);
	if (write_instruction(a, cur_instru, parsed_args))
	{
		return (verbose(a, MSG_ERROR, "%s-L%d: Can't write instruction: [%s]",
					a->file.filename, a->file.line_number,
					cur_instru->instruc));
	}
	return (0);
}

static t_op			*is_instruction(t_asm *a, char **line)
{
	int		i;


	i = -1;
	while (++i < 16)
		if (!ft_spastrcmp(*line, g_op_tab[i].instruc))
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
	t_ld		**found;

	*end_of_label = 0;
	if ((found = find_label(&a->file.list_know_label, *line)))
	{
		*end_of_label = LABEL_CHAR;
		return (verbose(a, MSG_ERROR, "%s-L%d: Label [%s] Already exists",
					a->file.filename, a->file.line_number,
					((t_label*)(*found)->content)->label));
	}
	if (!(label = (t_label *)malloc(sizeof(t_label))))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	label->label = ft_strdup(*line);
	*end_of_label = LABEL_CHAR;
	*line = end_of_label + 1;
	label->pos_label = a->file.header.prog_size;
	label->pos_instru = a->file.header.prog_size;
	ft_ld_pushfront(&a->file.list_know_label, label);
	while ((found = find_label(&a->file.list_unknow_label, label->label)))
		replace_label(a, label->pos_label, found);
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
