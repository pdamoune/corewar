/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:33:57 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 21:26:48 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_check_putnbr_base(char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		count = 0;
		while (base[j] != '\0')
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

int				ft_check_atoi_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

long int		ft_atoi_base(char *str, char *base)
{
	int			sign;
	int			index;
	long int	display;
	int			size_base;

	index = 0;
	display = 0;
	sign = 1;
	while (base[index])
		index++;
	size_base = index;
	index = 0;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\v' ||
			str[index] == '\f' || str[index] == '\r' || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			sign = -1;
	while (str[index] && (ft_check_atoi_base(str[index], base) != -1
	|| (sign = 0)))
		display = display * size_base +
		(ft_check_atoi_base(str[index++], base)) * sign;
	return (sign ? display : 0);
}

char			*ft_convert_base(char *nbr, int len_from, int len_to)
{
	int			nb;
	char		*str_nb;

	nb = ft_atoli_base(nbr, len_from);
	str_nb = ft_litoa_base(nb, len_to, 0);
	return (str_nb);
}
