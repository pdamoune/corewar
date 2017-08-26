/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_strlen_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:19:07 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/26 19:51:05 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

size_t	prf_strlen_wchar(int *str)
{
	int		i;
	size_t	error;
	size_t	ret;

	i = 0;
	ret = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		error = ret++;
		str[i] > 0x7f ? ret++ : 0;
		str[i] > 0x7ff ? ret++ : 0;
		str[i] > 0xffff ? ret++ : 0;
		if ((int)ret > PRECI && FLAG_PRECISION)
			return (error);
		i++;
	}
	return (ret);
}
