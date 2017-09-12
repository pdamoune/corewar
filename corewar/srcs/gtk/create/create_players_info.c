/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:50:08 by wescande          #+#    #+#             */
/*   Updated: 2017/09/12 18:44:05 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

#define LAST_CYCLE	"Last live at cycle:"
#define LAST_LIVE	"Not alive yet"
#define N_LIVE		"Current number of live:"

static GtkWidget	*panel_player(t_vm *vm, int i)
{
	GtkWidget	*frame;
	GtkWidget	*box;
	GtkWidget	*b;

	frame = gtk_frame_new(NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_container_set_border_width(GTK_CONTAINER(frame), 5);
	gtk_container_set_border_width(GTK_CONTAINER(box), 15);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(vm->file[i].header.prog_name), FALSE, FALSE, 10);
	vm->gtk.panel.players[i].status = gtk_label_new(STATUS_NEW);
	gtk_box_pack_start(GTK_BOX(box), vm->gtk.panel.players[i].status, FALSE, FALSE, 0);
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new(LAST_CYCLE), FALSE, FALSE, 0);
	vm->gtk.panel.players[i].last_live = gtk_label_new("Not alive yet");
	gtk_box_pack_end(GTK_BOX(b), vm->gtk.panel.players[i].last_live, FALSE, FALSE, 0);
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new(N_LIVE), FALSE, FALSE, 0);
	vm->gtk.panel.players[i].n_live = gtk_label_new("0");
	gtk_box_pack_end(GTK_BOX(b), vm->gtk.panel.players[i].n_live, FALSE, FALSE, 0);
	
	return (frame);
}

GtkWidget		*create_players_info(t_vm *vm)
{
	GtkWidget	*frame;
	GtkWidget	*box;
	int			i;

	frame = gtk_frame_new(NULL);	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_ETCHED_IN);	
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Player display :"), FALSE, FALSE, 15);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
			if (vm->file[i].is_used)
				gtk_box_pack_start(GTK_BOX(box), panel_player(vm, i), FALSE, FALSE, 0);
	}
	return (frame);
}