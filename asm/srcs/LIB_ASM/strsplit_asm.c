/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:50:34 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:50:35 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char			**ft_copy_tab_2(char **tab3, char **tab2)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	while (tab2[i])
	{
		k = 0;
		while (tab2[i][k])
			tab3[1][j++] = tab2[i][k++];
		i++;
	}
	tab3[1][j] = '\0';
	tab3[2] = NULL;
	return (tab3);
}

static char			**ft_copy_tab_1_and_3(char **tab3, char **tab1, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab3[j])
		tab[i++] = ft_strdup(tab3[j++]);
	j = 1;
	while (tab1[j])
		tab[i++] = ft_strdup(tab1[j++]);
	tab[i] = NULL;
	return (tab);
}

char				**ft_keep_first(char **tab2)
{
	int		i;
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
	tab3 = ft_copy_tab_2(tab3, tab2);
	return (tab3);
}

char				**ft_split_tab(char **tab1)
{
	char	**tab2;
	char	**tab3;
	char	**tab;
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
	tab = ft_copy_tab_1_and_3(tab3, tab1, tab);
	ft_tabdel(&tab2);
	ft_tabdel(&tab3);
	return (tab);
}
