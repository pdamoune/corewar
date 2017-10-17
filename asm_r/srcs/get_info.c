/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:04:31 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/18 00:23:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

static unsigned int	get_int_from_area(char *prog, char size, int *pc_inc)
{
	unsigned int		ret;
	char				i;

	ret = 0;
	i = -1;
	while (++i < size)
		ret = (ret << 8) | prog[*pc_inc + i];
	*pc_inc += size;
	return (ret);
}

unsigned int		get_value(char *prog, t_op op, unsigned int type,
	int *pc_inc)
{
	if (IS_SET(type, T_REG))
		return ((char)get_int_from_area(prog, 1, pc_inc));
	if (IS_SET(type, T_IND))
		return ((short)get_int_from_area(prog, 2, pc_inc));
	if (IS_SET(type, T_DIR) && op.index)
		return ((short)get_int_from_area(prog, 2, pc_inc));
	if (IS_SET(type, T_DIR))
		return ((int)get_int_from_area(prog, 4, pc_inc));
	return (0);
}

void				get_type(unsigned char ocp, int nb_params,
	unsigned int *type)
{
	int				i;
	unsigned char	bit;

	i = -1;
	while (++i < nb_params)
	{
		bit = (ocp >> (6 - 2 * i));
		if (bit & 1)
		{
			if ((bit >> 1) & 1)
				type[i] = T_IND;
			else
				type[i] = T_REG;
		}
		else if (bit & 2)
			type[i] = T_DIR;
		else
			type[i] = 0;
	}
}
