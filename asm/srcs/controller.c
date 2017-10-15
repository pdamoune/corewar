/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:52:41 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 16:01:51 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
**  LE CONTROLLER VA NOUS PERMETTRE DE TRAITER LES INFORMATIONS STOCKEES
*/

void		gal_fct(global_t *global, int one_arg, char *arg_tmp, int arg_ind)
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

void		ft_ptr_tab(global_t *global, int index, int one_arg, int arg_ind)
{
	char	*arg_tmp;

	p_tab[ld] = ld_instruct;
	p_tab[st] = st_instruct;
	p_tab[add] = add_instruct;
	p_tab[sub] = sub_instruct;
	p_tab[and] = and_instruct;
	p_tab[or] = or_instruct;
	p_tab[xor] = xor_instruct;
	p_tab[ldi] = ldi_instruct;
	p_tab[sti] = sti_instruct;
	p_tab[lld] = lld_instruct;
	p_tab[lldi] = lldi_instruct;
	p_tab[aff] = aff_instruct;
	arg_tmp = NULL;
	if (!one_arg)
		arg_tmp = p_tab[index](global, global->s_label->s_content->line);
	gal_fct(global, one_arg, arg_tmp, arg_ind);
}

void		ft_controller(global_t *global)
{
	ft_parse_label(global);
	ft_browse_file_counting(global);
	ft_parse_header(global);
	ft_browse_content(global);
}
