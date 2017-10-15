/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplitvirg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:53:46 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 18:53:48 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

static int		ft_isseparator(int c)
{
	return (c == SEPARATOR_CHAR);
}

static int		ft_strcpy_c(char *dest, char const *src)
{
	int decalage;

	decalage = 0;
	while (*src && *src == ' ')
	{
		++src;
	}
	while (*src && !ft_isseparator(*src))
	{
		*dest = *src;
		++dest;
		++src;
		++decalage;
	}
	*dest = '\0';
	return (decalage);
}

static int		ft_strlen_c(char const *str)
{
	int len;

	len = 0;
	while (*str && *str == ' ')
	{
		++str;
	}
	while (*str && !ft_isseparator(*str))
	{
		++str;
		++len;
	}
	return (len);
}

static int		ft_nbstr_c(char const *str)
{
	int len;

	len = 0;
	while (*str)
	{
		while (*str && ft_isseparator(*str))
			++str;
		if (*str)
			++len;
		while (*str && !ft_isseparator(*str))
			++str;
	}
	return (len);
}

char			**ft_strsplit_virg(char const *str)
{
	char	**s1;
	int		i;

	if (!str)
		return (NULL);
	if (!(s1 = (char**)malloc(sizeof(*s1) * (ft_nbstr_c(str) + 1))))
		return (NULL);
	i = 0;
	while (*str && ft_isseparator(*str))
		++str;
	while (*str)
	{
		while (*str && *str == ' ')
		{
			++str;
		}
		if (!(s1[i] = (char*)malloc(sizeof(**s1) * (ft_strlen_c(str) + 1))))
			return (NULL);
		str = str + ft_strcpy_c(s1[i], str);
		++i;
		while (*str && ft_isseparator(*str))
			++str;
	}
	s1[i] = 0;
	return (s1);
}
