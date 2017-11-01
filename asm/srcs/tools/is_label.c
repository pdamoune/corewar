/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/01 16:24:27 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char			*is_label(char *line)
{
	while (*line && ft_strchr(LABEL_CHARS, *line))
		++line;
	if (*line == LABEL_CHAR)
		return (line);
	return (NULL);
}
