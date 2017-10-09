/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:24:53 by wescande          #+#    #+#             */
/*   Updated: 2017/10/09 17:59:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	reset_lives(t_vm *vm)
{
	int		i;

	vm->livetmp = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (vm->file[i].is_used)
		{
			vm->file[i].live = 0;
			if (IS_SET(vm->flag, GRAPHIC))
				update_players(vm, i);
		}
	}
}

static void	update_cycle_to_die(t_vm *vm)
{
	char	txt[12];

	verbose(vm, MSG_INFO, "Cycle to die is now %d", vm->cycle_to_die);
	if (IS_SET(vm->flag, GRAPHIC))
	{
		ft_itoa_nomalloc(vm->cycle_to_die, txt);
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.cycle_to_die), txt);
	}
}

static void	update_chk_cpt(t_vm *vm)
{
	char	txt[12];

	if (IS_SET(vm->flag, GRAPHIC))
	{
		ft_itoa_nomalloc((vm->last_check + vm->cycle_to_die), txt);
		gtk_label_set_text(GTK_LABEL(vm->gtk.panel.next_chk), txt);
	}
}

void		check_cycle(t_vm *vm)
{
	if ((vm->last_check + vm->cycle_to_die) > vm->cycle)
		return ;
	verbose(vm, MSG_DEBUG, "TIME TO CHECK", NULL);
	check_live(vm);
	
	// if (vm->cycle_to_die <= 0)
	// 	return (war_end(vm));
	vm->last_check = vm->cycle;
	if (vm->livetmp < NBR_LIVE && (++vm->check_count) < MAX_CHECKS)
	{
		if (list_empty(&vm->process))
		return (war_end(vm));
		reset_lives(vm);
		return (update_chk_cpt(vm));
	}
	reset_lives(vm);
	vm->check_count = 0;
	vm->cycle_to_die -= CYCLE_DELTA;
	update_cycle_to_die(vm);
	update_chk_cpt(vm);
	if (list_empty(&vm->process))
		return (war_end(vm));
}
