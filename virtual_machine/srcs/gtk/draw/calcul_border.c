/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:32:51 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 17:09:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	calcul_border(GtkWidget *widget, t_vm *vm, int at)
{
	static int			previous = -1;

	if (at == previous)
		return ;
	if (previous != -1)
	{
		draw_border(widget, vm, previous, COLOR_WHITE);
		previous = -1;
	}
	if (at != -1)
	{
		draw_border(widget, vm, at, COLOR_GREEN);
		previous = at;
	}
	SET(vm->flag, REDRAW);
}
