/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:50:08 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 12:00:28 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

GtkWidget		*create_players_info(t_vm *vm)
{
	GtkWidget	*frame;
	GtkWidget	*box;
	int			i;

	frame = gtk_frame_new(NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(frame), box);
	gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_ETCHED_IN);
	gtk_box_pack_start(GTK_BOX(box), gtk_label_new("Player display :"),
					FALSE, FALSE, 15);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (vm->file[i].is_used)
			gtk_box_pack_start(GTK_BOX(box),
					create_players_info_display(vm, i), FALSE, FALSE, 0);
	}
	return (frame);
}
