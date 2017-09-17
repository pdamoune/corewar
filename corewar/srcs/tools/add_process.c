/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:18:33 by wescande          #+#    #+#             */
/*   Updated: 2017/09/15 23:20:21 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		add_process(t_vm *vm, t_process *p)
{
	static unsigned int		id = 0;
	char					txt[12];

	p->id = ++id;
	list_add(&(p->lx), &(vm->process));
	if (IS_SET(vm->flag, GRAPHIC))
	{
		ft_uitoa_nomalloc(id, txt);
		init_pc(vm, p->pc);
		gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(vm->gtk.panel.process_box), txt);
	}
}