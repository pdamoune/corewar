/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:23:09 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 16:23:13 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			check_header_comment(t_asm *a, char *line)
{
	if (*a->file.header.comment)
	{
		a->file.header.comment[a->file.comment_len++] = '\n';
		if (a->file.comment_len > COMMENT_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Comment is too long", a->file.filename));
	}
	while (*line && *line != '"')
	{
		a->file.header.comment[a->file.comment_len++] = *(line++);
		if (a->file.comment_len > COMMENT_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Comment is too long", a->file.filename));
	}
	if (!*line)
		return (2);
	++line;
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (0);
	return (verbose(a, MSG_ERROR, "%s: Comment lexical error", a->file.filename));
}

int			init_comment_header(t_asm *a, char *line)
{
	if (IS_SET(a->file.flag, HEAD_COMMENT))
		return (verbose(a, MSG_ERROR, "%s: Comment is already set", a->file.filename));
	SET(a->file.flag, HEAD_COMMENT);
	line += 8;
	while (ft_isspa(*line))
		++line;
	if (*line != '"')
		return (verbose(a, MSG_ERROR, "%s: Comment lexical error", a->file.filename));
	return (check_header_comment(a, line + 1));
}
