/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:02:48 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 18:02:50 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

char	*ft_arg_st_bis(global_t *global, char **line, int i, char **arg)
{
	if (i == 2)
	{
		if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 2, REG_CODE);
		else
			*arg = ft_arg(*arg, 2, IND_CODE);
	}
	if (i == 3)
		ft_exit(11, global, NULL);
	return (*arg);
}

char	*st_instruct(global_t *global, char **line)
{
	int		i;
	char	*arg;

	arg = ft_strdup("00000000");
	i = 0;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if (i > 2)
			ft_exit(11, global, NULL);
		else if (i == 1)
		{
			if (ft_strstart(line[i], "r"))
				arg = ft_arg(arg, 1, REG_CODE);
			else
				ft_exit(12, global, NULL);
		}
		else
			ft_arg_st_bis(global, line, i, &arg);
	}
	return (arg);
}
