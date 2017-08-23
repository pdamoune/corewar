/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:24:11 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 16:40:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *ptr, size_t n)
{
	char	*str;
	char	rev;
	size_t	i;

	str = (char *)ptr;
	i = -1;
	while (str[++i] == 0)
		;
	while (i < n)
	{
		rev = str[i];
		str[i] = str[n];
		str[n] = rev;
		i++;
		n--;
	}
}
