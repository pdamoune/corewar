/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_and_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:37:07 by wescande          #+#    #+#             */
/*   Updated: 2017/11/05 13:51:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		get_reg(t_asm *a, char *arg, t_argument *parsed_args)
{
	int			arg_value;
	int			allowed_type;

	allowed_type = parsed_args->type;
	parsed_args->type = T_REG;
	if (!(allowed_type & T_REG))
		return (-1);
	if (!ft_spastrisnumeral(arg))
		return (-1);
	arg_value = ft_atoi(arg);
	if (arg_value < 0 || arg_value > REG_NUMBER)
		verbose(a, MSG_WARNING,
				"%s-L%d: Register range is [0-%d], yours is %d\n[%s]",
				a->file.filename, a->file.line_number, REG_NUMBER, arg_value,
				a->file.line);
	parsed_args->value.reg = arg_value;
	return (0);
}

static int		get_dir(t_asm *a, char *arg, t_argument *parsed_args)
{
	char		*end_of_label;
	int			allowed_type;

	allowed_type = parsed_args->type;
	parsed_args->type = T_DIR;
	if (!(allowed_type & T_DIR))
		return (-1);
	if ((end_of_label = is_arg_label(arg)))
		return (analyze_arg_label(a, arg + 1, parsed_args, end_of_label));
	else if (!ft_spastrisnumeral(arg))
		return (-1);
	parsed_args->value.dir = ft_atoi(arg);
	return (0);
}

static int		get_ind(t_asm *a, char *arg, t_argument *parsed_args)
{
	char		*end_of_label;
	int			allowed_type;

	allowed_type = parsed_args->type;
	parsed_args->type = T_IND;
	if (!(allowed_type & T_IND))
		return (-1);
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
		return (get_reg(a, arg + 1, parsed_args));
	else if (*arg == '%')
		return (get_dir(a, arg + 1, parsed_args));
	return (get_ind(a, arg, parsed_args));
}

int				analyze_each_arguments(t_asm *a, const t_op *cur_instru,
					char **arg, t_argument *parsed_args)
{
	int			i;

	i = -1;
	while (++i < cur_instru->nb_params)
	{
		parsed_args[i].type = cur_instru->params[i];
		if (-1 == get_type_and_value(a, arg[i], &parsed_args[i]))
		{
			if (!(parsed_args[i].type & cur_instru->params[i]))
			{
				return (verbose(a, MSG_ERROR,
					"%s-L%d: Arg n°%d has incorrect type %s vs %s.\n[%s]",
						a->file.filename, a->file.line_number, i,
						type_to_str(parsed_args[i].type),
						type_to_str(cur_instru->params[i]), a->file.line));
			}
			return (verbose(a, MSG_ERROR,
					"%s-L%d: Arg n°%d has wrong format for type %s.\n[%s]",
						a->file.filename, a->file.line_number, i,
						type_to_str(parsed_args[i].type), a->file.line));
		}
		if (parsed_args[i].type & T_LAB)
			parsed_args[i].label->pos_label = i;
	}
	return (0);
}
