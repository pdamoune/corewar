/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ski_spa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/01 16:01:42 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

uint8_t		calcul_type_from_ocp(uint8_t ocp, uint8_t index)
{
	if (((ocp >> (6 - 2 * index)) & 0b11) == 0b01)
		return (T_REG);
	else if (((ocp >> (6 - 2 * index)) & 0b11) == 0b10)
		return (T_DIR);
	else if (((ocp >> (6 - 2 * index)) & 0b11) == 0b11)
		return (T_IND);
	return (0);
}

uint8_t		calcul_ocp(int	nb_params, t_argument *parsed_args)
{
	unsigned char		ocp;
	int					i;

	i = -1;
	ocp = 0;
	while (++i < nb_params)
	{
		if (IS_SET(parsed_args[i].type, T_REG))
			ocp |= (1 << (6 - 2 * i));
		else if (IS_SET(parsed_args[i].type, T_DIR))
			ocp |= (2 << (6 - 2 * i));
		else if (IS_SET(parsed_args[i].type, T_IND))
			ocp |= (3 << (6 - 2 * i));
	}
	return (ocp);
}

uint8_t		calcul_instruction_len(uint8_t op_code, uint8_t ocp)
{
	uint8_t			len;
	int				i;

	i = -1;
	len = g_op_tab[op_code].ocp + 1;
	while (++i < g_op_tab[op_code].nb_params)
	{
		if (((ocp >> (6 - 2 * i)) & 0b11) == 0b01)
			len += 1;
		else if (((ocp >> (6 - 2 * i)) & 0b11) == 0b10)
			len += 2 * (1 + g_op_tab[op_code].index);
		else if (((ocp >> (6 - 2 * i)) & 0b11) == 0b11)
			len += 2;
	}
	return (len);
}
