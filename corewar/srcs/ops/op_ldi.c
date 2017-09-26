/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:11:43 by philippe          #+#    #+#             */
/*   Updated: 2017/09/26 19:36:47 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ldi(t_vm *vm, t_process *p, unsigned int *args)
{
	analyze_value(vm, p, args, 2);
	// int pc_inc; // no more need i think

	// pc_inc = 4;//pourquoi pc_inc a 4... je l'aurais mis à 0 moi... @phillipe si tu lis ce commentaire.

	// if (process->op.params[0] == T_IND)
	// 	args[0] = get_value_at(vm, calc_addr(p->pc + args[0] % IDX_MOD), REG_SIZE);
	// else
	// 	args[0] = process->op.params[0] == T_REG ? process->r[args[0] - 1] : args[0];
	// args[1] = process->op.params[1] == T_REG ? process->r[args[1] - 1] : args[1];
	// process->r[args[2] - 1]= get_value_from_area(vm, process, process->pc + ((int)(args[0] + args[1]) % IDX_MOD), &pc_inc);
	p->r[args[2] - 1] = get_value_at(vm, calc_addr(p->pc + (args[0] + args[1]) % IDX_MOD), REG_SIZE);
	// process->carry = !process->r[args[2] - 1]; // pas de modif du carry dans le sujet de 42 TODO check

	return (0);
}
