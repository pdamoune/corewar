/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:32:51 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 18:35:58 by wescande         ###   ########.fr       */
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
		UNSET(vm->gtk.px[previous].flag, MOUSE);
		previous = -1;
	}
	if (at != -1)
	{
		draw_border(widget, vm, at, COLOR_GREEN);
		SET(vm->gtk.px[at].flag, MOUSE);
		previous = at;
	}
	SET(vm->flag, REDRAW);
}