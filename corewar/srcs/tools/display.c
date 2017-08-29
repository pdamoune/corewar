/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:55:36 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/29 23:15:08 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
# define CLEAR			"\033\143"

void 	display_data(void)
{
	int fd;

	if ((fd = open("/dev/ttys002", O_WRONLY)) == -1)
		return ;
	ft_dprintf(fd, CLEAR);
	ft_dprintf(fd, "\n%10c===== DATA =====\n\n", 0);
	ft_dprintf(fd, "%4c MAX_PLAYERS     : %d\n", 0, MAX_PLAYERS);
	ft_dprintf(fd, "%4c MEM_SIZE        : %d\n", 0, MEM_SIZE);
	ft_dprintf(fd, "%4c CHAMP_MAX_SIZE  : %d\n\n", 0, CHAMP_MAX_SIZE);
	ft_dprintf(fd, "%4c 01  live\n", 0);
	ft_dprintf(fd, "%4c 02  ld\n", 0);
	ft_dprintf(fd, "%4c 03  st\n", 0);
	ft_dprintf(fd, "%4c 04  add\n", 0);
	ft_dprintf(fd, "%4c 05  sub\n", 0);
	ft_dprintf(fd, "%4c 06  and\n", 0);
	ft_dprintf(fd, "%4c 07  or\n", 0);
	ft_dprintf(fd, "%4c 08  xor\n", 0);
	ft_dprintf(fd, "%4c 09  zjmp\n", 0);
	ft_dprintf(fd, "%4c 0a  ldi\n", 0);
	ft_dprintf(fd, "%4c 0b  sti\n", 0);
	ft_dprintf(fd, "%4c 0c  fork\n", 0);
	ft_dprintf(fd, "%4c 0d  lld\n", 0);
	ft_dprintf(fd, "%4c 0e  lldi\n", 0);
	ft_dprintf(fd, "%4c 0f  lfork\n", 0);
	ft_dprintf(fd, "%4c 10  aff\n", 0);
	close(fd);
}

void 	disp_prog(int fd, char *prog, unsigned size)
{
	unsigned i = 0;
	int j = 0;

	ft_dprintf(fd, CLEAR);
	while (i < size)
	{
		while (i < size && j < 16)
		{
			ft_dprintf(fd, "%.2hhx ", prog[i]);
			i++;
			j++;
		}
		ft_dprintf(fd, "\n");
		j = 0;
	}
}

void 	disp_file(int fd, int fd_prog, t_file *file, t_header *header)
{
	static int i = 0;

	ft_dprintf(fd, CLEAR);
	ft_dprintf(fd, "%4cint          fd      : %d\n", 0, fd);
	ft_dprintf(fd, "%4cint          fd_prog : %d\n", 0, fd_prog);
	ft_dprintf(fd, "\n%10c===== t_file file[%d] =====\n\n", 0, i);
	ft_dprintf(fd, "{\n");
	ft_dprintf(fd, "%4cint          is_used      : %d\n", 0, file->is_used);
	ft_dprintf(fd, "%4cchar         **registres  : %p\n", 0, file->r);
	ft_dprintf(fd, "%4cint          pc           : %#d\n", 0, file->pc);
	ft_dprintf(fd, "}\n");
	ft_dprintf(fd, "%10c===== t_header *header %d =====\n\n", 0, i++);
	ft_dprintf(fd, "{\n");
	ft_dprintf(fd, "%4cunsigned     magic      : %x\n", 0, header->magic);
	ft_dprintf(fd, "%4cchar         prog_name  : %p\n", 0, header->prog_name);
	ft_dprintf(fd, "%4cunsigned     prog_size  : %d\n", 0, header->prog_size);
	ft_dprintf(fd, "%4cchar         comment    : %p\n", 0, header->comment);
	ft_dprintf(fd, "%4cunsigned     prog[0]    : %02x\n", 0, (char)header->prog[0]);
	ft_dprintf(fd, "}\n");
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
	ft_dprintf(fd, "%4clong int     flag      : %.32b\n", 0, vm->flag);
	ft_dprintf(fd, "%4cchar         **av_data : %p\n", 0, vm->av_data);
	ft_dprintf(fd, "%4ct_file       file[4]   : %p\n", 0, vm->file);
	ft_dprintf(fd, "%4cint          nb_player : %d\n", 0, vm->nb_player);
	ft_dprintf(fd, "%4cchar         area[MEM] : %p\n", 0, vm->area);
	ft_dprintf(fd, "%4cint          cycle     : %d\n", 0, vm->cycle);
	ft_dprintf(fd, "%4cint          cycle_t_d : %d\n", 0, vm->cycle_to_dump);
	ft_dprintf(fd, "}\n");
	close(fd);
}

void 	disp_area(char *area)
{
	int i = 0;
	int j = 0;

	ft_printf(CLEAR);

	while (i < MEM_SIZE)
	{
		while (j < 64)
		{
			ft_printf("%0.2hhx ", area[i]);
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

	// disp_area(vm->area);
	disp_vm(vm);
	display_data();
	while (++i < 4)
	{
		if (vm->file[i].is_used)
			disp_file(fd[i], fd[i], &vm->file[i], &vm->file[i].header);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
}
