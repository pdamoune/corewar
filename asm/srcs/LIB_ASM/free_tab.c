/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:34:57 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/23 16:48:56 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

void		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i++]);
		}
		free(tab);
	}
	tab = NULL;
}
