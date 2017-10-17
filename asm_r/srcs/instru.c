/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:06:16 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/18 00:29:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

int		check_args(t_asm_r *asm_r, t_op op, unsigned int *type,
	unsigned int *args)
{
	int		i;

	i = -1;
	while (++i < op.nb_params)
	{
		if (IS_UNSET(op.params[i], type[i]) || !type[i])
		{
			verbose(asm_r, MSG_WARNING, "%b: Invalid type (allowed %b)",
			type[i], op.params[i]);
			return (1);
		}
		if (type[i] == T_REG && args[i] > REG_NUMBER)
		{
			verbose(asm_r, MSG_WARNING, "%u: max register is %d", args[i],
			REG_NUMBER);
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
		*(str - 1) == ',' ? *str++ = ' ' : 0;
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
		get_type(prog[0][1], op.nb_params, type);
	i = -1;
	while (++i < op.nb_params)
		args[i] = get_value(*prog, op, type[i], &pc_inc);
	if (check_args(asm_r, op, type, (unsigned *)args))
		verbose(asm_r, MSG_WARNING,
			"%s: Instruction has invalid type parameters", op.label);
	if (write_instru(fd, op, type, args))
	{
		return (verbose(asm_r, MSG_ERROR,
			"{yel}%s:{red} Invalid write", asm_r->file.filename));
	}
	if (pc_inc)
		*prog += pc_inc;
	return (0);
}
