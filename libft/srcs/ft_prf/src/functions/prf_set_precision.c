/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_set_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 22:43:51 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/25 16:55:37 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_precision(int len, int c)
{
	if (WIDTH >= PRECI)
	{
		prf_fill_c(c);
		return ;
	}
	while (--PRECI > len)
		prf_fill_c('0');
	FLAG &= ~PRECISION;
}
