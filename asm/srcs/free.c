/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:55:30 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 04:08:28 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		free_arguments(t_op *cur_instru, t_argument *parsed_args)
{
	int				i;

	DG("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	i = -1;
	while (++i < cur_instru->nb_params)
		if (parsed_args[i].type & T_LAB)
		{
			ft_strdel(&parsed_args[i].label->label);
			free(parsed_args[i].label);
		}
	return (-1);
}
