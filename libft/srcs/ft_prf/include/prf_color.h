/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:55:57 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/09 00:00:20 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_COLOR_H
# define PRF_COLOR_H
# include "ft_prf.h"

# define ALL_DEFAULT	"\e[0m"
# define T_BOLD			"\e[1m"
# define T_ITALIC		"\e[3m"
# define T_UNDERLINED	"\e[4m"
# define T_INVERTED		"\e[7m"
# define C_BLACK		"\e[30m"
# define C_GREY			"\e[2m"
# define C_RED			"\e[31m"
# define C_GREEN		"\e[32m"
# define C_YELLOW		"\e[33m"
# define C_BLUE			"\e[34m"
# define C_MAGENTA		"\e[35m"
# define C_CYAN			"\e[36m"
# define C_WHITE		"\e[37m"
# define C_DEFAULT		"\e[39m"
# define BG_BLACK		"\e[40m"
# define BG_RED			"\e[41m"
# define BG_GREEN		"\e[42m"
# define BG_YELLOW		"\e[43m"
# define BG_BLUE		"\e[44m"
# define BG_MAGENTA		"\e[45m"
# define BG_CYAN		"\e[46m"
# define BG_WHITE		"\e[47m"
# define BG_DEFAULT		"\e[49m"

typedef struct s_color	t_color;

struct		s_color
{
	char	flag_c[5];
	char	code_c[5];
};

#endif
