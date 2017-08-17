/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_type_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:54:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/05 17:36:52 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_prf.h"

void	prf_set_flag_c(char *str)
{
	FLAG &= TWO_FLAG;
	!str[0] && FLAG_MINUS ? J++ && WIDTH-- : 0;
	FLAG &= ~PRECISION;
}

void	prf_type_c(void)
{
	char	str[21];
	char	*ptr;
	int		len;

	str[1] = 0;
	ptr = str;
	len = 1;
	str[0] = (TYPE == 'c' ? va_arg(AP, int) : (int)TYPE);
	prf_set_flag_c(ptr);
	prf_set_padding(&ptr, len);
	prf_fill_data(&ptr, len);
	!FLAG_MINUS && !str[0] ? J++ : 0;
}
