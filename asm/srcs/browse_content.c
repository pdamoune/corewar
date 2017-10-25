/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:23 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

extern t_op	g_op_tab[];

void				ft_get_opcode(t_global *global, char *line)
{
	char	*arg;

	ITAB = ft_find_i(line);
	global->res[global->res_pc] = g_op_tab[ITAB].op_code;
	++global->res_pc;
	if (ITAB < 16 && g_op_tab[ITAB].ocp)
		arg = ft_central(global, G_L_C->line);
	else
		arg = NULL;
	gal_fct(global, arg);
	if (ITAB == 16)
		ft_exit(10, global, NULL);
}

void				ft_browse_content(t_global *global)
{
	global->s_label = global->begin_label;
	while (!ft_strcmp(global->s_label->name, "HEADER")
		|| !ft_strcmp(global->s_label->name, "COMMENTS"))
		global->s_label = global->s_label->next;
	while (global->s_label)
	{
		G_L_C = global->s_label->begin_content;
		while (G_L_C)
		{
			if (G_L_C->line && G_L_C->line[0])
				ft_get_opcode(global, G_L_C->line[0]);
			G_L_C = G_L_C->next;
		}
		global->s_label = global->s_label->next;
	}
}

void				ft_get_values(t_global *global, char **line)
{
	char			*tmp;
	int				inc;

	tmp = NULL;
	while ((inc = 1) && line[++global->i] && !ft_str_mod(line[global->i], "#"))
	{
		if (!g_op_tab[ITAB].index && ((tmp = ft_str_mod(line[global->i], "%:"))
			|| (tmp = ft_str_mod(line[global->i], "%"))))
			*(int *)(&global->res[global->res_pc]) =
			(inc = 4) && ft_isstrint(tmp) ?
			bswap_32(ft_atoi(tmp)) : bswap_32(go_to_label(tmp, global));
		else if ((tmp = ft_str_mod(line[global->i], "r"))
				&& !ft_strchr(line[global->i], ':') && ft_isdigitspace(tmp))
			global->res[global->res_pc] = ft_atoi(tmp);
		else if ((g_op_tab[ITAB].index && (tmp = ft_str_mod(line[global->i],
			"%:"))) || (tmp = ft_str_mod(line[global->i], ":")))
			*(unsigned short *)(&global->res[global->res_pc++]) =
			bswap_16(go_to_label(tmp, global));
		else if ((g_op_tab[ITAB].index && (tmp = ft_str_mod(line[global->i],
			"%"))) || ((tmp = ft_strtrim(line[global->i])) && ft_isstrint(tmp)))
			*(unsigned short *)(&global->res[global->res_pc++]) =
			bswap_16(ft_atoi(tmp));
		global->res_pc += inc;
	}
}
