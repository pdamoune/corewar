/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:24:47 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 11:26:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static GtkWidget	*create_one_register(t_process_win *p_win, int id)
{
	GtkWidget	*box;
	char		*str;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	ft_asprintf(&str, "Registre [%d] :", id);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new(str), FALSE, FALSE, 15);
	p_win->reg[id] = gtk_label_new(str);
	free(str);
	gtk_box_pack_end(GTK_BOX(box), p_win->reg[id], FALSE, FALSE, 15);
	return (box);
}

static GtkWidget	*create_carry(t_process_win *p_win)
{
	GtkWidget	*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Carry :"), FALSE, FALSE,
									15);
	p_win->carry = gtk_label_new("CARRY");
	gtk_box_pack_end(GTK_BOX(box), p_win->carry, FALSE, FALSE, 15);
	return (box);
}

GtkWidget			*create_info_win(t_vm *vm)
{
	t_process_win			*p_win;
	GtkWidget				*box;
	int						i;

	p_win = &(vm->gtk.panel.p_win);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
	p_win->main_label = gtk_label_new("");
	gtk_box_pack_start(GTK_BOX(box), p_win->main_label, FALSE, FALSE, 15);
	i = -1;
	while (++i < REG_NUMBER)
		gtk_box_pack_start(GTK_BOX(box), create_one_register(p_win, i), FALSE,
						FALSE, 15);
	gtk_box_pack_start(GTK_BOX(box), create_carry(p_win), FALSE, FALSE, 15);
	return (box);
}
