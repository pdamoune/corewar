/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_more_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:57:47 by wescande          #+#    #+#             */
/*   Updated: 2017/09/19 20:04:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static gboolean	quit_info(GtkWidget *widget, t_vm *vm)
{
	gtk_widget_destroy(widget);
	if (vm->gtk.panel.process)
		gtk_widget_set_sensitive(vm->gtk.panel.p_win.btn, TRUE);
	// vm->gtk.panel.p_win.is_updatable = 0;
	vm->gtk.panel.p_win.main_label = NULL;
	return (FALSE);
}

static int		play(GtkWidget *win, t_vm *vm)
{
	(void)win;
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(vm->gtk.panel.pause), IS_SET(vm->flag, PAUSE));
	return (0);
}

static t_itof	g_action_info[] =
{
	{GTK_ESC, quit_info},
	{GTK_SPA, play},
	{0, 0},
};

static gboolean			cb_key_info(GtkWidget *win, GdkEventKey *event, t_vm *vm)
{
	int i;

	i = -1;
	while (g_action_info[++i].id)
		if (g_action_info[i].id == event->hardware_keycode)
		{
			g_action_info[i].f(win, vm);
			return (FALSE);
		}
	return (TRUE);
}

gboolean	cb_more_info(GtkWidget *widget, GdkEvent *event, t_vm *vm)
{
	GtkWidget	*win;

	(void)event;
	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// vm->gtk.panel.p_win.win = win;
	gtk_widget_set_sensitive(widget, FALSE);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_NONE);
	gtk_window_set_default_size(GTK_WINDOW(win), 300, 800);
	g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(quit_info), vm);
	g_signal_connect(G_OBJECT(win), "key-release-event", G_CALLBACK(cb_key_info), vm);
	gtk_container_add(GTK_CONTAINER(win), create_info_win(vm));
	update_process_info(vm);
	gtk_widget_show_all(win);
	return (FALSE);
}