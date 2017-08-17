/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_fill_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:44:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/28 09:03:04 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

int		prf_fill_wchar(int data)
{
	char	wc[5];
	char	*ptr2;

	ptr2 = wc;
	if (data > 0x7f || (data <= 0xff && MB_CUR_MAX == 1))
	{
		ptr2 = wc;
		if (!prf_wctoa((char **)&ptr2, data))
			return (0);
		if ((int)prf_strlen(wc) <= PRECI)
			prf_fill_data(&ptr2, 4);
	}
	else
		prf_fill_c(data);
	return (1);
}
