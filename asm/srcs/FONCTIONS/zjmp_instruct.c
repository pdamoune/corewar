/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:04:50 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/24 15:28:10 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	zjmp_instruct(t_global *global)
{
	global->s_label->s_content->instruction[0] = 9;
	ft_get_values(global, global->s_label->s_content->line);
}
