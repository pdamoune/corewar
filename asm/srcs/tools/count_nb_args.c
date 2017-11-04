/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:26:09 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/04 01:25:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					count_nb_args(char *line)
{
	int		args_found;

	args_found = 0;
	while (*line)
	{
		if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
			break;
		if (*line == SEPARATOR_CHAR)
			return (-1);
		++args_found;
		while (*line && !ft_isspa(*line) && !ft_strchr(COMMENT_CHAR, *line)
				&& *line != SEPARATOR_CHAR)
			++line;
		if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
			break;
		if (*line != SEPARATOR_CHAR)
			return (-1);
		++line;
	}
	return (args_found);
}
