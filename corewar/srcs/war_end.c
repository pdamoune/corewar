/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/09/26 19:49:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	war_end(t_vm *vm)
{
	if (IS_SET(vm->flag, GRAPHIC))
	{
		if (IS_UNSET(vm->flag, PAUSE))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause), IS_SET(vm->flag, PAUSE));
		gtk_widget_set_sensitive(vm->gtk.panel.step, FALSE);
		gtk_widget_set_sensitive(vm->gtk.panel.pause, FALSE);
	}
	SET(vm->flag, END);
}