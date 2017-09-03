/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:27:58 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 23:29:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	cb_mouse(GtkWidget *win, GdkEventKey *event, t_vm *vm)
{
	GdkEventMotion		*e;
	int					at;

	(void)win;
	if (event->type == GDK_MOTION_NOTIFY)
	{
		e = (GdkEventMotion *)event;
		at = (int)e->x / PX_WIDTH + ((int)e->y / PX_HEIGHT) * BOX_BY_LINE;
		if (IS_SET(vm->gtk.px[at].flag, USED))
			calcul_border(vm, at);
		else
			calcul_border(vm, -1);
	}
	if (event->type == GDK_LEAVE_NOTIFY)
		calcul_border(vm, -1);
}