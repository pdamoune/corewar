/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_configure_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:39:53 by wescande          #+#    #+#             */
/*   Updated: 2017/09/06 11:09:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		clear_surface (cairo_surface_t *surface)
{
	cairo_t			*cr;

	cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_paint(cr);
	cairo_destroy(cr);
}

gboolean		cb_configure_event(GtkWidget *widget, GdkEventConfigure *event,
							t_vm *vm)
{
	(void)event;
	if (vm->gtk.surface)
		return (TRUE);
	vm->gtk.surface = gdk_window_create_similar_surface(
					gtk_widget_get_window(widget),
					CAIRO_CONTENT_COLOR,
					gtk_widget_get_allocated_width(widget),
					gtk_widget_get_allocated_height(widget));
	clear_surface(vm->gtk.surface);
	return (TRUE);
}