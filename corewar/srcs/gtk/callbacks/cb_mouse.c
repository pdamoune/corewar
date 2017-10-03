/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:27:58 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 16:36:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_mouse(GtkWidget *widget, GdkEventKey *event, t_vm *vm)
{
	GdkEventMotion		*e;
	int					at;

	if (event->type == GDK_MOTION_NOTIFY)
	{
		e = (GdkEventMotion *)event;
		at = (int)e->x / PX_WIDTH + ((int)e->y / PX_HEIGHT) * BOX_BY_LINE;
		if (at < MEM_SIZE && IS_SET(vm->gtk.px[at].flag, USED))
			calcul_border(widget, vm, at);
		else
			calcul_border(widget, vm, -1);
	}
	if (event->type == GDK_LEAVE_NOTIFY)
		calcul_border(widget, vm, -1);
	return (FALSE);
}
