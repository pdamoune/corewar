/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/02 19:07:01 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_ld			**find_label(t_ld **head_list, char *name)
{
	*head_list = ft_ld_front(*head_list);
	while (1)
	{
		if (!ft_strcmp(((t_label *)(*head_list)->content)->label, name))
			break ;
		if (!(*head_list)->next)
			return (NULL);
		*head_list = (*head_list)->next;
	}
	return (head_list);
}

void			replace_label(t_asm *a, unsigned int pos, t_ld **target)
{
	(void)a;
	(void)pos;
	remove_label(target);
}

int					check_label(t_asm *a)
{
	return(0);
	(void)a;
	//TODO function check
}
