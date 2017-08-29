/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/29 17:59:52 by pdamoune         ###   ########.fr       */
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

typedef struct		s_header
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
  unsigned			prog[CHAMP_MAX_SIZE / 4 + 1];
}					t_header;

typedef struct		s_file
{
	int				is_used:1;
	char			r[REG_NUMBER + 1][REG_SIZE];
	// carry = r[0] ?
	// int		carry:1;
	int				pc;
	t_header		header;
}					t_file;

/*
** it's forbidden to change the order of the 2 first params in the following struct
** she is cast in another one after
*/

typedef struct		s_vm
{
	long int		flag;
	char			**av_data;
	t_file			file[4];
	int				nb_player;
	char			area[MEM_SIZE];
	int				cycle;
	int				cycle_to_dump;
}					t_vm;

typedef struct		s_op
{
	char	*label;
	int		nb_params;
	int		params[3];
	// int		op_code;
	int		(*instru)();
	int		cycle;
	char	*label_name;
	int		ocp;
	int		index;
}					t_op;

/*
** Main functions.
*/

void	display(t_vm *vm);
int		main(int ac, char **av);
int		do_one_cycle(t_vm *vm);

/*
** Tools functions.
*/

int		usage(char *name);
int		free_vm(t_vm *vm);

/*
** INIT
*/

int		init_vm(t_vm *vm, int ac, char **av);
int		init_dump(char **opt_arg, t_vm *vm, int n_args);
int		init_number(char **opt_arg, t_vm *vm, int n_args);
int		init_file(t_vm *vm, int num, char *filename);
int		init_data(int fd, t_header *header);

/*
** Instructions.
*/

int		op_live(t_op param);
int		op_ld(t_op param);
int		op_st(t_op param);
int		op_add(t_op param);
int		op_sub(t_op param);
int		op_and(t_op param);
int		op_or(t_op param);
int		op_xor(t_op param);
int		op_zjmp(t_op param);
int		op_ldi(t_op param);
int		op_sti(t_op param);
int		op_fork(t_op param);
int		op_lld(t_op param);
int		op_lldi(t_op param);
int		op_lfork(t_op param);
int		op_aff(t_op param);

/*
** DISPLAY
*/
int		display_win(t_vm *vm);
int		dump(t_vm *vm);

#endif
