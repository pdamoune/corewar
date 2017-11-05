/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:27:58 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 11:33:40 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_mouse(GtkWidget *widget, GdkEventKey *event, t_vm *vm)
{
	GdkEventMotion		*e;
	int					at;
	char				txt[12];

	if (event->type == GDK_MOTION_NOTIFY)
	{
		e = (GdkEventMotion *)event;
		at = (int)e->x / PX_WIDTH + ((int)e->y / PX_HEIGHT) * BOX_BY_LINE;
		ft_itoa_nomalloc(at, txt);
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.mouse), txt);
		if (at < MEM_SIZE && IS_SET(vm->gtk.px[at].flag, USED))
			calcul_border(widget, vm, at);
		else
			calcul_border(widget, vm, -1);
	}
	if (event->type == GDK_LEAVE_NOTIFY)
	{
		calcul_border(widget, vm, -1);
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.mouse), "-");
	}
	return (FALSE);
}
