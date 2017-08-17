/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_us.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 22:57:34 by philippe          #+#    #+#             */
/*   Updated: 2017/05/05 17:35:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

int		prf_data_null(t_data *data)
{
	int len;

	!data->ptr ? data->ptr = "(null)" : 0;
	len = 6;
	FLAG &= TWO_FLAG;
	FLAG_PRECISION && (PRECI < len) ? len = PRECI : 0;
	FLAG_PRECISION && PRECI ? FLAG &= ~PRECISION : 0;
	if (WIDTH <= len)
	{
		prf_fill_data((char **)&data->ptr, len);
		return (1);
	}
	prf_set_padding((char **)&data->ptr, len);
	prf_fill_data((char **)&data->ptr, len);
	return (1);
}

void	prf_setus(int *len)
{
	FLAG &= TWO_FLAG;
	TYPE = 'S';
	WIDTH < *len ? WIDTH = *len : 0;
	!PRECI ? PRECI = WIDTH : 0;
	FLAG_PRECISION && *len < PRECI ? PRECI = *len : 0;
	FLAG &= ~PRECISION;
}

int		prf_type_us(void)
{
	t_data	data;
	int		*ptr;
	int		len;
	int		i;

	i = -1;
	data.ptr = va_arg(AP, wchar_t *);
	if (!data.ptr)
		return (prf_data_null(&data));
	ptr = data.ptr;
	(len = prf_strlen_wchar(ptr)) ? prf_setus(&len) : prf_setus(&len);
	if ((WIDTH <= len && len) || FLAG_MINUS)
	{
		while (ptr[++i] && PRECI)
			if (!prf_fill_wchar(ptr[i]))
				return (0);
		if (!FLAG_MINUS)
			return (1);
	}
	prf_set_padding((char **)&data.ptr, len);
	while (ptr[++i] && PRECI)
		if (!prf_fill_wchar(ptr[i]))
			return (0);
	return (1);
}
