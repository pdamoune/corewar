/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:52:52 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:50:35 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
	char	*find;

	if ((find = ft_strstr(big, little)))
		return (find + ft_strlen(little));
	else
		return (NULL);
}

char	*ft_str_mod(const char *big, const char *little)
{
	char	*find;

	if ((find = ft_strstr(big, little)))
		return (ft_big_till_space(find + ft_strlen(little)));
	else
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
