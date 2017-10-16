/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:52:52 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/16 17:29:12 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

char	*ft_strchrstart(const char *big, const char *little)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (big[i])
	{
		if (ft_isspa(big[i]))
			i++;
		else if (ft_strchr(little, big[i]))
			return ((char *)big + i);
		else
			return (NULL);
	}
	return (NULL);
}

char	*ft_strstart(const char *big, const char *little)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if ((size_t)k < ft_strlen(little) && (big[i] == ' ' || big[i] == '\t'))
			i++;
		if (little[k] == '\0')
			return ((char *)big + i);
		if (big[i] == little[k])
		{
			i++;
			k++;
		}
		else
			return (NULL);
	}
	if (big[i] == little[k] && (size_t)k == ft_strlen(little))
		return ((char *)big + i);
	return (NULL);
}

char	*ft_str_mod(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (little[0] == '\0')
		return (ft_big_till_space((char *)big));
	while (big[i])
	{
		if (little[i] == '\0')
			return (ft_big_till_space((char *)big + i));
		if (big[i] == little[i])
			i++;
		else
			return (NULL);
	}
	if (big[i] == little[i] && (size_t)i == ft_strlen(little))
		return (ft_big_till_space((char *)big + i));
	return (NULL);
}

char	*ft_big_till_space(char *big)
{
	int		i;
	int		k;
	int		m;

	k = ft_strlen(big);
	i = 0;
	m = 0;
	while (big[i] != '\0' && big[i] != ' ' && big[i] != '\t')
		i++;
	while (big[i + m] == ' ' || big[i + m] == '\t')
		m++;
	if (big[i + m] != '\0' && !ft_strchr(COMMENT_CHAR, big[i + m]))
	{
		ft_putstr("The chararcter used '");
		ft_putchar(big[i + m]);
		ft_putendl("' is not suitable.");
		exit(EXIT_FAILURE);
		return (NULL);
	}
	while (i < k)
	{
		big[i] = '\0';
		i++;
	}
	return ((char*)big);
}
