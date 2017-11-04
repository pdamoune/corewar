/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:01:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/11/02 17:39:26 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_op			*is_instruction(char **line)
{
	int		i;

	i = -1;
	while (++i < 16)
		if (!ft_spastrcmp(*line, g_op_tab[i].instruc))
		{
			*line += ft_strlen(g_op_tab[i].instruc);
			return ((t_op *)&g_op_tab[i]);
		}
	return (NULL);
}
