/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:40:17 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/05 12:28:29 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_flag_x(char **nbr, int *len)
{
	FLAG &= THREE_FLAG;
	FLAG |= HEXA;
	nbr[0][0] == '0' ? FLAG &= ~HASHTAG : 0;
	nbr[0][0] == '0' && FLAG_PRECISION && !PRECI ? (*nbr)++ && WIDTH++ : 0;
	TYPE == 'p' ? FLAG |= HASHTAG : 0;
	FLAG_MINUS ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION && !PRECI ? FLAG &= ~PRECISION : 0;
	!FLAG_PRECISION ? PRECI = *len : 0;
	!FLAG_PRECISION && FLAG_HASHTAG ? WIDTH -= 2 : 0;
	WIDTH < *len ? WIDTH = *len : 0;
	WIDTH < PRECI ? WIDTH = PRECI : 0;
	FLAG_PRECISION && FLAG_HASHTAG && PRECI < WIDTH ? WIDTH-- : 0;
	FLAG_PRECISION && FLAG_HASHTAG && PRECI < WIDTH ? WIDTH-- : 0;
}

void	prf_type_x(void)
{
	t_data	data;
	char	nbr[21];
	char	*ptr;
	int		len;

	prf_bzero(nbr, 21);
	ptr = nbr;
	TYPE == 'p' ? (FLAG |= (HASHTAG | MODIFIER)) && (MOD |= LONG) : 0;
	prf_set_arg(&data, 'u');
	prf_ulltoa_base(ptr, data.ui, 16);
	TYPE == 'X' ? prf_strtoupper(ptr) : 0;
	len = prf_strlen(ptr);
	prf_set_flag_x(&ptr, &len);
	prf_set_padding(&ptr, len);
	prf_fill_data(&ptr, len);
}
