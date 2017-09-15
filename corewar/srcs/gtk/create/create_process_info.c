/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:29:31 by wescande          #+#    #+#             */
/*   Updated: 2017/09/15 18:23:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		cb_pop_process_box(GtkComboBox *widget, t_vm *vm)
{
	(void)vm;
	(void)widget;
	DG();
	// gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(widget));
	return (FALSE);
}

GtkWidget		*create_process_info(t_vm *vm)
{
	GtkWidget	*frame;
	GtkWidget	*box;
	GtkWidget	*b;

	frame = gtk_frame_new(NULL);	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Processus display :"), FALSE, FALSE, 15);
	b = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), b, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("Select the processus you want to analyze:       "), FALSE, FALSE, 0);
	vm->gtk.panel.process_box = gtk_combo_box_text_new_with_entry();
	gtk_box_pack_end(GTK_BOX(b), vm->gtk.panel.process_box, FALSE, TRUE, 0);
	g_signal_connect(G_OBJECT(vm->gtk.panel.process_box), "changed", G_CALLBACK(cb_process_box), vm);
	g_signal_connect(G_OBJECT(vm->gtk.panel.process_box), "key-press-event", G_CALLBACK(cb_pop_process_box), vm);
	return (frame);
}