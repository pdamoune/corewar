/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:30:20 by wescande          #+#    #+#             */
/*   Updated: 2017/09/03 23:33:54 by wescande         ###   ########.fr       */
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

static int		do_instruction(t_vm *vm, t_process *p)
{
	int		type[MAX_ARGS_NUMBER];
	int		args[MAX_ARGS_NUMBER];
	int		pc_inc;
	int		i;

	pc_inc = p->op.ocp ? 2 : 1;
	if (p->op.ocp)
		get_type_from_area(vm, p, type);
	else
		type[0] = T_DIR;
	i = -1;
	while (++i < p->op.nb_params)
		args[i] = get_value_from_area(vm, p, type[i], &pc_inc);
	(void)args;
	//TODO use check if args are type compatible & execute
	DG("not yet full implemented");
	DG("make a pc jump of %d", pc_inc);
	p->pc = move_pc(vm, p->pc, pc_inc);
	return (0);
}

static int		init_instruction(t_vm *vm, t_process *p)
{
	--p->nb_cycle_before_exec;
	if (!p->nb_cycle_before_exec)//time to execute op
	{
		do_instruction(vm, p);
	}
	else if (p->nb_cycle_before_exec == -1) // time to check if new op is available
	{
		if (vm->area[p->pc] < 1 || vm->area[p->pc] > 16) // n est pas une instruction
		{
			p->pc = move_pc(vm, p->pc, 1);
			p->nb_cycle_before_exec = 0;
			DG("area[pc] n est pas une instruction");
			return (0);
		}
		p->op = g_op_tab[(unsigned)vm->area[p->pc]];
		p->nb_cycle_before_exec = p->op.cycle - 1;
	}
	return (0);
	/*
	char	*area;
	(void)&r;
	(void)&carry;
	(void)&pc;
	area = vm->area;
	if (!area[*pc] || (unsigned)area[*pc] > 16) // n est pas une instruction
	{
		*pc = (!*pc || (*pc % MEM_SIZE) ? (*pc) + 1 : 0);
		return (0);
	}
	// ft_printf("area pc = %x\n", area[*pc]);
	// // DG("\narea[*pc % 16] = %hh.2x\nfonction : %s\n", area[*pc % 16], g_op_tab[(int)area[*pc % 16]].label);
	g_op_tab[(short)area[*pc]].instru(g_op_tab[(int)area[*pc]]);
	*pc = (!*pc || (*pc % MEM_SIZE) ? *pc + 1 : 0);
	return (0);
	*/
}

int				do_one_cycle(t_vm *vm)
{
	t_process 	*process;
	int			*pc;

	LIST_FOR_EACH_ENTRY(process, &vm->process, lx)
	{
		pc = &(process->pc);
		if (IS_UNSET(vm->flag, GRAPHIC))
			ft_printf("=== %d\n", *pc);
		init_instruction(vm, process);
	}
	if (IS_SET(vm->flag, DUMP) && vm->cycle == vm->cycle_to_dump)
		dump(vm);
	// check_cycle(vm);
	++vm->cycle;
	return (0);
}
