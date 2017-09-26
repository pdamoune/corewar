/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:34:11 by wescande          #+#    #+#             */
/*   Updated: 2017/09/26 19:34:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		calc_long_value(t_vm *vm, t_process *p, int type, unsigned int arg)
{
	if (type == T_IND)
		return (get_value_at(vm, calc_addr(p->pc + arg), REG_SIZE));
	else if (type == T_REG)
		return (p->r[arg - 1]);
	return (arg);
}

static int		calc_value(t_vm *vm, t_process *p, int type, unsigned int arg)
{
	if (type == T_IND)
		return (get_value_at(vm, calc_addr(p->pc + arg % IDX_MOD), REG_SIZE));
	else if (type == T_REG)
		return (p->r[arg - 1]);
	return (arg);
}

void			analyze_long_value(t_vm *vm, t_process *p, unsigned int *args, int lim)
{
	short	i;
	
	i = -1;
	while (++i < lim)
		args[i] = calc_long_value(vm, p, p->op.params[i], args[i]);
}

void			analyze_value(t_vm *vm, t_process *p, unsigned int *args, int lim)
{
	short	i;
	
	i = -1;
	while (++i < lim)
		args[i] = calc_value(vm, p, p->op.params[i], args[i]);
}