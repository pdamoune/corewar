/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_info_display.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 11:34:10 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 12:21:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static GtkWidget	*process_cycle(t_vm *vm)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Cycle before cmd exec:"),
					FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box),
					(vm->gtk.panel.process_cycle_wait = gtk_label_new("x")),
					FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*process_cmd(t_vm *vm)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Process cmd:"),
					FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box),
					(vm->gtk.panel.process_desc_act = gtk_label_new(". . .")),
					FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box), gtk_label_new(" : "), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box),
					(vm->gtk.panel.process_act = gtk_label_new("Undefined")),
					FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*process_owner(t_vm *vm)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Owner:"), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box),
					(vm->gtk.panel.process_owner_id = gtk_label_new("x")),
					FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(box),
					(vm->gtk.panel.process_owner = gtk_label_new(". . .")),
					FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*process_status(t_vm *vm)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Process status:"),
					FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(box),
					(vm->gtk.panel.process_status = gtk_label_new("Undefined")),
					FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("At position:"),
					FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(box),
					(vm->gtk.panel.process_pc = gtk_label_new("x")),
					FALSE, FALSE, 15);
	return (box);
}

GtkWidget			*create_process_info_display(t_vm *vm)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	gtk_box_pack_start(GTK_BOX(box), process_status(vm), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), process_owner(vm), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), process_cmd(vm), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), process_cycle(vm), FALSE, FALSE, 0);
	return (box);
}
