/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/19 15:39:32 by tdebarge         ###   ########.fr       */
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
	if ((index > 0 && index <= 5) || index == 8 || index == 13 || index == 11 || index == 15)
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

// void				ft_get_values(t_global *global, char **line, int arg_ind)
// {
// 	char			*val_tmp;

// 	val_tmp = NULL;
// 	while (line[++global->i] && !ft_str_mod(line[global->i], "#"))
// 	{
// 		if (!arg_ind && ((val_tmp = ft_str_mod(line[global->i], "%:"))
// 			|| (val_tmp = ft_str_mod(line[global->i], "%"))))
// 		{
// 			if (ft_isstrint(val_tmp))
// 				global->res[global->res_pc += 4] = INTREV32(ft_atoi(val_tmp));
// 			else
// 				global->res[global->res_pc += 4] =
// 				INTREV32(go_to_label(val_tmp, global));
// 		}
// 		else if ((val_tmp = ft_str_mod(line[global->i], "r"))
// 				&& ft_isdigitspace(val_tmp))
// 			global->res[global->res_pc++] = ft_atoi(val_tmp);
// 		else if ((arg_ind && (val_tmp = ft_str_mod(line[global->i], "%:")))
// 		|| (val_tmp = ft_str_mod(line[global->i], ":")))
// 		{
// 			DG();
// 			DG("%p", &global->res[global->res_pc]);
// 			DG("%p", &global->res[global->res_pc += 2]);
// 			DG("%p", &global->res[global->res_pc]);
// 			// global->res[global->res_pc += 2] =
// 			global->res[global->res_pc] =
// 			INTREV16(go_to_label(val_tmp, global));
// 			// DG("%hd", global->res[global->res_pc]);
// 		}
// 		else if ((arg_ind && (val_tmp = ft_str_mod(line[global->i], "%")))
// 		|| ((val_tmp = ft_strdup(line[global->i])) && ft_isstrint(val_tmp)))
// 			global->res[global->res_pc += 2] = INTREV16(ft_atoi(val_tmp));
// 	}
// }

void	ft_get_values(t_global *global, char **line, int arg_ind)
{
	int				*value;
	unsigned short	*value_ind;
	char			*value_char;
	char			*val_tmp;

	val_tmp = NULL;
	value = 0;
	value_ind = 0;
	value_char = 0;
	while (line[++global->i] && !ft_str_mod(line[global->i], "#"))
	{
		//DG("-%s-", line[global->i]);
		if (!arg_ind && ((val_tmp = ft_str_mod(line[global->i], "%:"))
			|| (val_tmp = ft_str_mod(line[global->i], "%"))))
		{
			value = (int*)(global->res + global->res_pc);
			if(ft_isstrint(val_tmp))
				*value = INTREV32(ft_atoi(val_tmp));
			else
				*value = INTREV32(go_to_label(val_tmp, global));
			global->res_pc += 4;
		}
		else if ((val_tmp = ft_str_mod(line[global->i], "r"))
				&& ft_isdigitspace(val_tmp))
		{
			//global->res[global->res_pc++] = ft_atoi(val_tmp);
			value_char = (global->res + global->res_pc);
			*value_char = ft_atoi(val_tmp);
			global->res_pc++;
		}
		else if ((arg_ind && (val_tmp = ft_str_mod(line[global->i], "%:")))
			|| (val_tmp = ft_str_mod(line[global->i], ":")))
		{
			value_ind = (unsigned short*)(global->res + global->res_pc);
			*value_ind = INTREV16((unsigned short)go_to_label(val_tmp, global));
			global->res_pc += 2;
		}
		else if ((arg_ind && (val_tmp = ft_str_mod(line[global->i], "%")))
			|| ((val_tmp = ft_strtrim(line[global->i])) && ft_isstrint(val_tmp)))
		{
			value_ind = (unsigned short*)(global->res + global->res_pc);
			*value_ind = INTREV16(ft_atoi(val_tmp));
			global->res_pc += 2;
		}
	}
}
