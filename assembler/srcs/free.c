/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:55:30 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/05 12:37:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			free_arguments(const t_op *cur_instru, t_argument *parsed_args)
{
	int				i;

	i = -1;
	while (++i < cur_instru->nb_params)
		if (parsed_args[i].type & T_LAB)
		{
			ft_strdel(&parsed_args[i].label->label);
			free(parsed_args[i].label);
		}
	return (-1);
}

void		free_label(t_label **rip)
{
	ft_strdel(&(*rip)->label);
	free(*rip);
}

void		remove_label(t_ld **rip)
{
	ft_ld_del(rip, &free_label);
}

void		free_file(t_asm *a)
{
	free(a->file.filename);
	ft_ld_clear(&a->file.list_know_label, free_label);
	ft_ld_clear(&a->file.list_unknow_label, free_label);
}
