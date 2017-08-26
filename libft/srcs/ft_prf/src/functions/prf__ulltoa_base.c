/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf__ulltoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:22:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/19 03:38:19 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf__ulltoa_base(char *result, __uint128_t n, unsigned int base)
{
	__uint128_t		len;
	__uint128_t		mod;

	len = 0;
	result[len] = '0';
	while (n > 0)
	{
		mod = n % base;
		mod = ABS(mod);
		result[len] = mod + '0';
		if (base >= 10)
			if (!prf_isdigit(result[len]))
				result[len] += 39;
		n /= base;
		len++;
	}
	prf_strrev(result);
}
