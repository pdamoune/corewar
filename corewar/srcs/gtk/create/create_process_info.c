/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:29:31 by wescande          #+#    #+#             */
/*   Updated: 2017/09/12 18:57:32 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

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
	gtk_box_pack_start(GTK_BOX(b), gtk_label_new("Select the processus you want to analyze"), FALSE, FALSE, 0);
	vm->gtk.panel.process_box = gtk_combo_box_text_new();
	gtk_box_pack_end(GTK_BOX(b), vm->gtk.panel.process_box, FALSE, TRUE, 0);
	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(vm->gtk.panel.process_box),
		"hello");
	// gtk_combo_box_set_button_sensitivity (GTK_COMBO_BOX(vm->gtk.panel.process_box),	GTK_SENSITIVITY_OFF);
	return (frame);
}