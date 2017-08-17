/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 01:50:54 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/05 17:36:09 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_flag_o(char **nbr, int *len)
{
	FLAG &= THREE_FLAG;
	FLAG |= OCTAL;
	nbr[0][0] == '0' && FLAG_PRECISION && !PRECI && !FLAG_HASHTAG ?
	(*nbr)++ && WIDTH++ : 0;
	nbr[0][0] == '0' ? FLAG &= ~HASHTAG : 0;
	FLAG_MINUS ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION && !PRECI ? FLAG &= ~PRECISION : 0;
	!FLAG_PRECISION ? PRECI = *len : 0;
	WIDTH < *len ? WIDTH = *len : 0;
	PRECI < *len ? PRECI = *len : 0;
	PRECI > *len ? FLAG &= ~HASHTAG : 0;
	PRECI > WIDTH ? WIDTH = PRECI : 0;
	FLAG_HASHTAG ? WIDTH -= 1 : 0;
}

void	prf_type_o(void)
{
	t_data	data;
	char	nbr[25];
	char	*ptr;
	int		len;

	prf_bzero(nbr, 25);
	ptr = nbr;
	TYPE == 'O' ? (FLAG |= MODIFIER) && (MOD |= LONG) : 0;
	prf_set_arg(&data, 'u');
	prf_ulltoa_base(ptr, data.ui, 8);
	len = prf_strlen(ptr);
	prf_set_flag_o(&ptr, &len);
	prf_set_padding(&ptr, len);
	prf_fill_data(&ptr, len);
}
