/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:29:53 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/21 18:47:37 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"vm.h"

int		cor_parser(char *champion1)
{
	int		fd;
	char	line[65];
	t_ld	*data;

	data = NULL;
	ft_bzero(&line, 65);
	fd = open(champion1, O_RDONLY);
	// int i = 0;
	read(fd, line, 32);
	int i = 0;
	while (i < 32)
	{
		ft_printf("%.2x ", line[i++] & 0xff);
	}
		write(1, "\n", 1);
		data = data->next;
	return (0);
}
