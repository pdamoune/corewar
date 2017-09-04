/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:31:24 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 18:24:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_play(GtkWidget *widget, t_vm *vm)
{
	(void)widget;
	SWITCH(vm->flag, PAUSE);
	if (IS_SET(vm->flag, PAUSE))
		gtk_button_set_label(GTK_BUTTON(widget), "PLAY");
	else
		gtk_button_set_label(GTK_BUTTON(widget), "PAUSE");
	return (FALSE);
}