/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 17:47:30 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 15:40:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		god_players(t_vm *vm)
{
	int		live_num;
	int		i;

	live_num = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		if (vm->file[i].is_used && vm->file[i].live > live_num)
			live_num = vm->file[i].live;
	return (live_num);
}

void			update_players(t_vm *vm, int id)
{
	char	txt[21];

	if (!vm->file[id].last_live)
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.players[id].status),
				STATUS_NEW);
	else if (!vm->file[id].live)
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.players[id].status),
				STATUS_DEAD);
	else if (vm->file[id].live == god_players(vm))
	{
		if (vm->gtk.god_players != -1 && vm->gtk.god_players != id)
			gtk_label_set_text(GTK_LABEL(
						vm->gtk.panel.players[vm->gtk.god_players].status),
					STATUS_ALIVE);
		vm->gtk.god_players = id;
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.players[id].status),
				STATUS_GOD);
	}
	else
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.players[id].status),
				STATUS_ALIVE);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.players[id].last_live),
			ft_litoa_nomalloc(vm->file[id].last_live, txt));
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.players[id].n_live),
			ft_itoa_nomalloc(vm->file[id].live, txt));
}
