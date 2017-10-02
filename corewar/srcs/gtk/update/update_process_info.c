/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_process_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:20:40 by wescande          #+#    #+#             */
/*   Updated: 2017/10/02 12:11:15 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	update_process_info(t_vm *vm)
{
	int		i;
	char	txt[12];

	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.p_win.main_label),
			vm->gtk.panel.process->last_live ? STATUS_ALIVE : STATUS_NEW);
	i = -1;
	while (++i < REG_NUMBER)
	{
		ft_itoa_nomalloc(vm->gtk.panel.process->r[i], txt);
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.p_win.reg[i]), txt);
	}
	ft_itoa_nomalloc(vm->gtk.panel.process->carry, txt);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.p_win.carry), txt);
}
