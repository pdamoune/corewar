/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:29:53 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 14:47:09 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cor_parser(t_champions *champion1, int ac, char **av)
{
	int		index;

	index = cor_check_usage(ac, av);
	cor_check_champions(ac, av, index);
	(void)&champion1;
	return (0);
}
