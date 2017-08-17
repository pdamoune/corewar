/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/17 19:09:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		usage(void)
{
	char	hashtag[81];

	ft_memset(hashtag, '#', 80);
	hashtag[80] = 0;
	ft_prf("Usage:  [-d N -s N -v N | -b --stealth | -n --stealth] \
	[-a] <champion1.cor> <...>\n");
	ft_prf("%5c-a%8c: ", 0, 0);
	ft_prf("Prints output from \"aff\" (Default is to hide it)\n", 0, 0);
	ft_prf("%.4s TEXT OUTPUT MODE %.58s\n", hashtag, hashtag);
	return (0);
}
