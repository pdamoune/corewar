/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 02:54:26 by philippe          #+#    #+#             */
/*   Updated: 2017/05/19 03:36:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

/*
** %b options :
** nothing	: print the 32 bits of the int fill with 0 on the left.
**
** FLAGS
** space 	: split the 4 bytes of the int with one space
** +		: print the 32 bits of the int separated with a space
** #		: add the prefix 0b before the bits
** -		: printf the first n bits
**
** MODIFIERS
** h hh l ll j z are the same than %d Conversions
** k		: convert the argument to an __uint128_t
**
** WIDTH & PRECISION
** Specify the number of bits to printf
** does nothing if the supposed number of bits to print is superior.
*/

void	prf_set_flag_b(void)
{
	FLAG_PLUS ? FLAG |= BIN_SP : 0;
	FLAG_SPACE ? FLAG |= BIN_HGT : 0;
	FLAG &= THREE_FLAG;
	FLAG |= BINARY;
	FLAG |= ZERO;
	FLAG &= ~SPACE;
	!FLAG_PRECISION ? WIDTH = 32 : 0;
	!PRECISION ? PRECI = WIDTH : 0;
	FLAG_PRECISION && WIDTH < PRECI ? WIDTH = PRECI : 0;
	FLAG_HASHTAG ? WIDTH += 2 : 0;
}

void	prf_type_b(void)
{
	t_data	data;
	char	str[130];
	char	*s;
	int		len;

	prf_bzero(str, 130);
	s = str;
	prf_set_arg(&data, 'u');
	MOD_K ? prf__ulltoa_base(s, data.vui, 2) : prf_ulltoa_base(s, data.ui, 2);
	len = prf_strlen(s);
	WIDTH < len && WIDTH ? WIDTH = len : 0;
	prf_set_flag_b();
	prf_set_padding(&s, len);
	prf_fill_data(&s, len);
}
