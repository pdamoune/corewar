/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_widget.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:27:32 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 23:51:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

GtkWidget		*menu_item_new(GtkMenu *menu, const gchar *title,
								GCallback callback, gpointer data)
{
	GtkWidget	*menu_item;

	menu_item = gtk_menu_item_new_with_mnemonic (title);
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
	g_signal_connect(G_OBJECT(menu_item), "activate", callback, data);
	return (menu_item);
}

GtkWidget		*pack_new_button(GtkWidget *widget, const gchar *title,
									GCallback callback, gpointer data)
{
	GtkWidget	*button;

	button = gtk_button_new_with_label(title);
	gtk_widget_set_can_focus(button, FALSE);
	gtk_box_pack_start(GTK_BOX(widget), button, FALSE, FALSE, 0);
	g_signal_connect(G_OBJECT(button), "button-release-event", callback, data);
	return (button);
}

GtkWidget		*pack_new_toggle_button(GtkWidget *widget, const gchar *title,
										GCallback callback, gpointer data)
{
	GtkWidget	*button;

	button = gtk_toggle_button_new_with_label(title);
	gtk_widget_set_can_focus(button, FALSE);
	gtk_box_pack_start(GTK_BOX(widget), button, FALSE, FALSE, 0);
	g_signal_connect(G_OBJECT(button), "toggled", callback, data);
	return (button);
}