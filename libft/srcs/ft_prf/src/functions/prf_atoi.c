/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:37:55 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/28 09:03:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

/*
** Converts the initial portion of the string pointed to by str to int.
*/

int		prf_atoi(const char *str)
{
	int		n;
	int		s;
	int		strnb;

	n = 0;
	s = 0;
	strnb = 0;
	while (prf_isspace(str[n]) == 1)
		n++;
	if (str[n] == '-')
		s = 1;
	if (str[n] == '+' || str[n] == '-')
		n++;
	while (prf_isdigit(str[n]) == 1)
		strnb = (strnb * 10) + (str[n++] - '0');
	if (s == 1)
		return (-strnb);
	return (strnb);
}
