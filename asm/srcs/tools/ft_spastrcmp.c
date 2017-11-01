/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spastrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:06:04 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 21:14:53 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_spastrcmp(char *spastr, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strncmp(spastr, str, len))
		return (1);
	return (!ft_isspa(spastr[len]));
}