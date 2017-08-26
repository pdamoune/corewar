/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_isspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:55:10 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/28 09:00:41 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

/*
** Checks for white-space characters. These are:
** space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
** horizontal tab ('\t'), and vertical tab ('\v').
*/

int	prf_isspace(int c)
{
	return ((c >= 10 && c <= 13) || prf_isblank(c));
}
