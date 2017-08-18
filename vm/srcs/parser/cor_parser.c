/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:29:53 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/18 16:51:05 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"vm.h"

int		cor_parser(char *champion1)
{
	int		fd;
	char	line[65];
	t_ld	*data;

	ft_bzero(&line, 65);
	fd = open(champion1, O_RDONLY);
	while (read(fd, line, 16))
		ft_ld_pushback(&data, line);
	while (data)
	{
		int i = 0;
		while (i < 64)
		{
			ft_printf("%x ", ((long)(data->content))[i]);
			i += 8;
		}

		// write(1, line, 64);
		write(1, "\n", 1);
		data = data->next;
	}
	return (0);
}
