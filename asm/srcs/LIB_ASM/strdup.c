/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:41:38 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 18:41:41 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

char	*ft_strdup_asm(const char *s)
{
	int		i;
	int		i2;
	char	*dest;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	i2 = ft_strlen(s) - i;
	if (!(dest = (char*)malloc(sizeof(*dest) * i2 + 1)))
		return (NULL);
	i2 = 0;
	while (s[i])
	{
		dest[i2] = s[i];
		i++;
		i2++;
	}
	dest[i2] = '\0';
	return (dest);
}
