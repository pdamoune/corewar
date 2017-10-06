/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_configure_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:39:53 by wescande          #+#    #+#             */
/*   Updated: 2017/10/07 01:06:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>


gboolean		cb_configure_event(GtkWidget *widget, GdkEventConfigure *event,
							t_vm *vm)
{
	verbose(vm, MSG_DEBUG, "%s", __func__);
	(void)event;
	if (vm->gtk.surface)
		return (TRUE);
	vm->gtk.surface = gdk_window_create_similar_surface(
					gtk_widget_get_window(widget),
					CAIRO_CONTENT_COLOR,
					gtk_widget_get_allocated_width(widget),
					gtk_widget_get_allocated_height(widget));
	vm->gtk.cr = cairo_create(vm->gtk.surface);
	cairo_set_source_rgb(vm->gtk.cr, 1, 1, 1);
	cairo_paint(vm->gtk.cr);
	return (TRUE);
}
