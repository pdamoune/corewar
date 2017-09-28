/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:45:01 by wescande          #+#    #+#             */
/*   Updated: 2017/09/28 17:48:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		update_nothing(t_vm *vm)
{
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_status), STATUS_PRO_NOT);
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
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_owner_id), ft_itoa_nomalloc(p->id_player + 1, txt));
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_act), p->op.label ? p->op.label : "Undefined");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_desc_act), p->op.label ? p->op.description : ". . .");
	gtk_label_set_text(GTK_LABEL(vm->gtk.panel.process_cycle_wait), ft_itoa_nomalloc(p->nb_cycle_before_exec, txt));
}

void			update_process(t_vm *vm, t_process *p, int is_dead)
{
	if (!p)
	{
		update_nothing(vm);
		gtk_widget_set_sensitive(vm->gtk.panel.p_win.btn, FALSE);
		if (vm->gtk.panel.p_win.main_label)
			gtk_label_set_text(GTK_LABEL(vm->gtk.panel.p_win.main_label), STATUS_PRO_NOT);
	}
	else if (is_dead)
	{
		update_dead(vm, p);
		gtk_widget_set_sensitive(vm->gtk.panel.p_win.btn, FALSE);
		if (vm->gtk.panel.p_win.main_label)
			gtk_label_set_text(GTK_LABEL(vm->gtk.panel.p_win.main_label), p->last_live ? STATUS_PRO_DEAD : STATUS_PRO_NEVER);
	}
	else
	{
		update_for_real(vm, p);
		gtk_widget_set_sensitive(vm->gtk.panel.p_win.btn, TRUE);
		if (vm->gtk.panel.p_win.main_label)
			update_process_info(vm);
	}
}
