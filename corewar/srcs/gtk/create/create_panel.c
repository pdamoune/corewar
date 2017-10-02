/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:22:22 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 17:14:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static GtkWidget		*create_cycle_display(t_vm * vm)
{
	GtkWidget	*box;
	char		txt[12];
	
	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Current cycle:  "), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), (vm->gtk.panel.cpt = gtk_label_new("0")),
									FALSE, FALSE, 0);
	ft_itoa_nomalloc(CYCLE_TO_DIE, txt);
	gtk_box_pack_end(GTK_BOX(box), (vm->gtk.panel.next_chk = gtk_label_new(txt)), FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(box), gtk_label_new("Next check at:  "), FALSE, FALSE, 0);
	ft_itoa_nomalloc(CYCLE_TO_DIE, txt);
	gtk_box_pack_end(GTK_BOX(box), (vm->gtk.panel.cycle_to_die = gtk_label_new(txt)), FALSE, FALSE, 0);
	gtk_widget_set_margin_end(vm->gtk.panel.cycle_to_die, 150);
	gtk_box_pack_end(GTK_BOX(box), gtk_label_new("CYCLE TO DIE:  "), FALSE, FALSE, 0);
	gtk_widget_set_margin_top(box, 10);
	return (box);
}

static GtkWidget		*create_scale_bar(t_vm *vm)
{
	GtkWidget		*scale;

	scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	gtk_widget_set_can_focus(scale, FALSE);
	gtk_range_set_value(GTK_RANGE(scale), (gdouble)INIT_SPEED);
	gtk_scale_add_mark(GTK_SCALE(scale), 1, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark(GTK_SCALE(scale), 7, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark(GTK_SCALE(scale), 25, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark(GTK_SCALE(scale), 50, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark(GTK_SCALE(scale), 75, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark(GTK_SCALE(scale), 100, GTK_POS_BOTTOM, NULL);
	g_signal_connect(G_OBJECT(scale), "value-changed",
									G_CALLBACK(cb_speed), vm);
	return (scale);
}

GtkWidget				*create_panel(t_vm *vm)
{
	GtkWidget *box;

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	vm->gtk.panel.step = pack_new_button(box, "ONE_STEP",
										G_CALLBACK(cb_step), vm);
	vm->gtk.panel.pause = pack_new_toggle_button(box, "PLAY",
										G_CALLBACK(cb_play), vm);
	gtk_widget_set_margin_bottom(vm->gtk.panel.pause, 30);
	gtk_widget_set_margin_top(vm->gtk.panel.pause, 10);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Speed velocity:"),
										FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), create_scale_bar(vm), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), create_cycle_display(vm), FALSE, FALSE, 0);

	gtk_widget_set_size_request(box, 400, -1);
	gtk_box_pack_start(GTK_BOX(box), create_players_info(vm), FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box), create_process_info(vm), FALSE, FALSE, 10);
	return (box);
}
