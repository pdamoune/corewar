/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 00:03:33 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:05:29 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_atoui(const char *nptr)
{
	unsigned int nb;
	unsigned int nptr_len;

	nb = 0;
	nptr_len = 0;
	while (nptr[nptr_len] == ' ' || nptr[nptr_len] == '\t'
			|| nptr[nptr_len] == '\v' || nptr[nptr_len] == '\f'
			|| nptr[nptr_len] == '\r' || nptr[nptr_len] == '\n')
		nptr_len++;
	if (nptr[nptr_len] == '+')
		nptr_len++;
	while ('0' <= nptr[nptr_len] && nptr[nptr_len] <= '9')
	{
		nb = nb * 10 + (nptr[nptr_len] - '0');
		nptr_len++;
	}
	return (nb);
}

int					ft_atoi(const char *nptr)
{
	int nb;
	int nptr_start;
	int nptr_len;

	nb = 0;
	nptr_len = 0;
	while (nptr[nptr_len] == ' ' || nptr[nptr_len] == '\t'
			|| nptr[nptr_len] == '\v' || nptr[nptr_len] == '\f'
			|| nptr[nptr_len] == '\r' || nptr[nptr_len] == '\n')
		nptr_len++;
	nptr_start = nptr_len;
	if (nptr[nptr_len] == '-' || nptr[nptr_len] == '+')
		nptr_len++;
	while ('0' <= nptr[nptr_len] && nptr[nptr_len] <= '9')
	{
		nb = nb * 10 + (nptr[nptr_len] - '0');
		nptr_len++;
	}
	if (nptr[nptr_start] == '-')
		nb *= -1;
	return (nb);
}
