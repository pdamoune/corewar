/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:34:47 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 18:34:49 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

char	*ft_free_strjoin(char **s1, char **s2)
{
	char	*sptr;
	int		index;

	if (!*s1 || !*s2)
		return (NULL);
	if (!(sptr = (char*)malloc(sizeof(char)
		* (ft_strlen(*s1) + ft_strlen(*s2) + 1))))
		return (NULL);
	index = 0;
	while (**s1)
	{
		sptr[index] = **s1;
		++(*s1);
		++index;
	}
	while (**s2)
	{
		sptr[index] = **s2;
		++(*s2);
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}
