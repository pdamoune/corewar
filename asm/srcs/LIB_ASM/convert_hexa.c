/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:34:26 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:50:35 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*ft_construct_octets(t_global *global, int type, int nb_octet)
{
	char	*result;

	result = NULL;
	if (type == DIR_CODE)
	{
		if (nb_octet == 4)
			result = ft_strdup(" 0x.. 0x.. 0x.. 0x..");
		else if (nb_octet == 2)
			result = ft_strdup(" 0x.. 0x..");
		else
			ft_exit(13, global, NULL);
	}
	else if (type == IND_CODE)
		result = ft_strdup(" 0x.. 0x..");
	else if (type == REG_CODE || type == ARG_CODE)
		result = ft_strdup(" 0x..");
	return (result);
}
