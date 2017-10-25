/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:26:43 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 14:39:33 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

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
}
