/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:08:29 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/23 16:33:30 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		ft_initialize_map(t_map **map, char *str)
{
	if (!(*map = (t_map*)malloc(sizeof(t_map))))
		return ;
	(*map)->line = ft_strdup(str);
	(*map)->next = NULL;
	(*map)->previous = NULL;
}

/*
**  STOCKE CHAQUE LINE DANS LA STRUCT MAP
*/

void		ft_stock_map(t_global *global, char *line)
{
	t_map	*new;
	t_map	*previous;

	new = NULL;
	previous = NULL;
	ft_initialize_map(&new, line);
	if (!global->begin_map)
		global->begin_map = new;
	else
	{
		previous = global->s_map;
		new->previous = previous;
		previous->next = new;
	}
	global->s_map = new;
}
