/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:55:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/06 18:02:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
# define CLEAR			"\033\143"

void 	display_players(t_vm *vm)
{
	int fd;
	int i = 0;
	t_file *players;

	if ((fd = open("/dev/ttys002", O_WRONLY)) == -1)
		return ;
	players = vm->file;
	ft_dprintf(fd, CLEAR);
	ft_dprintf(fd, "\n%10c===== players =====\n\n", 0);
	while (i < vm->nb_player)
	{
		ft_dprintf(fd, "player %d\n", i + 1);
		ft_dprintf(fd, "   live      : %d\n", players[i].live);
		ft_dprintf(fd, "   last_live : %d\n\n", players[i].last_live);
		i++;
	}
	close(fd);
}

void 	disp_process(int fd, t_process *process, t_op op)
{
	int i = -1;

	(void)&fd;
	(void)&i;
	(void)&process;
	(void)&op;
	ft_dprintf(fd, CLEAR);
	ft_dprintf(fd, "\n%10c===== Process [%d] =====\n\n", 0, process->pc);
	ft_dprintf(fd, "{\n");
	ft_dprintf(fd, "%4cregistre :\n", 0);
	while (++i < REG_NUMBER)
		if (process->r[i])
			ft_dprintf(fd, "       r[%d] = %#x | %d\n", i, process->r[i], process->r[i]);
	ft_dprintf(fd, "=== r[1] = %#x | %d\n", i, process->r[1], process->r[1]);
	ft_dprintf(fd, "%4cint      pc              : %d\n", 0, process->pc);
	ft_dprintf(fd, "%4cint      carry           : %d\n", 0, process->carry);
	ft_dprintf(fd, "%4cint      id_player       : %d\n", 0, process->id_player);
	ft_dprintf(fd, "%4cint      last_live       : %d\n", 0, process->last_live);
	ft_dprintf(fd, "%4cint      nb_cycle_b_exec : %d\n", 0, process->nb_cycle_before_exec);
	ft_dprintf(fd, "\n%10c===== op =====\n\n", 0);
	ft_dprintf(fd, "%4cchar     nb_params : %d\n", 0, process->op.nb_params);
	int j = -1;
	while (++j < process->op.nb_params)
		ft_dprintf(fd, "%4c     params[%d] : %d\n", 0, j, process->op.params[j]);
	ft_dprintf(fd, "%4cchar     label : %d | %s\n", 0, process->op.op_code, process->op.label);
	ft_dprintf(fd, "%4cint        cycle : %d\n", 0, process->op.cycle);
	ft_dprintf(fd, "%4cint        ocp : %d\n", 0, process->op.ocp);
	ft_dprintf(fd, "%4cint        index : %d\n", 0, process->op.ocp);


	// ft_dprintf(fd, "}\n");
	// // ft_dprintf(fd, "%4cint          id_player    : %d\n", 0, file->process->id_player);
	// ft_dprintf(fd, "%4cint          pc           : %d\n", 0, file->pc);
	// // ft_dprintf(fd, "%4cint          carry        : %d\n", 0, file->process->carry);
	// // ft_dprintf(fd, "%4cint          next         : %p\n", 0, file->process->next);
	// ft_dprintf(fd, "%10c===== t_header *header %d =====\n\n", 0, i++);
	// ft_dprintf(fd, "{\n");
	// ft_dprintf(fd, "%4cunsigned     magic      : %x\n", 0, header->magic);
	// ft_dprintf(fd, "%4cchar         prog_name  : %p\n", 0, header->prog_name);
	// ft_dprintf(fd, "%4cunsigned     prog_size  : %d\n", 0, header->prog_size);
	// ft_dprintf(fd, "%4cchar         comment    : %p\n", 0, header->comment);
	// ft_dprintf(fd, "%4cunsigned     prog[0]    : %02x\n", 0, (char)header->prog[0]);
	// ft_dprintf(fd, "}\n");
	// disp_prog(fd_prog, (char *)header->prog, header->prog_size);

}

void 	disp_vm(t_vm *vm)
{
	int fd;

	if ((fd = open("/dev/ttys001", O_WRONLY)) == -1)
		return ;
	ft_dprintf(fd, CLEAR);
	ft_dprintf(fd, "\n%10c===== {red}t_vm *vm {eoc}=====\n\n", 0);
	ft_dprintf(fd, "{\n");
	ft_dprintf(fd, "%4clong int flag          : %.32b\n", 0, vm->flag);
	ft_dprintf(fd, "%4cint      nb_player     : %d\n", 0, vm->nb_player);
	ft_dprintf(fd, "%4cint      cycle         : %d\n", 0, vm->cycle);
	ft_dprintf(fd, "%4cint      cycle_to_dump : %d\n", 0, vm->cycle_to_dump);
	ft_dprintf(fd, "%4cint      cycle_to_die  : %d\n", 0, vm->cycle_to_die);
	ft_dprintf(fd, "%4cint      last_check    : %d\n", 0, vm->last_check);
	ft_dprintf(fd, "%4cint      check_count   : %d\n", 0, vm->check_count);

	ft_dprintf(fd, "}\n");
	close(fd);
}

void 	disp_area(t_vm *vm, unsigned char *area)
{
	t_process *process;
	int i = 0;
	int j = 0;

	ft_printf(CLEAR);
	while (i < MEM_SIZE)
	{
		while (j < 64)
		{
			LIST_FOR_EACH_ENTRY_0(process, &vm->process, lx);
			while (LIST_FOR_EACH_ENTRY_1(process, &vm->process, lx))
				if (i == (int)process->pc)
					ft_printf("{red}", area[i]);
			ft_printf("%0.2hhx ", area[i]);
			LIST_FOR_EACH_ENTRY_0(process, &vm->process, lx);
			while (LIST_FOR_EACH_ENTRY_1(process, &vm->process, lx))
				if (i == (int)process->pc)
					ft_printf("{eoc}", area[i]);
			j++;
			i++;
		}
		ft_printf("\n");
		j = 0;
	}
	(void)&area;

}

void 	display(t_vm *vm)
{
	int	fd[6] =
	{
		open("/dev/ttys003", O_WRONLY),
		open("/dev/ttys005", O_WRONLY),
		open("/dev/ttys004", O_WRONLY),
		open("/dev/ttys006", O_WRONLY),
		open("/dev/ttys007", O_WRONLY),
		open("/dev/ttys008", O_WRONLY)
	};
	int i = -1;
	// int j = -1;
	char *line = NULL;

	get_next_line(0, &line);
	disp_area(vm, vm->area);
	disp_vm(vm);
	display_players(vm);
	t_process	*process;

	LIST_FOR_EACH_ENTRY_0(process, &vm->process, lx);
	while (LIST_FOR_EACH_ENTRY_1(process, &vm->process, lx))
	{
		++i;
		disp_process(fd[i], process, process->op);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
}
