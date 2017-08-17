/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 01:17:09 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/05 17:36:02 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_flag_s(int *len)
{
	FLAG &= TWO_FLAG;
	FLAG_PRECISION && (PRECI < *len) ? *len = PRECI : 0;
	FLAG_PRECISION && PRECI ? FLAG &= ~PRECISION : 0;
}

void	prf_type_s(void)
{
	t_data	data;
	int		len;

	data.ptr = (char *)va_arg(AP, char *);
	!data.ptr ? data.ptr = "(null)" : 0;
	len = prf_strlen(data.ptr);
	prf_set_flag_s(&len);
	if (WIDTH <= len)
	{
		prf_fill_data((char **)&data.ptr, len);
		return ;
	}
	prf_set_padding((char **)&data.ptr, len);
	prf_fill_data((char **)&data.ptr, len);
}
