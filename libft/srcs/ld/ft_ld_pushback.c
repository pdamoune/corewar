/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_pushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:59:38 by wescande          #+#    #+#             */
/*   Updated: 2017/08/21 18:21:05 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ld_pushback(t_ld **alst, void *content)
{
	t_ld	*new;
	t_ld	*back;

	if (!alst || !*alst)
		return (ft_ld_new(alst, content));
	if ((new = (t_ld *)malloc(sizeof(t_ld))))
	{
		back = ft_ld_back(*alst);
		new->prev = back;
		new->next = NULL;
		new->content = content;
		back->next = new;
	}
}
