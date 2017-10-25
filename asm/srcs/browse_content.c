/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 14:17:33 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
extern t_op	g_op_tab[];


void				ft_get_opcode(t_global *global, char *line)
{
	char	*arg;

	global->i_tab = ft_find_i(line);
	global->res[global->res_pc] = g_op_tab[global->i_tab].op_code;
	++global->res_pc;
	if (global->i_tab < 16 && g_op_tab[global->i_tab].ocp)
		arg = ft_central(global, global->s_label->s_content->line);
	else
		arg = NULL;
	gal_fct(global, arg);
	if (global->i_tab == 16)
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
		global->s_label->s_content = global->s_label->begin_content;
		while (global->s_label->s_content)
		{
			if (global->s_label->s_content->line && global->s_label->s_content->line[0])
				ft_get_opcode(global, global->s_label->s_content->line[0]);
			global->s_label->s_content = global->s_label->s_content->next;
		}
		global->s_label = global->s_label->next;
	}
}

void				ft_get_values(t_global *global, char **line)
{
	char			*val_tmp;
	int				inc;

	val_tmp = NULL;
	while ((inc = 1) && line[++global->i] && !ft_str_mod(line[global->i], "#"))
	{
		if (!g_op_tab[global->i_tab].index && ((val_tmp = ft_str_mod(line[global->i], "%:"))
			|| (val_tmp = ft_str_mod(line[global->i], "%"))))
			*(int *)(&global->res[global->res_pc]) =
			(inc = 4) && ft_isstrint(val_tmp) ?
			bswap_32(ft_atoi(val_tmp)) : bswap_32(go_to_label(val_tmp, global));
		else if ((val_tmp = ft_str_mod(line[global->i], "r"))
				&& !ft_strchr(line[global->i], ':') && ft_isdigitspace(val_tmp))
			global->res[global->res_pc] = ft_atoi(val_tmp);
		else if ((g_op_tab[global->i_tab].index && (val_tmp = ft_str_mod(line[global->i], "%:")))
			|| (val_tmp = ft_str_mod(line[global->i], ":")))
			*(unsigned short *)(&global->res[global->res_pc++]) =
			bswap_16(go_to_label(val_tmp, global));
		else if ((g_op_tab[global->i_tab].index && (val_tmp = ft_str_mod(line[global->i], "%")))
		|| ((val_tmp = ft_strtrim(line[global->i])) && ft_isstrint(val_tmp)))
			*(unsigned short *)(&global->res[global->res_pc++]) =
			bswap_16(ft_atoi(val_tmp));
		global->res_pc += inc;
	}
}
