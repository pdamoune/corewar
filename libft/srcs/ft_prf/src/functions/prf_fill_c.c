/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_fill_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanie13 <fanie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:18:39 by fanie13           #+#    #+#             */
/*   Updated: 2017/08/10 21:38:11 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_fill_c(int c)
{
	FLAG_BINARY && !(WIDTH % 8) && FLAG_BIN_HGT ? BUFFER[J++] = ' ' : 0;
	FLAG_BIN_SP ? BUFFER[J++] = ' ' : 0;
	BUFFER[J] = c;
	J++;
	WIDTH && WIDTH == PRECI ? PRECI-- : 0;
	WIDTH ? WIDTH-- : 0;
	if (J == SIZE_BUF)
	{
		RET += J;
		write(FD, BUFFER, J);
		prf_bzero(BUFFER, SIZE_BUF);
		J = 0;
	}
}
