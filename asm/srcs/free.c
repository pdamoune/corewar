/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:55:30 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/24 14:56:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		ft_free_global(t_global *global)
{
	ft_tabdel(&global->index_tab);
	ft_free_labels(global);
	ft_free_map(global);
	/* free(global); */
}

void		ft_free_map(t_global *global)
{
	t_map	*tmp;

	if (global->begin_map)
		global->s_map = global->begin_map;
	while (global->s_map != NULL)
	{
		ft_strdel(&global->s_map->line);
		tmp = global->s_map->next;
		free(global->s_map);
		global->s_map = tmp;
	}
	global->begin_map = NULL;
}

void		ft_free_labels(t_global *global)
{
	t_label	*tmp;

	if (global->begin_label)
		global->s_label = global->begin_label;
	while (global->s_label)
	{
		ft_free_content(global);
		ft_strdel(&global->s_label->name);
		tmp = global->s_label->next;
		free(global->s_label);
		global->s_label = tmp;
	}
	global->begin_label = NULL;
}

void		ft_free_content(t_global *global)
{
	t_content	*tmp;

	global->s_label->s_content = global->s_label->begin_content;
	while (global->s_label->s_content)
	{
		if (global->s_label->s_content->line)
			ft_tabdel(&global->s_label->s_content->line);
		ft_strdel(&global->s_label->s_content->instruction);
		tmp = global->s_label->s_content->next;
		free(global->s_label->s_content);
		global->s_label->s_content = tmp;
	}
	global->s_label->begin_content = NULL;
}
