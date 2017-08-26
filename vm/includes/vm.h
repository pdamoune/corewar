/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/23 14:47:01 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "usage.h"
# include "op.h"
# define TITLE ft_printf("===   %s   ===\n", __func__);
# define E_TITLE ft_printf("=== fin %s ===\n", __func__);

typedef struct	s_champions
{
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
}				t_champions;

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

#endif
