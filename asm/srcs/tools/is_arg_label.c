/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/02 17:39:26 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char			*is_arg_label(char *line)
{
	if (*line != LABEL_CHAR)
		return (NULL);
	while (*line && ft_strchr(line, LABEL_CHAR))
		++line;
	if (!*line || ft_isspa(*line) || ft_strchr(COMMENT_CHAR, *line))
	{
		return (NULL);

	}
	DG("line: %s", line);

	return (line);
}
