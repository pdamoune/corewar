/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:50:34 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/16 11:48:53 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

char			**ft_keep_first(char **tab2)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**tab3;

	if (!tab2)
		return (NULL);
	i = 1;
	len = 0;
	while (tab2[i])
		len += ft_strlen(tab2[i++]);
	if (!(tab3 = (char**)malloc(sizeof(*tab3) * (2 + 1))))
		return (NULL);
	tab3[0] = ft_strdup(tab2[0]);
	if (!(tab3[1] = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 1;
	j = 0;
	while (tab2[i])
	{
		k = 0;
		while (tab2[i][k])
			tab3[1][j++] = tab2[i][k++];
		i++;
	}
	ft_free_tab(tab2);
	tab3[1][j] = '\0';
	tab3[2] = NULL;
	return (tab3);
}

char			**ft_split_tab(char **tab1)
{
	char	**tab2;
	char	**tab3;
	char	**tab;
	int		i;
	int		j;
	int		len;

	if (!tab1)
		return (NULL);
	tab2 = ft_strsplit_spa(tab1[0]);
	if (!tab2)
		return (tab1);
	tab3 = ft_keep_first(tab2);
	if (!tab3)
		return (tab1);
	len = ft_strlen_tab(tab3) + ft_strlen_tab(tab1);
	if (!(tab = (char**)malloc(sizeof(*tab) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (tab3[j])
		tab[i++] = ft_strdup(tab3[j++]);
	j = 1;
	while (tab1[j])
		tab[i++] = ft_strdup(tab1[j++]);
	tab[i] = NULL;
	ft_free_tab(tab1);
	ft_free_tab(tab3);
	return (tab);
}
