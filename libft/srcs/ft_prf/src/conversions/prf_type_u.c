/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 01:42:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/05 17:35:54 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_flag_u(char **nbr, int *len)
{
	FLAG &= TWO_FLAG;
	nbr[0][0] == '0' && FLAG_PRECISION && !PRECI ? (*nbr)++ && WIDTH++ : 0;
	FLAG_MINUS ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION ? FLAG &= ~ZERO : 0;
	FLAG_PRECISION && !PRECI ? FLAG &= ~PRECISION : 0;
	!FLAG_PRECISION ? PRECI = *len : 0;
	WIDTH < *len ? WIDTH = *len : 0;
	PRECI < *len ? PRECI = *len : 0;
	PRECI > WIDTH ? WIDTH = PRECI : 0;
}

void	prf_type_u(void)
{
	t_data	data;
	char	nbr[21];
	char	*ptr;
	int		len;

	prf_bzero(nbr, 21);
	ptr = nbr;
	TYPE == 'U' ? (FLAG |= MODIFIER) && (MOD |= LONG) : 0;
	prf_set_arg(&data, 'u');
	prf_ulltoa_base(ptr, data.ui, 10);
	len = prf_strlen(ptr);
	prf_set_flag_u(&ptr, &len);
	prf_set_padding(&ptr, len);
	prf_fill_data(&ptr, len);
}
