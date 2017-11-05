/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:29:31 by wescande          #+#    #+#             */
/*   Updated: 2017/10/03 19:23:47 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#define SELECT_TXT "Select the processus you want to analyze:"

/*
** Following cb is cut to respect the norm. should have plenty more params.
*/

static void			cb_search_insert(GtkEditable *editable, gchar *new_text)
{
	if (new_text && !ft_isdigit(*new_text))
		g_signal_stop_emission_by_name(editable, "insert_text");
}

static void			cb_process_activate(GtkEntry *entry, t_vm *vm)
{
	t_process		*process;
	int				position;
	unsigned int	process_id;

	process_id = ft_atoui(gtk_entry_get_text(entry));
	position = 0;
	LIST_FOR_EACH_ENTRY_0(process, &vm->process, lx);
	while (LIST_FOR_EACH_ENTRY_1(process, &vm->process, lx))
	{
		if (process_id == process->id)
		{
			gtk_combo_box_set_active(GTK_COMBO_BOX(vm->gtk.panel.process_box),
									position);
			return ;
		}
		++position;
	}
	verbose(vm, MSG_STD_G, "%s: No process match this value",
			gtk_entry_get_text(entry));
}

static GtkWidget	*process_selection(t_vm *vm)
{
	GtkWidget	*box;
	GtkWidget	*text_entry;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(SELECT_TXT), FALSE, FALSE,
								15);
	vm->gtk.panel.process_box = gtk_combo_box_text_new();
	gtk_widget_set_can_focus(vm->gtk.panel.process_box, FALSE);
	gtk_box_pack_end(GTK_BOX(box), vm->gtk.panel.process_box, FALSE, TRUE, 15);
	g_signal_connect(G_OBJECT(vm->gtk.panel.process_box), "changed",
							G_CALLBACK(cb_process_box), vm);
	text_entry = gtk_search_entry_new();
	gtk_widget_set_margin_start(text_entry, 100);
	gtk_entry_set_max_length(GTK_ENTRY(text_entry), 10);
	gtk_box_pack_end(GTK_BOX(box), text_entry, FALSE, TRUE, 0);
	g_signal_connect(G_OBJECT(text_entry), "insert-text",
							G_CALLBACK(cb_search_insert), vm);
	g_signal_connect(G_OBJECT(text_entry), "activate",
							G_CALLBACK(cb_process_activate), vm);
	return (box);
}

GtkWidget			*create_process_info(t_vm *vm)
{
	GtkWidget	*frame;
	GtkWidget	*box;

	frame = gtk_frame_new(NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Processus display :"),
						FALSE, FALSE, 15);
	gtk_box_pack_start(GTK_BOX(box), process_selection(vm), FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box), create_process_info_display(vm),
						FALSE, FALSE, 5);
	vm->gtk.panel.p_win.btn = pack_new_button(box, "More info ...",
						G_CALLBACK(cb_more_info), vm);
	gtk_widget_set_sensitive(vm->gtk.panel.p_win.btn, FALSE);
	return (frame);
}
