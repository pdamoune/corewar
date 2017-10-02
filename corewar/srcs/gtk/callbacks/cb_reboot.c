/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_reboot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:45:41 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 11:22:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	erase_draw_area(t_vm *vm)
{
	cairo_t		*cr;

	cr = cairo_create(vm->gtk.surface);
	cairo_set_source_rgb(cr, 1., 1., 1.);
	cairo_rectangle(cr, 0, 0, AREA_WIDTH, AREA_HEIGHT);
	cairo_fill(cr);
	cairo_destroy(cr);
	gtk_widget_queue_draw_area(vm->gtk.draw, 0, 0, AREA_WIDTH, AREA_HEIGHT);
}

gboolean	cb_reboot(GtkWidget *widget, t_vm *vm)
{
	int		tmp;

	(void)widget;
	UNSET(vm->flag, END);
	if (IS_UNSET(vm->flag, PAUSE))
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause),
									IS_SET(vm->flag, PAUSE));
	gtk_widget_set_sensitive(vm->gtk.panel.step, TRUE);
	gtk_widget_set_sensitive(vm->gtk.panel.pause, TRUE);
	remove_all_process(vm);
	erase_draw_area(vm);
	tmp = vm->gtk.speed;
	init_gtk_value(vm);
	init_vm_value(vm);
	vm->gtk.speed = tmp;
	return (FALSE);
}
