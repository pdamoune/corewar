/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/20 16:51:51 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static int			ft_opcode(int index)
{
	int		opcode[16];

	opcode[0] = 1;
	opcode[1] = 4;
	opcode[2] = 5;
	opcode[3] = 6;
	opcode[4] = 7;
	opcode[5] = 8;
	opcode[6] = 9;
	opcode[7] = 11;
	opcode[8] = 3;
	opcode[9] = 12;
	opcode[10] = 14;
	opcode[11] = 13;
	opcode[12] = 10;
	opcode[13] = 2;
	opcode[14] = 15;
	opcode[15] = 16;
	return (opcode[index]);
}

void				ft_get_opcode(t_global *global, char *line)
{
	int		index;

	index = ft_find_index(global, line);
	global->res[global->res_pc] = ft_opcode(index);
	++global->res_pc;
	if ((index > 0 && index <= 5) || index == 8
	|| index == 13 || index == 11 || index == 15)
		ft_g_ptr_tab(global, index, 0, 0);
	else if (index == 0)
		ft_g_ptr_tab(global, index, 1, 0);
	else if (index == 6 || index == 9 || index == 14)
		ft_g_ptr_tab(global, index, 1, 1);
	else if (index == 7 || index == 10 || index == 12)
		ft_g_ptr_tab(global, index, 0, 1);
	else
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
			if (global->s_label->s_content->line[0])
				ft_get_opcode(global, global->s_label->s_content->line[0]);
			global->s_label->s_content = global->s_label->s_content->next;
		}
		global->s_label = global->s_label->next;
	}
}

void				ft_get_values(t_global *global, char **line, int arg_ind)
{
	char			*val_tmp;
	int				inc;

	val_tmp = NULL;
	while ((inc = 1) && line[++global->i] && !ft_str_mod(line[global->i], "#"))
	{
		if (!arg_ind && ((val_tmp = ft_str_mod(line[global->i], "%:"))
			|| (val_tmp = ft_str_mod(line[global->i], "%"))))
			*(int *)(&global->res[global->res_pc]) =
			(inc = 4) && ft_isstrint(val_tmp) ?
			INTREV32(ft_atoi(val_tmp)) : INTREV32(go_to_label(val_tmp, global));
		else if ((val_tmp = ft_str_mod(line[global->i], "r"))
				&& !ft_strchr(line[global->i], ':') && ft_isdigitspace(val_tmp))
			global->res[global->res_pc] = ft_atoi(val_tmp);
		else if ((arg_ind && (val_tmp = ft_str_mod(line[global->i], "%:")))
			|| (val_tmp = ft_str_mod(line[global->i], ":")))
			*(unsigned short *)(&global->res[global->res_pc++]) =
			INTREV16((unsigned short)go_to_label(val_tmp, global));
		else if ((arg_ind && (val_tmp = ft_str_mod(line[global->i], "%")))
		|| ((val_tmp = ft_strtrim(line[global->i])) && ft_isstrint(val_tmp)))
			*(unsigned short *)(&global->res[global->res_pc++]) =
			INTREV16((unsigned short)ft_atoi(val_tmp));
		global->res_pc += inc;
	}
}
