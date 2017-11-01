/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:09:59 by wescande          #+#    #+#             */
/*   Updated: 2017/11/01 16:26:41 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static const t_op	g_op_tab[17] =
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
	if (skip_spa(&arg) || ft_strchr(COMMENT_CHAR, *arg))
		return (-1);
	a = NULL;
	parsed_args = NULL;
	cur_instru = NULL;
	return(0);
	//get type, then set t_arguments value corresponding to the type.
	//if label, check label lx to see if label exist
}

int					parse_arguments(t_asm *a, t_op *cur_instru, char *line, t_argument parsed_args[])
{
	char			**av;
	int				ret;
	int				i;

	if (cur_instru->nb_params != (i = count_nb_args(line)))
		return (verbose(a, MSG_ERROR, "%s: L %d: Incorrect nb of arguments %d on %d expected [%s]", a->file.filename, a->file.line_number, i, cur_instru->nb_params, a->file.line));
	if (!(av = ft_strsplit(line, SEPARATOR_CHAR)))
		return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
	i = -1;
	while (++i < cur_instru->nb_params)
	{
		if (-1 == (ret = get_type_and_value(a, cur_instru, av[i], &parsed_args[i])))
		{
			verbose(a, MSG_ERROR, "%s: L %d: type not recognized for arg %d", a->file.filename, a->file.line_number, i);
			break;
		}
	}
	if (ret)
		//TODO erase inside t_arguments
	ft_tabdel(&av);
	return (ret);
}

int					parse_instruction(t_asm *a, t_op *cur_instru, char *line)
{
	int				ret;
	t_argument		parsed_args[MAX_ARGS_NUMBER];

	//SPA AVNCE
	ft_bzero(parsed_args, sizeof(t_argument) * MAX_ARGS_NUMBER);
	ret = parse_arguments(a, cur_instru, line, parse_arguments);
	if (!ret)
		//TODO write instruction && avance prog_size
	//todo ELSE REMOVE LABEL, remove memory leaks
	return (ret);
}

static t_op			*is_instruction(t_asm *a, char **line)
{
	int		i;

	i = -1;
	while (++i < 17)
		if (ft_isspa(ft_strcmp(*line, g_op_tab[i].label)))//TODO BETTER CHECK
		{
			*line += ft_strlen(g_op_tab[i].label);
			return ((t_op *)&g_op_tab[i]);
		}
	return (NULL);
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
	*line = end_of_label + 1;
	label->pos_label = a->file.header.prog_size;
	label->pos_instru = a->file.header.prog_size;
	list_add(&(new_label->list_label), &(a->file.list_know_label));
	return (0);
}


int					check_file_content(t_asm *a, char *line)
{
	t_op		*cur_instru;
	char		*end_of_label;

	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (3);
	if ((cur_instru = is_instruction(a, &line)))
		return (parse_instruction(a, cur_instru, line));
	if ((end_of_label = is_label(line)))
	{
		if (save_label(a, &line, end_of_label))
			return (-1);
		// return (check_file_content(a, line)); // TODO CHECK IF 2 label se suivent and remove linessss below
		if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
			return (3);
		if ((cur_instru = is_instruction(a, &line)))
			return (parse_instruction(a, cur_instru, line));
		if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
			return (3);
		return (verbose(a, MSG_ERROR, "%s: Invalid char at EOF: [%s]", a->file.filename, a->file.line));
	}
	return (verbose(a, MSG_ERROR, "%s: Unknow line: [%s]", a->file.filename, a->file.line));
}
