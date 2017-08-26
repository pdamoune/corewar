/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_strtoupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 23:01:33 by philippe          #+#    #+#             */
/*   Updated: 2017/04/28 09:01:36 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

/*
** Converts the letter c to upper case, if possible.
*/

void	prf_strtoupper(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = prf_toupper(str[i]);
}
