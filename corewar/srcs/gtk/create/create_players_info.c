/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:50:08 by wescande          #+#    #+#             */
/*   Updated: 2017/09/10 11:51:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

GtkWidget		*create_players_info(t_vm *vm)
{
	GtkWidget	*box;
	int			i;

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	i = -1;
	while (++i < MAX_PLAYERS)
	{

	}
	return (box);
}