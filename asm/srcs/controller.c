/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:52:41 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/17 16:19:21 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
**  LE CONTROLLER VA NOUS PERMETTRE DE TRAITER LES INFORMATIONS STOCKEES
*/

void		ft_erase_cmt(char *line)
{
	char	*is_com;

	if ((is_com = ft_strstrchr(line, COMMENT_CHAR)))
		is_com[0] = '\0';
}

void		gal_fct(t_global *global, int one_arg, char *arg_tmp, int arg_ind)
{
	int		*arg;

	if (!one_arg)
	{
		arg = (int *)(global->res + global->res_pc);
		*arg = ft_atoi(ft_convert_base(arg_tmp, "01", "0123456789"));
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
