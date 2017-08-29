/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/29 22:55:42 by wescande         ###   ########.fr       */
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

# if MAX_PLAYERS < 1
#  error "macro MAX_PLAYERS must be strictly positive"
# endif

typedef struct	s_champions
{
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
}				t_champions;

typedef struct	s_process t_process;
struct	s_process
{
	t_process	*next;
	long		last_live;
};

typedef struct	s_player
{
	int			live;
	long		last_live;
}				t_player;

typedef struct	s_file
{
	int			is_used:1;
	t_header	header;
}				t_file;

/*
** it's forbidden to change the order of the 2 first params in the following struct
** she is cast in another one after
*/
typedef struct	s_vm
{
	long		flag;
	char		**av_data;
	t_file		file[MAX_PLAYERS];
	t_player	players[MAX_PLAYERS];
	t_process	*process;
	char		area[MEM_SIZE];
	long		cycle;
	long		cycle_to_dump;
	long		cycle_to_die;
	long		last_check;
	long		check_count;
}				t_vm;

/*
** Main functions.
*/

int		main(int ac, char **av);
int		do_one_cycle(t_vm *vm);
void	check_cycle(t_vm *vm);
void	check_live(t_vm *vm);

/*
** Tools functions.
*/

int		usage(char *name);
int		free_vm(t_vm *vm);
void		remove_one_process(t_vm *vm, t_process *process);
void		process_del(t_process *process);



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
