/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:58:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/20 16:48:49 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

char		*ft_strstrchr(char *line, char *pool)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(pool, line[i]))
			return (line + i);
		i++;
	}
	return (NULL);
}

char		*ld_instruct(t_global *global, char **line)
{
	int		i;
	char	*arg;

	arg = ft_strdup("00000000");
	i = 0;
	while (line[++i] && !ft_strstrchr(line[i], COMMENT_CHAR))
	{
		if (i > 2)
			ft_exit(11, global, NULL);
		else if (i == 1)
		{
			if (ft_strstart(line[i], "%"))
				arg = ft_arg(arg, 1, DIR_CODE);
			else if (ft_strstart(line[i], "r") && !ft_strchr(line[i], ':'))
				arg = ft_arg(arg, 1, REG_CODE);
			else
				arg = ft_arg(arg, 1, IND_CODE);
		}
		else
			ft_arg_ld_bis(global, line, i, &arg);
	}
	return (arg);
}

char		*ft_arg_ld_bis(t_global *global, char **line, int i, char **arg)
{
	char	*comment_tmp;

	comment_tmp = NULL;
	if (i == 2)
	{
		if ((comment_tmp = ft_strstrchr(line[i], COMMENT_CHAR)))
			*comment_tmp = '\0';
		if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 2, REG_CODE);
		else
			ft_exit(12, global, NULL);
	}
	return (*arg);
}
