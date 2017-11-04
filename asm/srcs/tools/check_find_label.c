/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/04 02:02:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_ld			**find_label(t_ld **head_list, char *name)
{
	if (!*head_list)
		return (NULL);
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

int					check_label(t_asm *a)
{
	return(0);
	(void)a;
	//TODO function check
}
