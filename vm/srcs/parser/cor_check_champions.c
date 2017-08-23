/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_check_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:29:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 13:33:04 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cor_check_champions(int ac, char **av, int index)
{
	TITLE

	DG("\nac = %d\nindex = %d\nav[index] = %s", ac, index, av[index]);
	(void)&ac;
	(void)&av;
	(void)&index;

	E_TITLE
	return (1);
}
