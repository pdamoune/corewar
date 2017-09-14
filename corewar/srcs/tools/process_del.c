/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:11:06 by wescande          #+#    #+#             */
/*   Updated: 2017/09/14 20:09:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		process_del(t_vm *vm, t_process *process)
{
	char	txt[12];

	//TODO play music ?
	list_del(&process->lx);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		ft_uitoa_nomalloc(process->id, txt);
		//TODO remove from combolist
		// gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(vm->gtk.panel.process_box), txt);
		if (vm->gtk.panel.process == process)
		{
			vm->gtk.panel.process = NULL;
			update_process(NULL);
		}
		--vm->gtk.px[process->pc].pc;
		if (!vm->gtk.px[process->pc].pc)
			erase_pc(vm, process->pc);
		if (list_empty(&vm->process))
			gtk_combo_box_set_button_sensitivity (GTK_COMBO_BOX(vm->gtk.panel.process_box),	GTK_SENSITIVITY_OFF);
	}
	free(process);
}