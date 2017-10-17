/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:26:43 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/17 16:06:45 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

char		**ft_index_tab(void)
{
	char	**tab;

	if (!(tab = (char **)malloc(17 * sizeof(*tab))))
		return (NULL);
	tab[0] = ft_strdup("live");
	tab[1] = ft_strdup("add");
	tab[2] = ft_strdup("sub");
	tab[3] = ft_strdup("and");
	tab[4] = ft_strdup("or");
	tab[5] = ft_strdup("xor");
	tab[6] = ft_strdup("zjmp");
	tab[7] = ft_strdup("sti");
	tab[8] = ft_strdup("st");
	tab[9] = ft_strdup("fork");
	tab[10] = ft_strdup("lldi");
	tab[11] = ft_strdup("lld");
	tab[12] = ft_strdup("ldi");
	tab[13] = ft_strdup("ld");
	tab[14] = ft_strdup("lfork");
	tab[15] = ft_strdup("aff");
	tab[16] = NULL;
	return (tab);
}

/*
**  INITIALISE LA GLOBALE UTILISEE DANS TOUT LE PROGRAMME
*/

void		ft_initialize_global(t_global **global)
{
	if (!(*global = (t_global*)malloc(sizeof(t_global))))
		return ;
	(*global)->nb_empty = 0;
	(*global)->nb_lines = 0;
	(*global)->i = 0;
	(*global)->j = 0;
	(*global)->k = 0;
	(*global)->total_octet = 0;
	(*global)->fdin = 0;
	(*global)->fdout = 0;
	(*global)->begin_map = NULL;
	(*global)->s_map = NULL;
	(*global)->begin_label = NULL;
	(*global)->s_label = NULL;
	(*global)->res_pc = 0;
	(*global)->index_tab = ft_index_tab();
}
