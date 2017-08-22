/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:13:41 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/22 20:35:00 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"

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

int		cor_parser(char *champion1);

#endif
