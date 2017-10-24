/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:56:31 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/24 16:17:03 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

extern t_op	g_op_tab[];

/*char	*ft_arg_and_bis(t_global *global, char **line, int i, char **arg)
{
	if (i == 2)
	{
		if (ft_strstart(line[i], "%"))
			*arg = ft_arg(*arg, 2, DIR_CODE);
		else if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 2, REG_CODE);
		else
			*arg = ft_arg(*arg, 2, IND_CODE);
	}
	else if (i == 3)
	{
		if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 3, REG_CODE);
		else
			ft_exit(12, global, NULL);
	}
	return (*arg);
}

char	*and_instruct(t_global *global, char **line)
{
	int		i;
	char	*arg;

	arg = ft_strdup("00000000");
	i = 0;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if (i > 3)
			ft_exit(11, global, NULL);
		else if (i == 1)
		{
			if (ft_strstart(line[i], "%"))
				arg = ft_arg(arg, 1, DIR_CODE);
			else if (ft_strstart(line[i], "r"))
				arg = ft_arg(arg, 1, REG_CODE);
			else
				arg = ft_arg(arg, 1, IND_CODE);
		}
		else
			ft_arg_and_bis(global, line, i, &arg);
	}
	return (arg);
}
*/
char	*ft_central(t_global *global, char **line)
{
	int		i;
	char	*arg;

	arg = ft_strdup("00000000");
	i = 0;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if (i > g_op_tab[global->i_tab].nb_params)
			ft_exit(11, global, NULL);
		else if (i == 1)
		{
			if (ft_strstart(line[i], "%") && g_op_tab[global->i_tab].params[0] & T_DIR)
				arg = ft_arg(arg, 1, DIR_CODE);
			else if (ft_strstart(line[i], "r") && g_op_tab[global->i_tab].params[0] & T_REG)
				arg = ft_arg(arg, 1, REG_CODE);
			else if (g_op_tab[global->i_tab].params[0] & T_IND)
				arg = ft_arg(arg, 1, IND_CODE);
			else
				ft_exit(12, global, NULL);
		}
		else
			ft_central2(global, line, i, &arg);
	}
	return (arg);
}

char	*ft_central2(t_global *global, char **line, int i, char **arg)
{
	if (i == 2)
	{
		if (ft_strstart(line[i], "%") && g_op_tab[global->i_tab].params[1] & T_DIR)
			*arg = ft_arg(*arg, 2, DIR_CODE);
		else if (ft_strstart(line[i], "r") && g_op_tab[global->i_tab].params[1] & T_REG)
			*arg = ft_arg(*arg, 2, REG_CODE);
		else if (g_op_tab[global->i_tab].params[1] & T_IND)
			*arg = ft_arg(*arg, 2, IND_CODE);
		else
			ft_exit(12, global, NULL);
	}
	else
		ft_central3(global, line, i, arg);
	return (*arg);
}

char	*ft_central3(t_global *global, char **line, int i, char **arg)
{
	if (i == 3)
	{
		if (ft_strstart(line[i], "%") && g_op_tab[global->i_tab].params[2] & T_DIR)
			*arg = ft_arg(*arg, 3, DIR_CODE);
		else if (ft_strstart(line[i], "r") && g_op_tab[global->i_tab].params[2] & T_REG)
			*arg = ft_arg(*arg, 3, REG_CODE);
		else if (g_op_tab[global->i_tab].params[2] & T_IND)
			*arg = ft_arg(*arg, 3, IND_CODE);
		else
			ft_exit(12, global, NULL);
	}
	return (*arg);
}
