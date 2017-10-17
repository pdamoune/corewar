/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:35:15 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/17 16:06:45 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

int		go_to_label(char *label, t_global *global)
{
	t_label		*tmp;
	int			begin_octet;
	int			label_octet;
	int			stop;

	tmp = global->s_label;
	stop = 0;
	begin_octet = global->s_label->s_content->begin_octet;
	label_octet = 0;
	global->s_label = global->begin_label;
	while (global->s_label && !stop)
	{
		if (!ft_strcmp(label, global->s_label->name))
		{
			stop = 1;
			label_octet = global->s_label->begin_content->begin_octet;
		}
		global->s_label = global->s_label->next;
	}
	global->s_label = tmp;
	if (stop)
		return (label_octet - begin_octet);
	else
		ft_exit(15, global, NULL);
	return (0);
}
