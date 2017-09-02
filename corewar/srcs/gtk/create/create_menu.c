/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:23:39 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:24:24 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static GtkWidget	*main_menu_item(gpointer data)
{
	GtkWidget *menu_item;
	GtkWidget *menu;

	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_mnemonic ("_File");
	menu_item_new(GTK_MENU(menu), "_Quit", G_CALLBACK(cb_quit), data);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	return (menu_item);
}

GtkMenuBar			*menu_new(gpointer data)
{
	GtkWidget *menu_bar;

	menu_bar = gtk_menu_bar_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), main_menu_item(data));
	return GTK_MENU_BAR(menu_bar);
}