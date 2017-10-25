/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:55:30 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:23 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		ft_free_global(t_global *global)
{
	/* ft_tabdel(&global->index_tab); */
	ft_free_labels(global);
	/* free(global); */
}

void		ft_free_map(t_global *global)
{
	t_map	*tmp;

	if (global->begin_map)
		global->s_map = global->begin_map;
	while (global->s_map != NULL)
	{
		free(global->s_map->line);
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

	G_L_C = global->s_label->begin_content;
	while (G_L_C)
	{
		if (G_L_C->line)
			ft_tabdel(&G_L_C->line);
		ft_strdel(&G_L_C->instruction);
		tmp = G_L_C->next;
		free(G_L_C);
		G_L_C = tmp;
	}
	global->s_label->begin_content = NULL;
}
