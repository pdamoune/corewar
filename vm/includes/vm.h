/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/22 22:22:55 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "op.h"

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

int		main(int argc, char **argv);

/*
** Tools functions.
*/

int		usage(char *name);

/*
** Parser.
*/

int		cor_parser(t_champions *champion1, int ac, char **av);

#endif
