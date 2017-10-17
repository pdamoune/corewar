/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:46:58 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/17 23:48:30 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

static void	asm_r_verbose(const int level, const char *str)
{
	if (level == MSG_ERROR)
		ft_dprintf(2, "{pur}Corewar:{red} %s{eoc}\n", str);
	else if (level == MSG_SUCESS)
		ft_printf("{gre}%s{eoc}\n", str);
	else if (level == MSG_WARNING)
		ft_printf("{pur}Corewar: {yel}WARNING:{eoc} %s{eoc}\n", str);
	else if (level == MSG_INFO)
		ft_printf("{pur}Corewar: {blu}INFO:{eoc} %s{eoc}\n", str);
	else if (level == MSG_STD)
		ft_printf("{pur}Corewar: {eoc}%s{eoc}\n", str);
	else if (level == MSG_DEBUG)
		ft_printf("{pur}Corewar: {YEL}{bla}DEBUG:{eoc} {yel}%s{eoc}\n", str);
}

int			verbose(t_asm_r *asm_r, const int level, const char *message, ...)
{
	va_list		va;
	char		*str;

	if ((IS_SET(asm_r->flag, QUIET) && level < MSG_DEBUG) ||
	(IS_UNSET(asm_r->flag, DEBUG) && level == MSG_DEBUG) ||
	(IS_UNSET(asm_r->flag, VERBOSE) && (level == MSG_INFO ||
		level == MSG_WARNING)))
		return (0);
	va_start(va, message);
	ft_vasprintf(&str, message, va);
	asm_r_verbose(level, str);
	free(str);
	return (level == MSG_ERROR);
}
