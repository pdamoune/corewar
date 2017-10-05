/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/05 19:39:05 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

// #include "../../includes/vm.h"
// #define	USG			"Usage:"

// #define	FILE_NAME	name

// #define	OPT1		"[-d N -s N -v N | -b --stealth | -n --stealth]"
// #define	OPT2		"[-a]"
// #define	OPT3		"<champion1.cor>"
// #define	OPT4		"<...>"

// #define	TITLE1		"TEXT OUTPUT MODE"
// #define	TITLE2		"BINARY OUTPUT MODE"
// #define	TITLE3		"NCURSES OUTPUT MODE"

// #define	USG1		"Prints output from \"aff\" (Default is to hide it)"
// #define	USG2		"Dumps memory after N cycles then exits"
// #define	USG3		"Runs N cycles, dumps memory, pauses, then repeats"
// #define	USG4		"Verbosity levels, can be added together to enable several"
// #define	USG41		"- 0 : Show only essentials"
// #define	USG42		"- 1 : Show lives"
// #define	USG43		"- 2 : Show cycles"
// #define	USG44		"- 4 : Show operations (Params are NOT litteral ...)"
// #define	USG45		"- 8 : Show deaths"
// #define	USG46		"- 16 : Show PC movements (Except for jumps)"
// #define	USG5		"Binary output mode for corewar.42.fr"
// #define	USG6		"--stealth : Hides the real contents of the memory"
// #define	USG7		"Ncurses output mode"
// #define	USG8		"--stealth : Hides the real contents of the memory"

// #define	TAB(X)		X, 0
// #define	SEPARATOR	"#################################################################################"
// #define	SEP			4, SEPARATOR
// #define	SEPEND(X)	79 - ft_strlen(X) - SEP

int		usage(char *name)
{
	(void)name;
	ft_printf("usage: corewar [-DgimqsvV][-d n_cycle][-n number champion_file]\n");
	ft_printf("see man for more information\n");
	//TODO usage is false. need to be change
	// ft_printf("%s %s ", USG, FILE_NAME);
	// ft_printf("%s %s %s %s\n", OPT1, OPT2, OPT3, OPT4);
	// ft_printf("%*c-a %*c: %s\n", TAB(5), TAB(8), USG1);
	// ft_printf("%.*s %s %.*s\n", SEP, TITLE1, SEPEND(TITLE1));
	// ft_printf("%*c-d N %*c: %s\n", TAB(5), TAB(6), USG2);
	// ft_printf("%*c-s N %*c: %s\n", TAB(5), TAB(6), USG3);
	// ft_printf("%*c-v N %*c: %s\n", TAB(5), TAB(6), USG4);
	// ft_printf("%*c %s\n", TAB(16), USG41);
	// ft_printf("%*c %s\n", TAB(16), USG42);
	// ft_printf("%*c %s\n", TAB(16), USG43);
	// ft_printf("%*c %s\n", TAB(16), USG44);
	// ft_printf("%*c %s\n", TAB(16), USG45);
	// ft_printf("%*c %s\n", TAB(16), USG46);
	// ft_printf("%.*s %s %.*s\n", SEP, TITLE2, SEPEND(TITLE2));
	// ft_printf("%*c-b %*c: %s\n", TAB(5), TAB(8), USG5);
	// ft_printf("%*c%s\n", TAB(5), USG6);
	// ft_printf("%.*s %s %.*s\n", SEP, TITLE3, SEPEND(TITLE3));
	// ft_printf("%*c-n %*c: %s\n", TAB(5), TAB(8), USG7);
	// ft_printf("%*c%s\n", TAB(5), USG8);
	// ft_printf("%s\n", SEPARATOR);
	return (1);
}
// #### TEXT OUTPUT MODE ############################################################%
