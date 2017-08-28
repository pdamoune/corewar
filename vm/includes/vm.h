/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/28 17:24:05 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <stdio.h>
# include "usage.h"
# include "op.h"
# define TITLE ft_printf("===   %s   ===\n", __func__);
# define E_TITLE ft_printf("=== fin %s ===\n", __func__);

# define MSG_COR(s) ("{red}corewar: " s "{eoc}\n")
# define ERR_COR(s, ...) (ft_dprintf(2, MSG_COR(s), ##__VA_ARGS__) * 0 + 1)


/*
** FLAGS
*/

# define GRAPHIC	(1 << 0)
# define DUMP		(1 << 1)
# define STOP		(1 << 2)

typedef struct	s_file
{
	int			is_used:1;
	char		r[REG_NUMBER + 1][REG_SIZE];
	// carry = r[0] ?
	// int		carry:1;
	int			pc;
	t_header	header;
}				t_file;

/*
** it's forbidden to change the order of the 2 first params in the following struct
** she is cast in another one after
*/

typedef struct	s_vm
{
	long int	flag;
	char		**av_data;
	t_file		file[4];
	int			cycle;
	char		area[MEM_SIZE];
	int			cycle_to_dump;
}				t_vm;

/*
** Main functions.
*/

int		main(int ac, char **av);
int		do_one_cycle(t_vm *vm);

/*
** Tools functions.
*/

int		usage(char *name);
int		free_vm(t_vm *vm);


/*
** Parser.
*/

int		cor_parser(t_champions *champion1, int ac, char **av);
int		cor_check_usage(int ac, char **av);
int		cor_check_champions(int ac, char **av, int index);

/*
** INIT
*/
int		init_vm(t_vm *vm, int ac, char **av);
int		init_dump(char **opt_arg, t_vm *vm, int n_args);
int		init_number(char **opt_arg, t_vm *vm, int n_args);
int		init_file(t_vm *vm, int num, char *filename);
int		cor_get_data(int fd, t_header *header);

/*
** DISPLAY
*/
int		display_win(t_vm *vm);
int		dump(t_vm *vm);

#endif
