/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:33:53 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/04 16:54:58 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		free_label(t_label **rip)
{
	DG("I'mmmm freeeeeeeee: %s", (*rip)->label);
	ft_strdel(&(*rip)->label);
	free(*rip);
	//TODO i don't know why free(rip) hav to be commented
}

void 			remove_label(t_ld **rip)
{
	ft_ld_del(rip, &free_label);
}