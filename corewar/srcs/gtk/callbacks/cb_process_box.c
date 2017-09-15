/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_process_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:46:47 by wescande          #+#    #+#             */
/*   Updated: 2017/09/15 18:27:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

gboolean		cb_process_box(GtkComboBox *widget, t_vm *vm)
{
	t_process		*process;
	unsigned int	process_id;
	int				cur_pro;

	
	process_id = ft_atoui(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
	DG("%d", process_id);
	LIST_FOR_EACH_ENTRY(process, &vm->process, lx)
	{
		if (process_id == process->id)
		{
			DG("FOUND IT");
			update_process(process);
			// return (FALSE);
		}
	}
	return (FALSE);
	DG();
	cur_pro = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	DG("remove entry %d", cur_pro);
	
	gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(widget), cur_pro);
	DG();
			gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(widget));

	
	update_process(NULL);
	DG();
	
	return (FALSE);
}