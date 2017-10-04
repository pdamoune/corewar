/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_key_event_release.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:46:51 by wescande          #+#    #+#             */
/*   Updated: 2017/10/04 16:39:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
// extern Uint8 *audio_pos; // global pointer to the audio buffer to be played
// extern Uint32 audio_len; 
static int		music(t_vm *vm)
{
	play_sound_from_memory(vm->sound, SDL_MIX_MAXVOLUME);

	// (void)vm;
	// DG();
	// if (vm->audio.is_play)
	// 	return (1);
	// DG();
		
	// vm->audio.is_play = 1;
	// vm->audio.audio_pos_tmp = vm->audio.audio_pos;
	// vm->audio.audio_len_tmp = vm->audio.audio_len;
	// vm->audio.audio_pos = vm->audio.audio_pos_reset;
	// vm->audio.audio_len = vm->audio.audio_len_reset;
	// DG("len: %d, pos: %d", vm->audio.audio_len, vm->audio.audio_pos_reset);
	// SDL_PauseAudio(0);
return (0);
}
static int		stop_corewar(t_vm *vm)
{
	SET(vm->flag, STOP);
	return (0);
}

static int		play(t_vm *vm)
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause),
			IS_SET(vm->flag, PAUSE));
	return (0);
}

static t_itof	g_action[] =
{
	{GTK_ESC, stop_corewar},
	{GTK_SPA, play},
	{GTK_M, music},
	// {GTK_B, back_music},
	{0, 0},
};

gboolean		cb_key_event_release(GtkWidget *win, GdkEventKey *event,
				t_vm *vm)
{
	int i;

	(void)win;
	i = -1;
	verbose(vm, MSG_DEBUG, "release key %s (val %u)",
					gdk_keyval_name(event->keyval), event->hardware_keycode);
	while (g_action[++i].id)
		if (g_action[i].id == event->hardware_keycode)
		{
			g_action[i].f(vm);
			return (FALSE);
		}
	return (FALSE);
}
