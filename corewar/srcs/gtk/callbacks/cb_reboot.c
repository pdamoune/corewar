/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_reboot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:45:41 by wescande          #+#    #+#             */
/*   Updated: 2017/09/20 14:59:29 by wescande         ###   ########.fr       */
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
	(void)widget;
	if (IS_UNSET(vm->flag, PAUSE))
	{	DG();
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause), IS_SET(vm->flag, PAUSE));
	}
	remove_all_process(vm);
	erase_draw_area(vm);
	init_gtk_value(vm);
	init_vm_value(vm);
	return (FALSE);
}