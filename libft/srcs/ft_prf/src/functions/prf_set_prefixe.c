/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_set_prefixe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanie13 <fanie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:17:29 by fanie13           #+#    #+#             */
/*   Updated: 2017/04/26 05:19:29 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_prefixe(void)
{
	(FLAG & SIGN_FLAG) || FLAG_OCTAL ? WIDTH++ : 0;
	FLAG_BINARY || FLAG_HEXA ? WIDTH += 2 : 0;
	FLAG_SPACE ? prf_fill_c(' ') : 0;
	FLAG_PLUS ? prf_fill_c('+') : 0;
	FLAG_NEGATIVE ? prf_fill_c('-') : 0;
	FLAG_OCTAL ? prf_fill_c('0') : 0;
	FLAG_BINARY ? prf_set_x("0b") : 0;
	FLAG_HEXA ? prf_set_x("0x") : 0;
	FLAG &= ~HASHTAG;
}
