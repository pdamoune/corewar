/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:37:07 by wescande          #+#    #+#             */
/*   Updated: 2017/11/02 20:01:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		get_reg(t_asm *a, char *arg, t_argument *parsed_args)
{
	int			arg_value;

	if (!parsed_args->type & T_REG)
		return (-1);
	if (!ft_spastrisnumeral(arg))
		return (-1);
	parsed_args->type = T_REG;
	arg_value = ft_atoi(arg + 1);
	if (arg_value < 0 || arg_value > REG_NUMBER)
		verbose(a, MSG_WARNING,
				"%s: L%d: Register range is [0-%d], yours is %d",
				a->file.line, a->file.line_number, REG_NUMBER, arg_value);
	parsed_args->value.reg = arg_value;
	return (0);
}

static int		get_dir(t_asm *a, char *arg, t_argument *parsed_args)
{
	char *end_of_label;

	if (!parsed_args->type & T_DIR)
		return (-1);
	parsed_args->type = T_DIR;
	++arg;
	if ((end_of_label = is_arg_label(arg)))
		return (analyze_arg_label(a, arg + 1, parsed_args, end_of_label));
	else if (!ft_spastrisnumeral(arg))
		return (-1);
	parsed_args->value.dir = ft_atoi(arg);
	return (0);
}

static int		get_ind(t_asm *a, char *arg, t_argument *parsed_args)
{
	char *end_of_label;

	if (!parsed_args->type & T_IND)
		return (-1);
	parsed_args->type = T_IND;
	if ((end_of_label = is_arg_label(arg)))
		return (analyze_arg_label(a, arg + 1, parsed_args, end_of_label));
	else if (!ft_spastrisnumeral(arg))
		return (-1);
	parsed_args->value.ind = ft_atoi(arg);
	return (0);
}

static int		get_type_and_value(t_asm *a, char *arg, t_argument *parsed_args)
{
	if (skip_spa(&arg))
		return (-1);
	if (*arg == 'r')
		return (get_reg(a, arg, parsed_args));
	else if (*arg == '%')
		return (get_dir(a, arg, parsed_args));
	return (get_ind(a, arg, parsed_args));
}

int				analyze_each_arguments(t_asm *a, t_op *cur_instru, char **arg,
										t_argument *parsed_args)
{
	int			i;

	i = -1;
	while (++i < cur_instru->nb_params)
	{
		parsed_args[i].type = cur_instru->params[i];
		if (-1 == get_type_and_value(a, arg[i], &parsed_args[i]))
		{
			return (verbose(a, MSG_ERROR,
						"%s: L %d: Arg %d has not a valid type type found is : "
						"%s Type allowed are vs %s. [%s]",
						a->file.filename, a->file.line_number, i,
						type_to_str(parsed_args[i].type),
						type_to_str(cur_instru->params[i]), a->file.line));
		}
		if (parsed_args[i].type & T_LAB)
			parsed_args[i].label->pos_label = i;
	}
	return (0);
}

