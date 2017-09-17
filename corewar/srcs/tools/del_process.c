/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:11:06 by wescande          #+#    #+#             */
/*   Updated: 2017/09/17 17:46:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	gtk_del_process(t_vm *vm, t_process *process)
{
	t_process		*p;
	char			txt[12];

	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(vm->gtk.panel.process_box));
	if (vm->gtk.panel.process == process)
	{
		update_process(vm, process, 1);
		vm->gtk.panel.process = NULL;
	}
	--vm->gtk.px[process->pc].pc;
	if (!vm->gtk.px[process->pc].pc)
		erase_pc(vm, process->pc);
	if (list_empty(&vm->process))
		gtk_combo_box_set_button_sensitivity(GTK_COMBO_BOX(vm->gtk.panel.process_box), GTK_SENSITIVITY_OFF);
	else
	{
		LIST_FOR_EACH_ENTRY(p, &vm->process, lx)
		{
			gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(vm->gtk.panel.process_box), ft_uitoa_nomalloc(p->id, txt));
		}
	}
}

void		del_process(t_vm *vm, t_process *process)
{
	//TODO play music ?
	list_del(&process->lx);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		gtk_del_process(vm, process);
	}
	free(process);
}