/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:10:59 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/18 16:28:14 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
# define	USG			"Usage:"
# define	FILE_NAME	name
# define	OPT1		"[-d N -s N -v N | -b --stealth | -n --stealth]"
# define	OPT2		"[-a]"
# define	OPT3		"<champion1.cor>"
# define	OPT4		"<...>"

# define	USG1		""
# define	USG2		"Prints output from \"aff\" (Default is to hide it)"
# define	USG3		""

# define	TAB1		5, 0
# define	TAB2		9, 0
# define	TAB3		0, 0

# define	SERPARATOR	"########################################"

int		usage(char *name)
{
	ft_prf("{bol}{ita}%s %s %s %s %s %s{eoc}\n", USG, FILE_NAME, OPT1, OPT2, OPT3, OPT4);
	ft_prf("%*c-a%*c: %s\n", TAB1, TAB2, USG2);
	ft_prf("");
	return (0);
}
