/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_isblank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:31:21 by pdamoune          #+#    #+#             */
/*   Updated: 2017/04/28 09:00:21 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

/*
** Checks for a blank character; that is, a space or a tab.
*/

int	prf_isblank(int c)
{
	return (c == 9 || c == 32);
}
