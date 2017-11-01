/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsubc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:54:39 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:50:35 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char		*ft_strndup(char *s, int i)
{
	char	*s_ret;

	if (!(s_ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s_ret = ft_memcpy(s_ret, s, i);
	s_ret[i] = '\0';
	return (s_ret);
}

int			ft_strsubc_nb(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		i++;
	}
	return (i);
}
