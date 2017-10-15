/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:24:25 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 18:25:26 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		ft_initialize_label(label_t **label)
{
	if (!(*label = (label_t*)malloc(sizeof(label_t))))
		return ;
	(*label)->begin_content = NULL;
	(*label)->s_content = NULL;
	(*label)->name = NULL;
	(*label)->num = 0;
	(*label)->index = 42;
	(*label)->next = NULL;
	(*label)->previous = NULL;
}

void		ft_stock_label(global_t *global)
{
	label_t	*new;

	new = NULL;
	ft_initialize_label(&new);
	if (!global->begin_label)
		global->begin_label = new;
	else
	{
		new->previous = global->s_label;
		global->s_label->next = new;
	}
	global->s_label = new;
	global->s_label->num = global->k++;
}
