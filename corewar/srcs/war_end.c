/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 17:42:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#define TXT_ASK		"Sorry, you asked for a dump at %d but the game is already over at %d. Do you want to dump current memory?[Y/n]"

static int	does_the_user_want_the_dump(t_vm *vm)
{
	(void)vm;
	//TODO HERE
	// if (IS_SET())
	// 	ft_printf();
	
	return (0);
}

void		war_end(t_vm *vm)
{
	if (IS_SET(vm->flag, DUMP))
	{
		if (does_the_user_want_the_dump(vm))
		{
			//TODO this dump here
		}
	}
	display_win(vm);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		if (IS_UNSET(vm->flag, PAUSE))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause), IS_SET(vm->flag, PAUSE));
		gtk_widget_set_sensitive(vm->gtk.panel.step, FALSE);
		gtk_widget_set_sensitive(vm->gtk.panel.pause, FALSE);
	}
	SET(vm->flag, END);
}