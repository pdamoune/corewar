/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_process_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:46:47 by wescande          #+#    #+#             */
/*   Updated: 2017/09/17 17:44:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		cb_process_box(GtkComboBox *widget, t_vm *vm)
{
	t_process		*process;
	unsigned int	process_id;

	process_id = ft_atoui(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
	LIST_FOR_EACH_ENTRY(process, &vm->process, lx)
	{
		if (process_id == process->id)
		{
			vm->gtk.panel.process = process;
			update_process(vm, process, 0);
			return (FALSE);
		}
	}
	vm->gtk.panel.process = NULL;
	update_process(vm, NULL, 0);	
	return (FALSE);
}