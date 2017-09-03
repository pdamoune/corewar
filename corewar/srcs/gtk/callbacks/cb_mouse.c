/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:27:58 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 11:39:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	cb_mouse(GtkWidget *win, GdkEventKey *event, t_vm *vm)
{
	GdkEventMotion		*e;

	(void)win;
	if (event->type == GDK_MOTION_NOTIFY)
	{
		e = (GdkEventMotion *)event;
		calcul_border(vm, (t_ivec2){(int)e->x, (int)e->y});
	}
	if (event->type == GDK_LEAVE_NOTIFY)
		calcul_border(vm, (t_ivec2){0, 0});
}