/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_check_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:29:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 17:47:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*ft_intrev(unsigned int *i)
{
	int		n;
	int		m;
	char	*str;
	char	rev;

	str = (char *)i;
	m = 3;
	n = 0;
	while (n < m)
	{
		rev = str[m];
		str[m] = str[n];
		str[n] = rev;
		n++;
		m--;
	}
	return (str);
}

#include <stdio.h>

int		cor_check_champions(int ac, char **av, int index)
{
	TITLE
	int 		fd;
	header_t	header;

	ft_bzero(&header, sizeof(header_t));
	if ((fd = open(av[index], O_RDONLY)) == -1)
		DG("\nBad champion file : fd = %d\n", fd), exit (-1);

	DG("\nac = %d | index = %d | av[index] = %s\n", ac, index, av[index]);

	ft_printf("  ret = %5d | ", read(fd, &header.magic, 4));
	ft_printf("magic     = %x \n", header.magic);
	// ft_printf("magic = %x\n", header.magic);

	ft_printf("  ret = %5d | ", read(fd, &header.prog_name, PROG_NAME_LENGTH + 4));
	ft_printf("name      : %.10s(...)\n", header.prog_name);

	ft_printf("  ret = %5d | ", read(fd, &header.prog_size, 4));
	ft_printf("prog_size = %x\n", header.prog_size);
	// ft_printf("prog_size = %d\n", header.prog_size);

	ft_printf("  ret = %5d | ", read(fd, &header.comment, COMMENT_LENGTH + 4));
	ft_printf("comment   : %.10s(...)\n\n", header.comment);

	ft_intrev(&header.magic);
	ft_intrev(&header.prog_size);

	ft_printf("  ret = %5x | retour CHAMP_MAX_SIZE + 1\n", read(fd, header.prog, (CHAMP_MAX_SIZE * 4) + 1));
	ft_printf("  prog_size = %x\n", header.prog_size);
	ft_printf("  magic     = %08x\n\n", header.magic);
	// ft_printf("comment : %.10s(...)\n\n", header.comment);





	E_TITLE
	return (1);
}
