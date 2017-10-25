/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 16:56:46 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 14:47:51 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
**  IDENTIFIE LE TYPE DE LIGNES
** 1) ligne vide - EMPTY_LINE
** 2) ligne de commentaire - COMMENT
** 3) instruction avec LABEL_CHAR - WITH_LABEL
** 4) instruction sans LABEL_CHAR ou autre - EMPTY_LABEL
** 5) instruction de header - HEADER
*/

int				ft_kind_of_line(t_global *global, char *line)
{
	int		i;

	i = 0;
	if (line[i] == '\n' || line[i] == '\0')
		return (EMPTY_LINE);
	else if (ft_strchr(COMMENT_CHAR, line[i]))
		return (COMMENT);
	else if (ft_strstart(line, NAME_CMD_STRING)
			|| ft_strstart(line, COMMENT_CMD_STRING))
		return (HEADER);
	else if (ft_strstart(line, "."))
		ft_exit(15, global, &line);
	while (line[i++])
	{
		while (is_labelchars(line[i]))
			i++;
		if (line[i] == LABEL_CHAR)
			return (WITH_LABEL);
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
			i++;
		return (EMPTY_LABEL);
	}
	return (0);
}

static int		ft_follow_lab(t_global *global, int k)
{
	int			i;

	i = 0;
	while (global->s_map->line[i + k])
	{
		if (ft_isspa(global->s_map->line[i + k]))
			i++;
		else if (ft_strchr(COMMENT_CHAR, global->s_map->line[i + k]))
		{
			global->s_map = global->s_map->next;
			return (1);
		}
		else
			return (0);
	}
	if (global->s_map->next)
		global->s_map = global->s_map->next;
	return (1);
}

void			ft_with_label(t_global *global)
{
	int			i;

	i = ft_strsubc_nb(global->s_map->line, LABEL_CHAR);
	global->s_label->name = ft_strndup((global->s_map->line), i);
	if (!ft_follow_lab(global, i + 1))
		ft_stock_content(global, global->s_map->line + i + 1);
	else if (!global->s_map->line || ft_strchr(global->s_map->line, ':'))
	{
		ft_stock_content(global, NULL);
		if (global->s_map->next)
			global->s_map = global->s_map->previous;
	}
	else
		ft_stock_content(global, global->s_map->line);
	if ((global->i = 1) && global->s_map)
		global->s_map = global->s_map->next;
	while (global->s_map
		&& ft_kind_of_line(global, global->s_map->line) == EMPTY_LABEL)
	{
		ft_stock_content(global, global->s_map->line);
		global->i++;
		global->s_map = global->s_map->next;
	}
	if (global->s_map)
		global->s_map = global->s_map->previous;
}

/*
**  STOCK LES DONNEES DANS UNE STRUCTURE LABEL
*/

static void		ft_sort_lines(t_global *global, char *comment_line)
{
	if (ft_kind_of_line(global, global->s_map->line) == COMMENT)
	{
		ft_stock_content(global, global->s_map->line);
		global->s_label->name = ft_strdup("COMMENTS");
	}
	else if (ft_kind_of_line(global, global->s_map->line) == HEADER)
	{
		ft_comment_is_done(global, comment_line);
		ft_stock_content(global, comment_line);
		global->s_label->name = ft_strdup("HEADER");
	}
	else if (ft_kind_of_line(global, global->s_map->line) == EMPTY_LABEL)
	{
		ft_stock_content(global, global->s_map->line);
		global->s_label->name = ft_strjoinf(ft_itoa(global->j++), "_EMPTY", 1);
	}
	else if (ft_kind_of_line(global, global->s_map->line) == WITH_LABEL)
		ft_with_label(global);
	else
		return ;
	ft_stock_label(global);
}

void			ft_parse_label(t_global *global)
{
	char	comment_line[COMMENT_LENGTH + 256];

	global->j = 0;
	ft_stock_label(global);
	global->s_map = global->begin_map;
	while (global->s_map && ft_kind_of_line(global, global->s_map->line)
			== COMMENT)
		global->s_map = global->s_map->next;
	while (global->s_map)
	{
		while (global->s_map && ft_kind_of_line(global, global->s_map->line)
			== EMPTY_LINE)
			global->s_map = global->s_map->next;
		if (global->s_map)
			ft_sort_lines(global, comment_line);
		if (global->s_map)
			global->s_map = global->s_map->next;
	}
}
