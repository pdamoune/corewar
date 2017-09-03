/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gtk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:35:17 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 11:31:00 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static GtkWidget		*create_area(t_vm *vm)
{
	GtkWidget *scrol;
	GtkWidget *event_box;

	scrol = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(scrol, AREA_WIDTH, AREA_HEIGHT < 1000 ? AREA_HEIGHT : -1);
	DG("creating scrol with size: %d x %d", AREA_WIDTH, AREA_HEIGHT);//TODO CHECK SIZE HERE
	vm->gtk.pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, AREA_WIDTH, AREA_HEIGHT); // good ?
	gdk_pixbuf_fill(vm->gtk.pixbuf, 0xffffffff);
	vm->gtk.img = gtk_image_new_from_pixbuf(vm->gtk.pixbuf);
	vm->gtk.pixels = gdk_pixbuf_get_pixels(vm->gtk.pixbuf);
	vm->gtk.rowstride = gdk_pixbuf_get_rowstride(vm->gtk.pixbuf);
	event_box = gtk_event_box_new();
	gtk_event_box_set_above_child (GTK_EVENT_BOX(event_box), TRUE);
	gtk_container_add(GTK_CONTAINER(event_box), vm->gtk.img);
	gtk_container_add(GTK_CONTAINER(scrol), event_box);
	gtk_widget_add_events(event_box, GDK_POINTER_MOTION_MASK);
	g_signal_connect(G_OBJECT(event_box), "motion-notify-event", G_CALLBACK(cb_mouse), vm);
	g_signal_connect(G_OBJECT(event_box), "leave-notify-event", G_CALLBACK(cb_mouse), vm);
	return (scrol);
}

static GtkWidget		*create_panel(t_vm *vm)
{
	GtkWidget *box;
	GtkWidget *scale;
	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	vm->gtk.pause = pack_new_toggle_button(box, "PLAY", G_CALLBACK(cb_play), vm);
	gtk_widget_set_margin_bottom(vm->gtk.pause, 50);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Speed velocity:"), FALSE, FALSE, 0);
	scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	gtk_box_pack_start(GTK_BOX(box), scale, FALSE, FALSE, 0);
	gtk_range_set_value(GTK_RANGE(scale), (gdouble)INIT_SPEED);
	gtk_scale_add_mark (GTK_SCALE(scale), 1, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark (GTK_SCALE(scale), 7, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark (GTK_SCALE(scale), 25, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark (GTK_SCALE(scale), 50, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark (GTK_SCALE(scale), 75, GTK_POS_BOTTOM, NULL);
	gtk_scale_add_mark (GTK_SCALE(scale), 100, GTK_POS_BOTTOM, NULL);
	g_signal_connect(G_OBJECT(scale), "value-changed", G_CALLBACK(cb_speed), vm);
	gtk_box_pack_start(GTK_BOX(box), (vm->gtk.cpt = gtk_label_new("0")), FALSE, FALSE, 0);
	gtk_widget_set_margin_top(vm->gtk.cpt, 10);
	gtk_widget_set_size_request(box, 400, -1);
	return (box);
}

static GtkWidget		*create_main_box(t_vm *vm)
{
	GtkWidget *win;
	GtkWidget *box;
	GtkWidget *hbox;

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_decorated(GTK_WINDOW(win), FALSE);
	gtk_window_set_default_size(GTK_WINDOW(win), GTK_WIDTH, GTK_HEIGHT);
	gtk_window_set_title(GTK_WINDOW(win), "~   C . O . R . E . W . A . R   ~");
	g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(cb_quit), win);
	g_signal_connect(G_OBJECT(win), "key-release-event",
					G_CALLBACK(cb_key_event_release), vm);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(win), box);
	gtk_box_pack_start(GTK_BOX(box),
						GTK_WIDGET(menu_new(win)), FALSE, FALSE, 0);
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), hbox, TRUE, TRUE, 5);
	vm->gtk.win = win;
	return (hbox);
}

void					create_gtk(t_vm *vm)
{
	GtkWidget *box;

	box = create_main_box(vm);
	gtk_box_pack_start(GTK_BOX(box), create_panel(vm), FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box), create_area(vm), FALSE, FALSE, 5);
	gtk_widget_show_all(vm->gtk.win);
}