/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:33:53 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/04 17:11:59 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		free_label(t_label **rip)
{
	DG("I'mmmm freeeeeeeee: %s", (*rip)->label);
	ft_strdel(&(*rip)->label);
	free(*rip);
}

void 			remove_label(t_ld **rip)
{
	ft_ld_del(rip, &free_label);
}