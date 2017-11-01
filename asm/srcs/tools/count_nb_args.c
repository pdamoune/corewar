/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:26:09 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/01 20:50:34 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					count_nb_args(char *line)
{
	int		args_found;

	args_found = 0;
	DG("ANALYZE OF %s", line);
	while (*line)
	{
		if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
			break;
		DG();
		if (*line == SEPARATOR_CHAR)
			return (-1);
		DG();
		++args_found;
		DG("val of char is %c [%d]", *line, *line);
		while (*line && !ft_isspa(*line) && !ft_strchr(COMMENT_CHAR, *line)
				&& *line != SEPARATOR_CHAR)
			++line;
		if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
			break;
		DG("val of char is %c [%d]", *line, *line);
		if (*line != SEPARATOR_CHAR)
			return (-1);
		DG();
		++line;
	}
	return (args_found);
}
