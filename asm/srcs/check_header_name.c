/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:23:09 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 16:21:27 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			check_header_name(t_asm *a, char *line)
{
	if (*a->file.header.prog_name)//TODO test faire un nom et/ou commentaire qui ne contient/commence qu'un '\0'
	{
		a->file.header.prog_name[a->file.name_len++] = '\n';
		if (a->file.name_len > PROG_NAME_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Name is too long", a->file.filename));
	}
	while (*line && *line != '"')
	{
		a->file.header.prog_name[a->file.name_len++] = *(line++);
		if (a->file.name_len > PROG_NAME_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Name is too long", a->file.filename));
	}
	if (!*line)
		return (1);
	++line;
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (0);
	return (verbose(a, MSG_ERROR, "%s: Name lexical error", a->file.filename));
}

static int			init_name_header(t_asm *a, char *line)
{
	if (IS_SET(a->file.flag, HEAD_NAME))
		return (verbose(a, MSG_ERROR, "%s: Name was already set", a->file.filename));
	SET(a->file.flag, HEAD_NAME);
	line += 5;
	while (ft_isspa(*line))//TODO check if .name /n "fjgaskjfghd" is valid
		++line;
	if (*line != '"')
		return (verbose(a, MSG_ERROR, "%s: Name lexical error", a->file.filename));
	return (check_header_name(a, line + 1));
}
