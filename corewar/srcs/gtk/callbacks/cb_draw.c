/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:28:20 by wescande          #+#    #+#             */
/*   Updated: 2017/10/24 11:33:31 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		cb_draw(GtkWidget *widget, cairo_t *cr, t_vm *vm)
{
	(void)widget;
	cairo_set_source_surface(cr, vm->gtk.surface, 0, 0);
	cairo_paint(cr);
	return (FALSE);
}
