/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_one_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:30:20 by wescande          #+#    #+#             */
/*   Updated: 2017/09/04 21:41:03 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_op	g_op_tab[18] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &op_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &op_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &op_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &op_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, &op_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &op_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &op_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &op_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &op_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, &op_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, &op_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &op_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &op_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, &op_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &op_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &op_aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

int		check_args(t_vm *vm, int *type, unsigned *args)
{
	int		i;

	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (type[i] == T_REG && args[i] > REG_NUMBER)
			return (DG("Invalid register"));
	}
	//
	// ft_printf("args[0] : %0.32b\n", args[0]);
	// ft_printf("args[1] : %0.32b\n", args[1]);
	// ft_printf("args[2] : %0.32b\n", args[2]);
	// // ft_printf("args[3] : %d\n", args[3]);
	//
	// ft_printf("op.label : %s\n", op.label);
	// ft_printf("op.nb_params : %d\n", op.nb_params);
	// ft_printf("op.params[0] : %0.8b\n", op.params[0]);
	// ft_printf("op.params[1] : %0.8b\n", op.params[1]);
	// ft_printf("op.params[2] : %0.8b\n", op.params[2]);
	// ft_printf("op.op_code : %d\n", op.op_code);
	// ft_printf("op.cycle : %d\n", op.cycle);
	// ft_printf("op.description : %s\n", op.description);
	// ft_printf("op.ocp : %d\n", op.ocp);
	// ft_printf("op.index : %d\n", op.index);
	// ft_printf("op.instru : %p\n", op.instru);
	(void)&vm;
	(void)&type;
	return (0);
}


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
	if (check_args(vm, type, (unsigned *)args)) //TODO check if args are type compatible others exceptions
		return (DG("Next process"));

	/* TODO Check if p->op is really usefull.
	** 
	** p->op = g_op_tab[(unsigned)vm->area[p->pc]];
	** 	p->params = args;
	** 	p->op.instru(p->op, args);
	*/
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
		// p->nb_cycle_before_exec = p->op.cycle - 1;

		// Decommenter la ligne precedente et commenter la suivante pour avoir
		// les vrai nb_cycle_before_exec.
		p->nb_cycle_before_exec = 1;
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
			DG("IS_UNSET, pc = %d, nb_cycle_before_exec = %d", *pc, process->nb_cycle_before_exec);
		init_instruction(vm, process);
	}
	if (IS_SET(vm->flag, DUMP) && vm->cycle == vm->cycle_to_dump)
		dump(vm);
	// check_cycle(vm);
	++vm->cycle;
	return (0);
}
