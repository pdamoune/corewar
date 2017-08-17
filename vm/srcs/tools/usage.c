/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/17 16:11:33 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		usage(void)
{
	ft_printf("Usage : ./corewar [-d N -s N -v N | \
	-b --stealth | -n --stealth] [-a] <champion1.cor> <...>\n");
	ft_prf("%4c-a%8c: \n", 0, 0);
	return (0);
}
