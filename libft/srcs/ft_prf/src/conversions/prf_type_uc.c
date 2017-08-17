/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_uc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 20:51:58 by philippe          #+#    #+#             */
/*   Updated: 2017/05/05 17:35:52 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"
#define NB_BIT (8 * nb_bytes)
#define MSK_B ((1 << NB_BIT) - 1)
#define MSK_ZERO (1 << (NB_BIT - 2))
#define MSK_ONE (1 << (NB_BIT - 1))

void	prf_set_flag_uc(void)
{
	FLAG &= TWO_FLAG;
	TYPE = 'C';
	FLAG &= ~PRECISION;
	PRECI = 0;
}

int		prf_type_uc(void)
{
	t_data	data;
	char	wc[5];
	char	*ptr;
	int		len;

	prf_bzero(wc, 5);
	ptr = wc;
	data.ui = (int)va_arg(AP, wchar_t);
	if (!prf_wctoa(&ptr, data.ui))
		return (0);
	len = data.ui == 0 ? 1 : prf_strlen(ptr);
	if (FLAG_PRECISION && PRECI < len)
		PRECI = len;
	FLAG_MINUS && !ptr[0] ? J++ : 0;
	prf_set_flag_uc();
	WIDTH > len ? prf_set_padding(&ptr, len) : 0;
	!FLAG_MINUS && !wc[0] ? J++ : prf_fill_data(&ptr, len);
	return (1);
}
