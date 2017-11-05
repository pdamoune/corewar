/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:31:24 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 13:18:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean	cb_play(GtkWidget *widget, t_vm *vm)
{
	(void)widget;
	verbose(vm, MSG_DEBUG, "%s", __func__);
	if (IS_SET(vm->flag, NEVER_START))
	{
		UNSET(vm->flag, NEVER_START);
		if (IS_SET(vm->flag, MUSIC))
			play_music(&(vm->audio), MUSIC_FILE_FIGHT, SDL_MIX_MAXVOLUME);
	}
	SWITCH(vm->flag, PAUSE);
	if (IS_SET(vm->flag, PAUSE))
		gtk_button_set_label(GTK_BUTTON(widget), "PLAY");
	else
		gtk_button_set_label(GTK_BUTTON(widget), "PAUSE");
	return (FALSE);
}
