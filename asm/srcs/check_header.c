/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:23:09 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 18:58:31 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			check_header_name(t_asm *a, char *line)
{
	if (*a->file.header.prog_name)
		if (ft_strcat_check(a->file.header.prog_name,
				"\n", &a->file.name_len, PROG_NAME_LENGTH))
			return (verbose(a, MSG_ERROR, "Name is too long", NULL));
	while (*line && *line != '"')
	{
		a->file.header.prog_name[a->file.name_len++] = *(line++);
		if (a->file.name_len > PROG_NAME_LENGTH)
			return (verbose(a, MSG_ERROR, "Name is too long", NULL));
	}
	if (!*line)
		return (2);
	++line;
	while (ft_isspa(*line))
		++line;
	return (*line ? -1 : 0);
}

int			check_header_comment(t_asm *a, char *line)
{
	if (*a->file.header.comment)
		if (ft_strcat_check(a->file.header.comment,
				"\n", &a->file.comment_len, COMMENT_LENGTH))
			return (verbose(a, MSG_ERROR, "Comment is too long", NULL));
	while (*line && *line != '"')
	{
		a->file.header.comment[a->file.comment_len++] = *(line++);
		if (a->file.comment_len > COMMENT_LENGTH)
			return (verbose(a, MSG_ERROR, "Comment is too long", NULL));
	}
	if (!*line)
		return (3);
	++line;
	while (ft_isspa(*line))
		++line;
	return (*line ? -1 : 0);
}

static int			init_name_header(t_asm *a, char *line)
{
	if (IS_SET(a->file.flag, HEAD_NAME))
		return (verbose(a, MSG_ERROR, "Name is already set", NULL));
	SET(a->file.flag, HEAD_NAME);
	line += 5;
	while (ft_isspa(*line))
		++line;
	if (*line != '"')
		return (verbose(a, MSG_ERROR, "Name lexical error", NULL));
	return (check_header_name(a, line + 1));
}

static int			init_comment_header(t_asm *a, char *line)
{
	if (IS_SET(a->file.flag, HEAD_COMMENT))
		return (verbose(a, MSG_ERROR, "Comment is already set", NULL));
	SET(a->file.flag, HEAD_COMMENT);
	line += 8;
	while (ft_isspa(*line))
		++line;
	if (*line != '"')
		return (verbose(a, MSG_ERROR, "Comment lexical error", NULL));
	return (check_header_comment(a, line + 1));
}

int					check_header(t_asm *a, char *line)
{
	while (ft_isspa(*line))
		++line;
	if (!*line || ft_strchr(COMMENT_CHAR, *line))
		return (1);
	if (ft_isspa(ft_strcmp(line, NAME_CMD_STRING)))
		return (init_name_header(a, line));
	else if (ft_isspa(ft_strcmp(line, COMMENT_CMD_STRING)))
		return (init_comment_header(a, line));
	else
		return (verbose(a, MSG_ERROR, "Invalid header", NULL));
	return (1);
}
