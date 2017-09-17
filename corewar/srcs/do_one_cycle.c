/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_one_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:30:20 by wescande          #+#    #+#             */
/*   Updated: 2017/09/17 22:57:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_op	g_op_tab[18] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, 0},
	{
		"live", 1,
		{
			T_DIR
		},
		1, 10, "alive", 0, 0, &op_live
	},
	{
		"ld", 2,
		{
			T_DIR | T_IND,
			T_REG
		},
		2, 5, "load", 1, 0, &op_ld
	},
	{
		"st", 2,
		{
			T_REG,
			T_IND | T_REG
		},
		3, 5, "store", 1, 0, &op_st
	},
	{
		"add", 3,
		{
			T_REG,
			T_REG,
			T_REG
		}, 4, 10, "addition", 1, 0, &op_add
	},
	{
		"sub", 3,
		{
			T_REG, T_REG, T_REG
		},
		5, 10, "soustraction", 1, 0, &op_sub
	},
	{
		"and", 3,
		{
			T_REG | T_IND | T_DIR,
			T_REG | T_IND | T_DIR,
			T_REG
		},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &op_and
	},
	{
		"or", 3,
		{
			T_REG | T_IND | T_DIR,
			T_REG | T_IND | T_DIR,
			T_REG
		},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &op_or
	},
	{
		"xor", 3,
		{
			T_REG | T_IND | T_DIR,
			T_REG | T_IND | T_DIR,
			T_REG
		},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &op_xor
	},
	{
		"zjmp", 1,
		{
			T_DIR
		},
		9, 20, "jump if zero", 0, 1, &op_zjmp
	},
	{
		"ldi", 3,
		{
			T_REG | T_DIR | T_IND,
			T_DIR | T_REG,
			T_REG
		},
		10, 25,	"load index", 1, 1, &op_ldi
	},

	{
		"sti", 3,
		{
			T_REG,
			T_REG | T_DIR | T_IND,
			T_DIR | T_REG
		},
		11, 25,	"store index", 1, 1, &op_sti
	},

	{
		"fork", 1,
		{
			T_DIR
		},
		12, 800, "fork", 0, 1, &op_fork
	},
	{
		"lld", 2,
		{
			T_DIR | T_IND, T_REG
		},
		13, 10, "long load", 1, 0, &op_lld
	},
	{
		"lldi", 3,
		{
			T_REG | T_DIR | T_IND,
			T_DIR | T_REG,
			T_REG
		},
		14, 50,	"long load index", 1, 1, &op_lldi
	},
	{
		"lfork", 1,
		{
			T_DIR
		},
		15, 1000, "long fork", 0, 1, &op_lfork
	},
	{
		"aff", 1,
		{
			T_REG}, 16, 2, "aff", 1, 0, &op_aff
		},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

static int		check_args(t_vm *vm, t_process *p, unsigned int *type, unsigned int *args)
{
	int		i;

	(void)vm; // vm ne sert a rien mais tu en a besoin je crois
	i = -1;
	while (++i < p->op.nb_params)
	{
		if (IS_UNSET(p->op.params[i], type[i]))
			return (1);
		if (type[i] == T_REG && args[i] > REG_NUMBER)
			return (DG("Invalid register"));
		p->op.params[i] = type[i]; // je sais pas si c'est une bonne chose
	}
	return (0);
}


static int		do_instruction(t_vm *vm, t_process *p)
{
	unsigned int		type[MAX_ARGS_NUMBER];
	unsigned int		args[MAX_ARGS_NUMBER];
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
	if (check_args(vm, p, type, (unsigned *)args)) //TODO check if args are type compatible others exceptions
	{
		p->pc = move_pc(vm, p->pc, 1);
		return (DG("Next process"));
	}
	p->op.instru(vm, p, args); // sending to instruction function

	DG("not yet full implemented");
	DG("make a pc jump of %d", pc_inc);
	p->pc = move_pc(vm, p->pc, pc_inc);
	return (0);
}

//TODO il faudrait lire l'instruction un tour plus tôt (et donc dès l'initialisation), et enregistrer un nombre de cycle restan de la bonne taille, sans le -1
static int		init_instruction(t_vm *vm, t_process *p)
{
	--p->nb_cycle_before_exec;
	if (!p->nb_cycle_before_exec)
	{
		do_instruction(vm, p);
	}
	else if (p->nb_cycle_before_exec == -1)
	{
		if (vm->area[p->pc] < 1 || vm->area[p->pc] > 16)
		{
			ft_bzero(&p->op, sizeof(t_op));//TODO check if no impact on result
			p->pc = move_pc(vm, p->pc, 1);
			p->nb_cycle_before_exec = 0;
			return (0);
		}
		p->op = g_op_tab[(unsigned)vm->area[p->pc]];
		p->nb_cycle_before_exec = p->op.cycle - 1;

		// Decommenter la ligne precedente et commenter la suivante pour avoir
		// les vrai nb_cycle_before_exec.
		// p->nb_cycle_before_exec = 1;
	}
	return (0);
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
	check_cycle(vm);
	++vm->cycle;
	return (0);
}
