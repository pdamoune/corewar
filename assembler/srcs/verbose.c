/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:39:28 by wescande          #+#    #+#             */
/*   Updated: 2017/11/04 00:20:37 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	asm_verbose(const int level, const char *str)
{
	if (level == MSG_ERROR)
		ft_dprintf(2, "{pur}Asm:{red} ERROR: %s{eoc}\n", str);
	else if (level == MSG_SUCESS)
		ft_printf("{gre}%s{eoc}\n", str);
	else if (level == MSG_WARNING)
		ft_printf("{pur}Asm: {yel}WARNING:{eoc} %s{eoc}\n", str);
	else if (level == MSG_INFO)
		ft_printf("{pur}Asm: {blu}INFO:{eoc} %s{eoc}\n", str);
	else if (level == MSG_STD)
		ft_printf("{pur}Asm: {eoc}%s{eoc}\n", str);
	else if (level == MSG_DEBUG)
		ft_printf("{pur}Asm: {YEL}{bla}DEBUG:{eoc} {yel}%s{eoc}\n", str);
}

int			verbose(t_asm *a, const int level, const char *message, ...)
{
	va_list		va;
	char		*str;

	if ((IS_SET(a->flag, QUIET) && level < MSG_DEBUG) ||
	(IS_UNSET(a->flag, DEBUG) && level == MSG_DEBUG) ||
	(IS_UNSET(a->flag, VERBOSE) && (level == MSG_INFO ||
		level == MSG_WARNING)))
		return (0);
	va_start(va, message);
	ft_vasprintf(&str, message, va);
	asm_verbose(level, str);
	free(str);
	return (level == MSG_ERROR ? -1 : 0);
}
