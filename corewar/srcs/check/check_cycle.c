/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:24:53 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 14:14:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	reset_lives(t_vm *vm)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
		vm->players[i].live = 0;
}

static int	count_all_lives(t_vm *vm)
{
	int		lives;
	int		i;

	lives = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		lives += vm->players[i].live;
	return (lives);
}

void		check_cycle(t_vm *vm)
{
	if ((vm->last_check + vm->cycle_to_die) > vm->cycle)
		return ;
	if (list_empty(&vm->process)) // TODO on devrait faire ce check apres avoir supprime les process ? la vm de zz sembe le faire avant.
	{
		SET(vm->flag, STOP);
		return ;
	}
	check_live(vm);
	vm->last_check = vm->cycle;
	++vm->check_count;
	if (count_all_lives(vm) < NBR_LIVE && vm->check_count <= MAX_CHECKS)
		return ;
	reset_lives(vm);
	vm->check_count = 0;
	vm->cycle_to_die -= CYCLE_DELTA;
	if (vm->cycle_to_die <= 0)
		SET(vm->flag, STOP);
}