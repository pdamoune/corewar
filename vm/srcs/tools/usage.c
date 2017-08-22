/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/22 22:00:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
# define	USG			"Usage:"

# define	FILE_NAME	name

# define	OPT1		"[-d N -s N -v N | -b --stealth | -n --stealth]"
# define	OPT2		"[-a]"
# define	OPT3		"<champion1.cor>"
# define	OPT4		"<...>"

# define	TITLE1		"TEXT OUTPUT MODE"
# define	TITLE2		"BINARY OUTPUT MODE"
# define	TITLE3		"NCURSES OUTPUT MODE"

# define	USG1		"Prints output from \"aff\" (Default is to hide it)"
# define	USG2		"Dumps memory after N cycles then exits"
# define	USG3		"Runs N cycles, dumps memory, pauses, then repeats"
# define	USG4		"Verbosity levels, can be added together to enable several"
# define	USG41		"- 0 : Show only essentials"
# define	USG42		"- 1 : Show lives"
# define	USG43		"- 2 : Show cycles"
# define	USG44		"- 4 : Show operations (Params are NOT litteral ...)"
# define	USG45		"- 8 : Show deaths"
# define	USG46		"- 16 : Show PC movements (Except for jumps)"
# define	USG5		"Binary output mode for corewar.42.fr"
# define	USG6		"--stealth : Hides the real contents of the memory"
# define	USG7		"Ncurses output mode"
# define	USG8		"--stealth : Hides the real contents of the memory"

# define	TAB(X)		X, 0
# define	SEPARATOR	"#################################################################################"
# define	SEP			4, SEPARATOR
# define	SEPEND(X)	79 - ft_strlen(X) - SEP

int		usage(char *name)
{
	ft_prf("%s %s ", USG, FILE_NAME);
	ft_prf("%s %s %s %s\n", OPT1, OPT2, OPT3, OPT4);
	ft_prf("%*c-a %*c: %s\n", TAB(5), TAB(8), USG1);
	ft_prf("%.*s %s %.*s\n", SEP, TITLE1, SEPEND(TITLE1));
	ft_prf("%*c-d N %*c: %s\n", TAB(5), TAB(6), USG2);
	ft_prf("%*c-s N %*c: %s\n", TAB(5), TAB(6), USG3);
	ft_prf("%*c-v N %*c: %s\n", TAB(5), TAB(6), USG4);
	ft_prf("%*c %s\n", TAB(16), USG41);
	ft_prf("%*c %s\n", TAB(16), USG42);
	ft_prf("%*c %s\n", TAB(16), USG43);
	ft_prf("%*c %s\n", TAB(16), USG44);
	ft_prf("%*c %s\n", TAB(16), USG45);
	ft_prf("%*c %s\n", TAB(16), USG46);
	ft_prf("%.*s %s %.*s\n", SEP, TITLE2, SEPEND(TITLE2));
	ft_prf("%*c-b %*c: %s\n", TAB(5), TAB(8), USG5);
	ft_prf("%*c%s\n", TAB(5), USG6);
	ft_prf("%.*s %s %.*s\n", SEP, TITLE3, SEPEND(TITLE3));
	ft_prf("%*c-n %*c: %s\n", TAB(5), TAB(8), USG7);
	ft_prf("%*c%s\n", TAB(5), USG8);
	ft_prf("%s\n", SEPARATOR);
	return (0);
}
// #### TEXT OUTPUT MODE ############################################################%
