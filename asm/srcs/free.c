/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:55:30 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/23 16:43:01 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		ft_free_global(t_global *global)
{
	ft_free_tab(global->index_tab);
	ft_free_labels(global);
	free(global);
}

void		ft_free_map(t_global *global)
{
	t_map	*tmp;

	global->s_map = global->begin_map;
	while (global->s_map != NULL)
	{
		if (global->s_map->line != NULL)
			//ft_strdel(&global->s_map->line);
		tmp = global->s_map->next;
		free(global->s_map);
		global->s_map = tmp;
	}
}

void		ft_free_labels(t_global *global)
{
	t_label	*tmp;

	global->s_label = global->begin_label;
	while (global->s_label)
	{
		ft_free_content(global);
		free(global->s_label->name);
		tmp = global->s_label->next;
		free(global->s_label);
		global->s_label = tmp;
	}
}

void		ft_free_content(t_global *global)
{
	t_content	*tmp;

	global->s_label->s_content = global->s_label->begin_content;
	while (global->s_label->s_content)
	{
		if (global->s_label->s_content->line)
			ft_free_tab(global->s_label->s_content->line);
		free(global->s_label->s_content->instruction);
		tmp = global->s_label->s_content->next;
		free(global->s_label->s_content);
		global->s_label->s_content = tmp;
	}
}
