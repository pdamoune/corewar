/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spastrisnumeral.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:00:42 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/02 16:01:38 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_spastrisnumeral(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		++str;
	while (*str && !ft_isspa(*str))
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}