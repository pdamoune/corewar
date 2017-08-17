/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_wctoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:46:53 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/28 09:07:35 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"
#define NB_BIT (8 * nb_bytes)
#define MSK_B ((1 << NB_BIT) - 1)
#define MSK_ZERO (1 << (NB_BIT - 2))
#define MSK_ONE (1 << (NB_BIT - 1))

int		prf_wchar(char **wc_conv, unsigned int wc)
{
	if (MB_CUR_MAX == 1 && wc <= 0xff)
	{
		wc_conv[0][0] = wc;
		return (1);
	}
	if (wc > 0x10ffff ||
		wc > (((1 << ((MB_CUR_MAX * 8) - MB_CUR_MAX - 1)) - 1)))
		return (0);
	return (-1);
}

int		prf_wctoa(char **wc_conv, unsigned int wc)
{
	int		nb_bytes;
	int		first_bits;
	int		byte;

	nb_bytes = 1;
	byte = 0;
	prf_bzero(wc_conv[0], 5);
	if (prf_wchar(wc_conv, wc) != -1)
		return (prf_wchar(wc_conv, wc));
	while (wc >= 1 << (NB_BIT - nb_bytes - 1) && wc >= 0x80)
	{
		wc = ((((wc << 2) & ~MSK_B) | (wc & MSK_B)) & ~MSK_ZERO) | MSK_ONE;
		nb_bytes++;
	}
	first_bits = NB_BIT - 1;
	byte = MB_CUR_MAX < nb_bytes ? MB_CUR_MAX : nb_bytes;
	nb_bytes = 0;
	while (byte-- != 0)
	{
		wc_conv[0][byte] = wc < 0x80 ? wc : (((wc |= 1 << first_bits--)
		& (0xff << NB_BIT)) >> NB_BIT);
		nb_bytes++;
	}
	return (1);
}
