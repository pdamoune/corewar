/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:59:16 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/04 18:54:50 by tdebarge         ###   ########.fr       */
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
