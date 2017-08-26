/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_set_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 17:55:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/19 03:12:38 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"
#include "stdio.h"

void	prf_set_arg_unsigned(t_data *data)
{
	if (!FLAG_MODIFIER)
	{
		data->ui = (unsigned int)va_arg(AP, unsigned int);
		return ;
	}
	MOD_K && TYPE == 'b' ? MOD = __MAX : 0;
	MOD_K && TYPE == 'b' ? data->vui = (__uint128_t)va_arg(AP, __uint128_t) : 0;
	MOD_J ? MOD = MAX_T : 0;
	MOD_J ? data->ui = (uintmax_t)va_arg(AP, uintmax_t) : 0;
	MOD_Z ? MOD = SIZE_T : 0;
	MOD_Z ? data->ui = (size_t)va_arg(AP, size_t) : 0;
	MOD_LL ? MOD = MOD_LL : 0;
	MOD_LL ? data->ui = (unsigned long long)va_arg(AP, unsigned long long) : 0;
	MOD_L ? MOD = MOD_L : 0;
	MOD_L ? data->ui = (unsigned long)va_arg(AP, unsigned long) : 0;
	MOD_H ? MOD = MOD_H : 0;
	MOD_H ? data->ui = (unsigned short)va_arg(AP, unsigned int) : 0;
	MOD_HH ? MOD = MOD_HH : 0;
	MOD_HH ? data->ui = (unsigned char)va_arg(AP, unsigned int) : 0;
}

void	prf_set_arg_signed(t_data *data)
{
	if (!FLAG_MODIFIER)
	{
		data->si = (int)va_arg(AP, int);
		return ;
	}
	MOD_J ? MOD = MAX_T : 0;
	MOD_J ? data->si = (intmax_t)va_arg(AP, intmax_t) : 0;
	MOD_Z ? MOD = SIZE_T : 0;
	MOD_Z ? data->si = (ssize_t)va_arg(AP, ssize_t) : 0;
	MOD_LL ? MOD = LONG_LONG : 0;
	MOD_LL ? data->si = (long long)va_arg(AP, long long) : 0;
	MOD_L ? MOD = LONG : 0;
	MOD_L ? data->si = (long)va_arg(AP, long) : 0;
	MOD_H ? MOD = SHORT : 0;
	MOD_H ? data->si = (short)va_arg(AP, int) : 0;
	MOD_HH ? MOD = CHAR : 0;
	MOD_HH ? data->si = (char)va_arg(AP, int) : 0;
}

void	prf_set_arg(t_data *data, int c)
{
	c == 's' ? prf_set_arg_signed(data) : 0;
	c == 'u' ? prf_set_arg_unsigned(data) : 0;
}
