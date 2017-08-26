/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_set_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:25:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/28 09:06:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_prf.h"

void	prf_test_preci(int len, int *c, char **data)
{
	FLAG_HASHTAG ? prf_set_prefixe() : 0;
	*c = (WIDTH <= PRECI) ? '0' : ' ';
	while (PRECI - len > 0)
	{
		prf_fill_c(*c);
		PRECI != WIDTH ? PRECI-- : 0;
	}
	data[0][0] == 0 ? WIDTH++ : 0;
	FLAG &= ~PRECISION;
	FLAG &= ~SIGN_FLAG;
}

void	prf_flag_minus(int len, int *c, char **data)
{
	FLAG_HASHTAG ? prf_set_prefixe() : 0;
	if (FLAG_PRECISION)
		while (PRECI > len)
		{
			*c = FLAG_PRECISION ? '0' : ' ';
			FLAG_PRECISION && (WIDTH <= PRECI) ?
			prf_test_preci(len, c, data) : prf_fill_c(*c);
			PRECI--;
		}
	TYPE != 'S' ? prf_fill_data(data, len) : 0;
	while (WIDTH > 0)
		prf_fill_c(' ');
}

void	prf_set_padding(char **data, int len)
{
	int c;

	c = FLAG_ZERO ? '0' : ' ';
	if (FLAG_MINUS)
	{
		prf_flag_minus(len, &c, data);
		return ;
	}
	if (!FLAG_MINUS)
		if (!FLAG_ZERO)
			while (WIDTH - len > 0)
				FLAG_PRECISION && (WIDTH <= PRECI) ?
				prf_test_preci(len, &c, data) : prf_fill_c(c);
	(FLAG_HASHTAG) || (SIGN_FLAG & FLAG) ? prf_set_prefixe() : 0;
	while (WIDTH - len > 0 && WIDTH > 0)
		FLAG_PRECISION && (WIDTH <= PRECI) ?
		prf_test_preci(len, &c, data) : prf_fill_c(c);
	FLAG_HASHTAG ? prf_set_prefixe() : 0;
	TYPE != 'S' ? prf_fill_data(data, len) : 0;
}
