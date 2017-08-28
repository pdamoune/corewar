/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:30:20 by wescande          #+#    #+#             */
/*   Updated: 2017/08/28 19:14:13 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_op	g_op_tab[18] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, },
	{"live", 1, {T_DIR}, &op_live, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, &op_ld, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, &op_st, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, &op_add, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, &op_sub, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, &op_and, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, &op_or, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, &op_xor, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, &op_zjmp, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, &op_ldi, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, &op_sti, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, &op_fork, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, &op_lld, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, &op_lldi, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, &op_lfork, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, &op_aff, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		do_instruction(t_vm *vm, int *pc, char **r, char *carry)
{
	char	*mem;
	(void)&r;
	(void)&carry;
	mem = vm->area;
	if (!mem[*pc] || mem[*pc] > 16) // n est pas une instruction
		return (0);
	g_op_tab[(int)mem[*pc]].instru(g_op_tab[(int)mem[*pc]]);
	return (0);
}



int		do_one_cycle(t_vm *vm)
{
	int			champion;
	int			*pc;
	char		**r;
	char		*carry;

	champion = 0;
	while (champion < 4)
	{
		pc = &vm->file[champion].pc;
		r = (char **)vm->file[champion].r;
		carry = &vm->file[champion].r[0][0];
		if (!do_instruction(vm, pc, r, carry))
			return (DG("area[pc] n est pas une instruction"));
		champion++;
	}
	if (IS_SET(vm->flag, DUMP) && vm->cycle == vm->cycle_to_dump)
		dump(vm);
	++vm->cycle;
	return (0);
}
