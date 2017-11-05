/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:55:30 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/05 11:08:33 by tdebarge         ###   ########.fr       */
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
