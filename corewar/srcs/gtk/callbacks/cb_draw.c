/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:28:20 by wescande          #+#    #+#             */
/*   Updated: 2017/09/14 19:33:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		cb_draw(GtkWidget *widget, cairo_t *cr, t_vm *vm)
{
	// static int started = 0;

	(void)widget;
	// if (!started)
	// {
	// 	started = 1;
	// 	gtk_init_area(vm);
	// }
	cairo_set_source_surface(cr, vm->gtk.surface, 0, 0);
	cairo_paint(cr);
	return (FALSE);
}