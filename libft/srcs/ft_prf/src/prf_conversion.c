/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:38:51 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/15 17:43:40 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_prf.h"

/*
** the b conversion is binary conversion of the argument
** the @ conversion is to print to a different file descriptor
** it will take the last file descriptor called
*/

t_conv		g_conv[] =
{
	{'%', &prf_type_c},
	{'c', &prf_type_c},
	{'s', &prf_type_s},
	{'b', &prf_type_b},
	{'d', &prf_type_d},
	{'D', &prf_type_d},
	{'i', &prf_type_d},
	{'p', &prf_type_x},
	{'o', &prf_type_o},
	{'O', &prf_type_o},
	{'u', &prf_type_u},
	{'U', &prf_type_u},
	{'x', &prf_type_x},
	{'X', &prf_type_x},
	{'@', 0},
	{0, &prf_type_c}
};

void	prf_conversion(void)
{
	int	i;

	i = 0;
	MOD_FD ? g_form.fd = va_arg(AP, int) : 0;
	while (TYPE != g_conv[i].id && g_conv[i].id != 0)
		i++;
	if (TYPE == 'C' || (TYPE == 'c' && MOD & MOD_L))
		!prf_type_uc() ? RET = -1 : 0;
	else if (TYPE == 'S' || (TYPE == 's' && MOD & MOD_L))
		!prf_type_us() ? RET = -1 : 0;
	else if (TYPE == '@')
		(g_form.fd = va_arg(AP, int)) == -1 ?
		(RET = -1) : 0;
	else
		(g_conv[i].fonction)();
}
