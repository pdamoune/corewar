/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:09:59 by wescande          #+#    #+#             */
/*   Updated: 2017/11/01 22:29:10 by tdebarge         ###   ########.fr       */
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

int					get_reg(int i, t_op *cur_instru, char *arg, t_argument *parsed_args)
{
	if (!cur_instru->params[i] & T_REG)
		return (-1);	
	parsed_args[i].type = T_REG;
	parsed_args[i].value.reg = ft_atoi(arg + 1);
	return (0);
}

int					get_dir(int i, t_op *cur_instru, char *arg, t_argument *parsed_args)
{
	if (!cur_instru->params[i] & T_DIR)
		return (-1);
	++arg;
	if (*arg == ':')
	{
		parsed_args[i].type = T_DIR | T_LAB;
		//TODO find value if label is known ELSE save in list of unknown labels
	}
	else if (*arg == '-' || (*arg >= '0' && *arg <= '9'))
	{
		parsed_args[i].type = T_DIR;
		parsed_args[i].value.dir = ft_atoi(arg);
	}
	else
		return (-1);
	return (0);
}

int					get_ind(int i, t_op *cur_instru, char *arg, t_argument *parsed_args)
{
	if (!cur_instru->params[i] & T_IND)
		return (-1);
	if (*arg == ':')
	{
		parsed_args[i].type = T_IND | T_LAB;
		//TODO find value if label is known ELSE save in list of unknown labels
	}
	else if (*arg == '-' || (*arg >= '0' && *arg <= '9'))
	{
		parsed_args[i].type = T_IND;
		parsed_args[i].value.ind = ft_atoi(arg);
	}
	else
		return (-1);
	return (0);
}

int					get_type_and_value(int i, t_op *cur_instru, char *arg, t_argument *parsed_args)
{
	int				ret;

	if (skip_spa(&arg))
		return (-1);
	if (*arg == 'r')
		ret = get_reg(i, cur_instru, arg, &parsed_args[i]);
	else if (*arg == '%')
		ret = get_dir(i, cur_instru, arg, &parsed_args[i]);
	else
		ret = get_ind(i, cur_instru, arg, &parsed_args[i]);
	if (ret)
		return (-1);
	return(0);
}

int					parse_arguments(t_asm *a, t_op *cur_instru, char *line, t_argument parsed_args[])
{
	char			**arg;
	int				ret;
	int				i;

DG();
	if (cur_instru->nb_params != (i = count_nb_args(line)))
		return (verbose(a, MSG_ERROR, "%s: L %d: Incorrect nb of arguments %d on %d expected [%s]", a->file.filename, a->file.line_number, i, cur_instru->nb_params, a->file.line));
DG();
	if (!(arg = ft_strsplit(line, SEPARATOR_CHAR)))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	i = -1;
	while (++i < cur_instru->nb_params)
	{
		if (-1 == (ret = get_type_and_value(i, cur_instru, arg[i], &parsed_args[i])))
		{
			verbose(a, MSG_ERROR, "%s: L %d: type not recognized for arg %d", a->file.filename, a->file.line_number, i);
			break;
		}

	}

	if (ret)
		//TODO erase inside t_arguments
	ft_tabdel(&arg);
	return (ret);
}


// {"live", 1,
// 	{T_DIR},
// 	1, 10, "alive", 0, 0},

int					write_instruction(t_asm *a, t_op *cur_instru, t_argument *parsed_args)
{


	(void)a;
	(void)cur_instru;
	(void)parsed_args;
	return (0);
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
	if (ret)
		return (ret); // TODO
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
