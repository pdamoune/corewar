/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:23:39 by wescande          #+#    #+#             */
/*   Updated: 2017/09/19 20:00:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static GtkWidget	*main_menu_item(t_vm *vm)
{
	GtkWidget *menu_item;
	GtkWidget *menu;

	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_mnemonic ("_File");
	menu_item_new(GTK_MENU(menu), "_Restart", G_CALLBACK(cb_reboot), vm);
	menu_item_new(GTK_MENU(menu), "_Quit", G_CALLBACK(cb_quit), vm);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	return (menu_item);
}

GtkMenuBar			*menu_new(t_vm *vm)
{
	GtkWidget *menu_bar;

	menu_bar = gtk_menu_bar_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), main_menu_item(vm));
	return GTK_MENU_BAR(menu_bar);
}