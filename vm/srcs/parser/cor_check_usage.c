/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_check_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:39:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 13:26:43 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_usage	g_usg[] =
{
	{"-a"},
	{"-d"},
	{"-s"},
	{"-v"},
	{"-n"},
	{"--stealth"},
	{""}
};

int		cor_check_usage(int ac, char **av)
{
	TITLE
	int i;
	int j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		while (g_usg[i].name[0])
		{
			if (!ft_strcmp(g_usg[i].name, av[j]))
			{
				ft_printf("--> function %s\n", g_usg[i].name);
				break ;
			}
			i++;
		}
		if (!g_usg[i].name[0])
			break ;
		i = (j++ & 0);
	}
	if (j == ac)
		ft_printf("pas de champions\n"), exit (-1);
	E_TITLE
	return (j);
}
