/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_key_event_release.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:46:51 by wescande          #+#    #+#             */
/*   Updated: 2017/09/12 17:21:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		stop_corewar(t_vm *vm)
{
	SET(vm->flag, STOP);
	return (0);
}

static int		play(t_vm *vm)
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause), IS_SET(vm->flag, PAUSE));
	return (0);
}

static t_itof	g_action[] =
{
	{GTK_ESC, stop_corewar},
	{GTK_SPA, play},
	{0, 0},
};

gboolean			cb_key_event_release(GtkWidget *win, GdkEventKey *event, t_vm *vm)
{
	int i;

	(void)win;
	i = -1;
	DG("release %s of val %u", gdk_keyval_name(event->keyval),
						event->hardware_keycode);
	while (g_action[++i].id)
		if (g_action[i].id == event->hardware_keycode)
		{
			g_action[i].f(vm);
			return (FALSE);
			
			break;
		}
	return (TRUE);
}