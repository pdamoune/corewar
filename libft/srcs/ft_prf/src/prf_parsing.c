/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:36:25 by pdamoune          #+#    #+#             */
/*   Updated: 2017/05/19 03:22:38 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_prf.h"

int		g_flags[6] = {'-', '0', '#', ' ', '+'};
char	*g_modifiers[8] = {"hh", "h", "l", "ll", "j", "z", "k", 0};

int		prf_flags(const char *format)
{
	int i;

	i = 0;
	while (format[I] == 39)
		I++;
	if (format[I] == '*')
	{
		(WIDTH = va_arg(AP, int)) < 0 ? FLAG |= MINUS : 0;
		WIDTH = ABS(WIDTH);
		return (1);
	}
	while (i < 5 && format[I] && (i = -1))
	{
		while (++i < 5)
			if (g_flags[i] == format[I])
			{
				FLAG |= TEST_COMB(i);
				return (1);
			}
		I++;
	}
	I--;
	return (0);
}

int		prf_modifier(const char *format)
{
	int i;

	i = 0;
	while (i < 7 && format[I])
	{
		if (!prf_strncmp(g_modifiers[i],
			&format[I], prf_strlen(g_modifiers[i])))
		{
			MOD |= TEST_COMB(i);
			FLAG |= MODIFIER;
			I += prf_strlen(g_modifiers[i]) - 1;
			return (1);
		}
		i++;
	}
	TYPE = format[I];
	I++;
	return (0);
}

int		prf_precision(const char *format)
{
	I++;
	FLAG |= PRECISION;
	PRECI = 0;
	if (format[I] == '*')
	{
		PRECI = va_arg(AP, int);
		PRECI = PRECI < 0 ? FLAG &= ~PRECISION : PRECI;
		return (1);
	}
	while (format[I] == '0')
		I++;
	if (prf_isdigit(format[I]) || format[I] == '-')
		PRECI = prf_atoi(&format[I]);
	PRECI < 0 ? PRECI = 0 && (FLAG |= MINUS) && I++ : 0;
	while (prf_isdigit(format[I]))
		I++;
	I--;
	return (1);
}

int		prf_width(const char *format)
{
	if (!prf_isdigit(format[I]))
		return
		(format[I] != '.' ? prf_modifier(format) : prf_precision(format));
	WIDTH = prf_atoi(&format[I]);
	while (prf_isdigit(format[I]))
		I++;
	I--;
	return (1);
}

int		prf_parsing(const char *format)
{
	I++;
	while (format[I])
	{
		if (!prf_flags(format) && !prf_width(format))
			return (1);
		I++;
	}
	return (0);
}
