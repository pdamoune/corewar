/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:09:59 by wescande          #+#    #+#             */
/*   Updated: 2017/11/04 17:12:07 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					check_and_stock_instruction(t_asm *a, const t_op *cur_instru, t_argument *parsed_args)
{
	int		ocp;
	int		instruction_len;

	ocp = calcul_ocp(cur_instru->nb_params, parsed_args);
	instruction_len = calcul_instruction_len(cur_instru->ocp, ocp, cur_instru->nb_params, cur_instru->index);
	if (PROG_SIZE + instruction_len > 2 * CHAMP_MAX_SIZE)
	{
		SET(a->file.flag, LEN_ERROR);
		return (verbose(a, MSG_ERROR,
					"%s-L%d: Champion is too big", a->file.filename, a->file.line_number));
	}
	if (PROG_SIZE + instruction_len > CHAMP_MAX_SIZE
			&& IS_UNSET(a->file.flag, LEN_WARNING))
	{
		SET(a->file.flag, LEN_WARNING);
		verbose(a, MSG_WARNING, "%s-L%d: Champion is too big", a->file.filename, a->file.line_number);
	}
	return (stock_instruction(a, cur_instru, parsed_args, ocp));
}

int					parse_arguments(t_asm *a, const t_op *cur_instru,
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


int					parse_instruction(t_asm *a, const t_op *cur_instru, char *line)
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
	if (check_and_stock_instruction(a, cur_instru, parsed_args))
	{
		return (verbose(a, MSG_ERROR, "%s-L%d: Can't write instruction: [%s]",
					a->file.filename, a->file.line_number,
					cur_instru->instruc));
	}
	return (0);
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
		replace_label(a, label, found);
	return (0);
}


int					check_file_content(t_asm *a, char *line)
{
	const t_op	*cur_instru;
	char		*end_of_label;

	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (3);
	if ((end_of_label = is_label(line)))
		if (save_label(a, &line, end_of_label))
			return (-1);
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (3);
	if ((cur_instru = is_instruction(&line)))
		return (parse_instruction(a, cur_instru, line));
	return (verbose(a, MSG_ERROR, "%s-L%d: Unknown line: [%s]", a->file.filename, a->file.line_number, a->file.line));
}
