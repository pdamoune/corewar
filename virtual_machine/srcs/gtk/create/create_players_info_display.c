/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players_info_display.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 11:50:27 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 15:13:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

#define LAST_CYCLE	"Last live at cycle:"
#define LAST_LIVE	"Not alive yet"
#define N_LIVE		"Current number of live:"

static GtkWidget	*player_n_live(t_vm *vm, int i)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(N_LIVE), FALSE, FALSE, 15);
	vm->gtk.panel.players[i].n_live = gtk_label_new("0");
	gtk_box_pack_end(GTK_BOX(box), vm->gtk.panel.players[i].n_live,
					FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*player_alive(t_vm *vm, int i)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(LAST_CYCLE),
					FALSE, FALSE, 15);
	vm->gtk.panel.players[i].last_live = gtk_label_new("Not alive yet");
	gtk_box_pack_end(GTK_BOX(box), vm->gtk.panel.players[i].last_live,
					FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*player_status(t_vm *vm, int i)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	vm->gtk.panel.players[i].status = gtk_label_new(STATUS_NEW);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Player Status:"),
					FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box), vm->gtk.panel.players[i].status,
					FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*player_header(t_vm *vm, int i)
{
	GtkWidget	*box;
	char		id[12];

	(void)vm;
	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	ft_itoa_nomalloc(i + 1, id);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(id), FALSE, FALSE, 0);
	return (box);
}

GtkWidget			*create_players_info_display(t_vm *vm, int i)
{
	GtkWidget	*frame;
	GtkWidget	*box;

	frame = gtk_frame_new(NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_container_set_border_width(GTK_CONTAINER(frame), 5);
	gtk_container_set_border_width(GTK_CONTAINER(box), 15);
	gtk_box_pack_start(GTK_BOX(box), player_header(vm, i), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box),
			gtk_label_new(vm->file[i].header.prog_name), FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box), player_status(vm, i), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), player_alive(vm, i), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), player_n_live(vm, i), FALSE, FALSE, 0);
	return (frame);
}
