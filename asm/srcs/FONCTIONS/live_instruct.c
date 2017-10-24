/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:59:44 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/24 15:28:23 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	live_instruct(t_global *global)
{
	global->i = 0;
	ft_get_values(global, global->s_label->s_content->line);
}
