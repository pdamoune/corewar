/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/04 01:33:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char			*is_arg_label(char *line)
{
	if (*line != LABEL_CHAR)
		return (NULL);
	++line;
	while (*line && ft_strchr(LABEL_CHARS, *line))
		++line;
	if (!*line || ft_isspa(*line) || ft_strchr(COMMENT_CHAR, *line))
		return (line);
	return (NULL);
}
