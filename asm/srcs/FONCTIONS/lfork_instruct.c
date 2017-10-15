/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:59:34 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/15 17:59:35 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	lfork_instruct(global_t *global)
{
	global->s_label->s_content->instruction[0] = 15;
	ft_get_values(global, global->s_label->s_content->line, 1);
}
