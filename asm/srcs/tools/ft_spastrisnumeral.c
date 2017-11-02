/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spastrisnumeral.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:00:42 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/02 19:25:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_spastrisnumeral(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		++str;
	while (*str && !ft_isspa(*str) && !ft_strchr(COMMENT_CHAR, *str))
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}