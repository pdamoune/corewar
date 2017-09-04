/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_speed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:37:35 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 18:23:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_speed(GtkWidget *widget, t_vm *vm)
{
	vm->gtk.speed = ft_pow((int)gtk_range_get_value(GTK_RANGE(widget)), 2);
	return (FALSE);
}