/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/27 12:05:24 by wescande         ###   ########.fr       */
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

/*
** FLAGS 
*/
# define GRAPHIC	(1 << 0)
# define DUMP		(1 << 1)

typedef struct	s_champions
{
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
}				t_champions;

/*
** it's forbidden to change the order of the 2 first params in the following struct
** she is cast in another one after
*/
typedef struct	s_vm
{
	long int	flag;
	char		**av_data;
	int			cycle_to_dump;
}				t_vm;

/*
** Main functions.
*/

int		main(int ac, char **av);

/*
** Tools functions.
*/

int		usage(char *name);

/*
** Parser.
*/

int		cor_parser(t_champions *champion1, int ac, char **av);
int		cor_check_usage(int ac, char **av);
int		cor_check_champions(int ac, char **av, int index);

/*
**		initialisation
*/
int		init_vm(t_vm *vm, int ac, char **av);
int		init_dump(char *opt_arg, t_vm *vm, int n_args);
int		init_player_number(char *opt_arg, t_vm *vm, int n_args);
int		init_player(int num, char *filename);
int		cor_get_data(int fd, header_t *header);

#endif
