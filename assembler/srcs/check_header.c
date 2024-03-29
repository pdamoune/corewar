/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:23:09 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/05 12:49:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					check_header_name(t_asm *a, char *line)
{
	if (*a->file.header.prog_name)
	{
		a->file.header.prog_name[a->file.name_len++] = '\n';
		if (a->file.name_len > PROG_NAME_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Name is too long",
				a->file.filename));
	}
	while (*line && *line != '"')
	{
		a->file.header.prog_name[a->file.name_len++] = *(line++);
		if (a->file.name_len > PROG_NAME_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Name is too long",
				a->file.filename));
	}
	if (!*line)
		return (1);
	++line;
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
	{
		SET(a->file.flag, HEAD_NAME);
		return (0);
	}
	return (verbose(a, MSG_ERROR, "%s: Name lexical error", a->file.filename));
}

static int			init_name_header(t_asm *a, char *line)
{
	if (IS_SET(a->file.flag, HEAD_NAME))
	{
		return (verbose(a, MSG_ERROR, "%s: Name was already set",
				a->file.filename));
	}
	line += 5;
	while (ft_isspa(*line))
		++line;
	if (*line != '"')
	{
		return (verbose(a, MSG_ERROR, "%s: Name lexical error",
			a->file.filename));
	}
	return (check_header_name(a, line + 1));
}

int					check_header_comment(t_asm *a, char *line)
{
	if (*a->file.header.comment)
	{
		a->file.header.comment[a->file.comment_len++] = '\n';
		if (a->file.comment_len > COMMENT_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Comment is too long",
							a->file.filename));
	}
	while (*line && *line != '"')
	{
		a->file.header.comment[a->file.comment_len++] = *(line++);
		if (a->file.comment_len > COMMENT_LENGTH)
			return (verbose(a, MSG_ERROR, "%s: Comment is too long",
							a->file.filename));
	}
	if (!*line)
		return (2);
	++line;
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
	{
		SET(a->file.flag, HEAD_COMMENT);
		return (0);
	}
	return (verbose(a, MSG_ERROR, "%s: Comment lexical error",
						a->file.filename));
}

static int			init_comment_header(t_asm *a, char *line)
{
	if (IS_SET(a->file.flag, HEAD_COMMENT))
	{
		return (verbose(a, MSG_ERROR, "%s: Comment is already set",
					a->file.filename));
	}
	line += 8;
	while (ft_isspa(*line))
		++line;
	if (*line != '"')
	{
		return (verbose(a, MSG_ERROR, "%s: Comment lexical error",
						a->file.filename));
	}
	return (check_header_comment(a, line + 1));
}

int					check_header(t_asm *a, char *line)
{
	if (skip_spa(&line) || ft_strchr(COMMENT_CHAR, *line))
		return (0);
	if (!(ft_strncmp(line, NAME_CMD_STRING, 5)))
		return (init_name_header(a, line));
	else if (!(ft_strncmp(line, COMMENT_CMD_STRING, 8)))
		return (init_comment_header(a, line));
	return (verbose(a, MSG_ERROR, "%s:Invalid header", a->file.filename));
}
