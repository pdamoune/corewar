/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:44:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#define TXT_ASK_0	"{cya}Sorry, you asked for a dump at cycle %d but the game"
#define TXT_ASK_1	TXT_ASK_0 " is already over at cycle %d. Do you want to"
#define TXT_ASK		TXT_ASK_1 " dump current memory?\n{blu}[Y/n]\n{eoc}$>"
#define TXT_ASK_G_0	"Sorry, you asked for a dump at cycle %d but the game is"
#define TXT_ASK_G_1	TXT_ASK_G_0 " already over at cycle %d. Do you want to dump"
#define TXT_ASK_G	TXT_ASK_G_1 " current memory?\n"

static void		does_the_user_still_want_the_dump(t_vm *vm)
{
	GtkWidget	*dialog;
	char		ans;
	int			n_read;

	if (IS_SET(vm->flag, GRAPHIC))
	{
		dialog = gtk_message_dialog_new(GTK_WINDOW(vm->gtk.win),
				GTK_DIALOG_MODAL, GTK_MESSAGE_QUESTION,
				GTK_BUTTONS_YES_NO, TXT_ASK_G, vm->cycle_to_dump, vm->cycle);
		if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_YES)
			dump(vm);
		gtk_widget_destroy(dialog);
	}
	else
	{
		ft_printf(TXT_ASK, vm->cycle_to_dump, vm->cycle);
		n_read = read(0, &ans, 1);
		dump(vm);
	}
}

void			war_end(t_vm *vm)
{
	if (IS_SET(vm->flag, MUSIC))
		play_music(&(vm->audio), MUSIC_FILE_END, SDL_MIX_MAXVOLUME);
	if (IS_SET(vm->flag, DUMP))
		does_the_user_still_want_the_dump(vm);
	display_win(vm);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		if (IS_UNSET(vm->flag, PAUSE))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause),
										IS_SET(vm->flag, PAUSE));
		gtk_widget_set_sensitive(vm->gtk.panel.step, FALSE);
		gtk_widget_set_sensitive(vm->gtk.panel.pause, FALSE);
	}
	SET(vm->flag, END);
}
