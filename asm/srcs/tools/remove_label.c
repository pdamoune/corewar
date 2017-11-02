/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:33:53 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/02 13:57:15 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void		free_label(t_label *rip)
{
	ft_strdel(&rip->label);
	free(rip);
}

void 			remove_label(t_ld **rip)
{
	ft_ld_del(rip, &free_label);
}