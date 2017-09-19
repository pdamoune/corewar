/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:29:31 by wescande          #+#    #+#             */
/*   Updated: 2017/09/19 19:13:02 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#define SELECT_TXT "Select the processus you want to analyze:                 "

static GtkWidget	*process_info(t_vm *vm)
{
	GtkWidget	*box;
	GtkWidget	*b;

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("Process status:"), FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(b), (vm->gtk.panel.process_status = gtk_label_new("Undefined")), FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("At position:"), FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(b), (vm->gtk.panel.process_pc = gtk_label_new("x")), FALSE, FALSE, 15);

	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("Owner:"), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(b), (vm->gtk.panel.process_owner_id = gtk_label_new("x")), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(b), (vm->gtk.panel.process_owner = gtk_label_new(". . .")), FALSE, FALSE, 15);
	
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("Process cmd:"), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(b), (vm->gtk.panel.process_desc_act = gtk_label_new(". . .")), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(b), gtk_label_new(" : "), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(b), (vm->gtk.panel.process_act = gtk_label_new("Undefined")), FALSE, FALSE, 15);
	
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("Cycle before cmd exec:"), FALSE, FALSE, 15);
	gtk_box_pack_end(GTK_BOX(b), (vm->gtk.panel.process_cycle_wait = gtk_label_new("x")), FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*process_selection(t_vm *vm)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(SELECT_TXT), FALSE, FALSE, 15);
	vm->gtk.panel.process_box = gtk_combo_box_text_new_with_entry();
	gtk_widget_set_can_focus(vm->gtk.panel.process_box, FALSE);
	gtk_box_pack_end(GTK_BOX(box), vm->gtk.panel.process_box, FALSE, TRUE, 15);
	g_signal_connect(G_OBJECT(vm->gtk.panel.process_box), "changed", G_CALLBACK(cb_process_box), vm);
	return (box);
}

GtkWidget			*create_process_info(t_vm *vm)
{
	GtkWidget	*frame;
	GtkWidget	*box;

	frame = gtk_frame_new(NULL);	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Processus display :"), FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(box), process_selection(vm), FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box), process_info(vm), FALSE, FALSE, 5);
	vm->gtk.panel.p_win.btn = pack_new_button(box, "More info ...", G_CALLBACK(cb_more_info), vm);
	gtk_widget_set_sensitive(vm->gtk.panel.p_win.btn, FALSE);
	return (frame);
}