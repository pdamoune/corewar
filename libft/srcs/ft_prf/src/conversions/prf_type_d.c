/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 23:44:08 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/19 02:31:23 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_flag_d(char **nbr, int *len)
{
	FLAG &= FOUR_FLAG;
	nbr[0][0] == '-' ? (FLAG |= NEGATIVE) && (*nbr)++ : 0;
	nbr[0][0] == '0' && FLAG_PRECISION && !PRECI ? (*nbr)++ && WIDTH++ : 0;
	FLAG_NEGATIVE ? FLAG &= NEG_FLAG : 0;
	FLAG_PLUS ? FLAG &= ~SPACE : 0;
	FLAG_SIGN ? FLAG |= HASHTAG : 0;
	FLAG_MINUS ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION && !PRECI ? FLAG &= ~PRECISION : 0;
	!FLAG_PRECISION ? PRECI = *len : 0;
	WIDTH < *len ? WIDTH = *len : 0;
	PRECI < *len ? PRECI = *len : 0;
	FLAG_SIGN ? WIDTH -= 1 : 0;
	PRECI > WIDTH ? WIDTH = PRECI : 0;
}

void	prf_type_d(void)
{
	t_data	data;
	char	nbr[21];
	char	*ptr;
	int		len;

	prf_bzero(nbr, 21);
	ptr = nbr;
	TYPE == 'D' ? (FLAG |= MODIFIER) && (MOD |= LONG) : 0;
	prf_set_arg(&data, 's');
	prf_lltoa_base(ptr, data.si, 10);
	len = data.si < 0 ? prf_strlen(ptr) - 1 : prf_strlen(ptr);
	prf_set_flag_d(&ptr, &len);
	prf_set_padding(&ptr, len);
	prf_fill_data(&ptr, len);
}
