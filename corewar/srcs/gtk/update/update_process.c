/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:45:01 by wescande          #+#    #+#             */
/*   Updated: 2017/09/17 23:49:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		update_nothing(t_vm *vm)
{
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_status), "Undefined");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_pc), "x");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner), ". . .");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner_id), "x");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_act), "Undefined");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_desc_act), ". . .");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_cycle_wait), "x");
}

static void		update_dead(t_vm *vm, t_process *p)
{
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_status), p->last_live ? STATUS_PRO_DEAD : STATUS_PRO_NEVER);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_pc), "x");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner), "Undertaker");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner_id), "666");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_act), "D.E.A.D");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_desc_act), "worms food");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_cycle_wait), "x");
}

static void		update_for_real(t_vm *vm, t_process *p)
{
	char txt[12];

	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_status), p->last_live ? STATUS_ALIVE : STATUS_NEW);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_pc), ft_itoa_nomalloc(p->pc, txt));
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner), vm->file[p->id_player].header.prog_name);
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner_id), ft_itoa_nomalloc(p->id_player, txt));
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_act), p->op.label ? p->op.label : "Undefined");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_desc_act), p->op.label ? p->op.description : ". . .");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_cycle_wait), ft_itoa_nomalloc(p->nb_cycle_before_exec, txt));
}

void			update_process(t_vm *vm, t_process *process, int is_dead)
{
	if (!process)
		update_nothing(vm);
	else if (is_dead)
		update_dead(vm, process);
	else
		update_for_real(vm, process);
}
