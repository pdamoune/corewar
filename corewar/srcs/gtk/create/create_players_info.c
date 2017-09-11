/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:50:08 by wescande          #+#    #+#             */
/*   Updated: 2017/09/11 18:56:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

#define NEW_STATUS	"Fœtus"
#define LAST_CYCLE	"Last live at cycle:"
#define LAST_LIVE	"Not alive yet"

static GtkWidget	*panel_player(t_vm *vm, int i)
{
	GtkWidget	*box;
	GtkWidget	*b;

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	vm->gtk.panel.player[i].is_used = 1;
	vm->gtk.panel.player[i].status = gtk_label_new(NEW_STATUS);
	gtk_box_pack_start(box, vm->gtk.panel.player[i].status, FALSE, FALSE, 0);
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(box, b, FALSE, FALSE, 0);
	gtk_box_pack_start(b, gtk_label_new(LAST_CYCLE), FALSE, FALSE, 0);
	vm->gtk.panel.player[i].last_live = gtk_label_new("Not alive yet")
	gtk_box_pack_start(b, vm->gtk.panel.player[i].last_live, FALSE, FALSE, 0);
	
	return (box);
}

GtkWidget		*create_players_info(t_vm *vm)
{
	GtkWidget	*box;
	int			i;

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
			if (vm->player[i].is_used)
				gtk_box_pack_start(box, panel_player(vm, i), FALSE, FALSE, 0);
	}
	return (box);
}