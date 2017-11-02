/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:48:18 by wescande          #+#    #+#             */
/*   Updated: 2017/11/02 19:55:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char		*g_char_type[]=
{
	"{T_REG | T_DIR | T_IND}",
	"{T_DIR | T_IND}",
	"{T_REG | T_IND}",
	"{T_REG | T_DIR}",
	"{T_REG}",
	"{T_DIR}",
	"{T_IND}",
	"{Type was not recognized}",
};

char		*type_to_str(int type)
{
	if (IS_SET(type, T_REG | T_DIR | T_IND))
		return (g_char_type[0]);
	if (IS_SET(type, T_DIR | T_IND))
		return (g_char_type[1]);
	if (IS_SET(type, T_REG | T_IND))
		return (g_char_type[2]);
	if (IS_SET(type, T_REG | T_DIR))
		return (g_char_type[3]);
	if (IS_SET(type, T_REG))
		return (g_char_type[4]);
	if (IS_SET(type, T_DIR))
		return (g_char_type[5]);
	if (IS_SET(type, T_IND))
		return (g_char_type[6]);
	return (g_char_type[7]);
}

