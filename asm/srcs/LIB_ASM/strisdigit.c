/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:40:57 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 18:41:17 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

int		ft_isstrdigit(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (i == ft_strlen(s));
}

int		ft_isdigitspace(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (i != ft_strlen(s))
		return (0);
	return (i);
}

int		ft_isstrint(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '-')
			i++;
		else if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (i == ft_strlen(s));
}
