/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:52:41 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/23 17:41:11 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
**  LE CONTROLLER VA NOUS PERMETTRE DE TRAITER LES INFORMATIONS STOCKEES
*/

// t_opa	g_op_tab[17] =
// {
// 	{"live", 1,
// 		{T_DIR},
// 		1, 10, "alive", 0, 0},
// 	{"ld", 2,
// 		{T_DIR | T_IND, T_REG},
// 		2, 5, "load", 1, 0},
// 	{"st", 2,
// 		{T_REG, T_IND | T_REG},
// 		3, 5, "store", 1, 0},
// 	{"add", 3,
// 		{T_REG, T_REG, T_REG},
// 		4, 10, "addition", 1, 0},
// 	{"sub", 3,
// 		{T_REG, T_REG, T_REG},
// 		5, 10, "soustraction", 1, 0},
// 	{"and", 3,
// 		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
// 		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
// 	{"or", 3,
// 		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
// 		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
// 	{"xor", 3,
// 		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
// 		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
// 	{"zjmp", 1,
// 		{T_DIR},
// 		9, 20, "jump if zero", 0, 1},
// 	{"ldi", 3,
// 		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
// 		10, 25, "load index", 1, 1},
// 	{"sti", 3,
// 		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
// 		11, 25, "store index", 1, 1},
// 	{"fork", 1,
// 		{T_DIR},
// 		12, 800, "fork", 0, 1},
// 	{"lld", 2,
// 		{T_DIR | T_IND, T_REG},
// 		13, 10, "long load", 1, 0},
// 	{"lldi", 3,
// 		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
// 		14, 50, "long load index", 1, 1},
// 	{"lfork", 1,
// 		{T_DIR},
// 		15, 1000, "long fork", 0, 1},
// 	{"aff", 1,
// 		{T_REG},
// 		16, 2, "aff", 1, 0}
// };

void		ft_erase_cmt(char *line)
{
	char	*is_com;

	if ((is_com = ft_strstrchr(line, COMMENT_CHAR)))
		is_com[0] = '\0';
}

void		gal_fct(t_global *global, int one_arg, char *arg_tmp, int arg_ind)
{
	int		*arg;
	char	*str;

	if (!one_arg)
	{
		arg = (int *)(global->res + global->res_pc);
		str = ft_convert_base(arg_tmp, 2, 10);
		*arg = ft_atoi(str);
		free(str);
		free(arg_tmp);
		global->res_pc++;
	}
	global->i = 0;
	ft_get_values(global, global->s_label->s_content->line, arg_ind);
}

void		ft_g_ptr_tab(t_global *global, int index, int one_arg, int arg_ind)
{
	char	*arg_tmp;

	g_ptr_tab[ld] = ld_instruct;
	g_ptr_tab[st] = st_instruct;
	g_ptr_tab[add] = add_instruct;
	g_ptr_tab[sub] = sub_instruct;
	g_ptr_tab[and] = and_instruct;
	g_ptr_tab[or] = or_instruct;
	g_ptr_tab[xor] = xor_instruct;
	g_ptr_tab[ldi] = ldi_instruct;
	g_ptr_tab[sti] = sti_instruct;
	g_ptr_tab[lld] = lld_instruct;
	g_ptr_tab[lldi] = lldi_instruct;
	g_ptr_tab[aff] = aff_instruct;
	arg_tmp = NULL;
	if (!one_arg)
		arg_tmp = g_ptr_tab[index](global, global->s_label->s_content->line);
	gal_fct(global, one_arg, arg_tmp, arg_ind);
}

void		ft_controller(t_global *global)
{
	ft_parse_label(global);
	ft_browse_file_counting(global);
	ft_parse_header(global);
	ft_browse_content(global);
}
