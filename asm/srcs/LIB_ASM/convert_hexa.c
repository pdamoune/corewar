/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:34:26 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/17 16:06:45 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"

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

char	*ft_convert_hexa(t_global *global, char *arg, int type, int nb_octet)
{
	char	*result;
	char	*value;
	int		i;
	int		j;

	result = ft_construct_octets(global, type, nb_octet);
	if (type == ARG_CODE)
		value = ft_convert_base(arg, "01", "0123456789ABCDEF");
	else
		value = ft_convert_base(arg, "0123456789", "0123456789ABCDEF");
	i = ft_strlen(result) - 1;
	j = ft_strlen(value) - 1;
	while (i >= 0)
	{
		if (result[i] == '.')
		{
			if (j >= 0)
				result[i] = value[j--];
			else
				result[i] = '0';
		}
		i--;
	}
	free(value);
	return (result);
}
