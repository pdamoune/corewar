/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_r.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:27:04 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/16 19:43:39 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_R_H
# define ASM_R_H

# include <libft.h>
# include <op.h>
# include <errno.h>

# define DEBUG			(1 << 0)
# define VERBOSE		(1 << 1)
# define QUIET			(1 << 2)

# define MSG_STD		0
# define MSG_INFO		1
# define MSG_WARNING	2
# define MSG_DEBUG		3
# define MSG_ERROR		4
# define MSG_SUCESS		5
# define MSG_STD_G		6

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_file
{
	char			*filename; // .cor
	t_header		header;
	char			prog[CHAMP_MAX_SIZE + 1];
}					t_file;

typedef struct		s_asm_r
{
	uint64_t		flag;
	char			**av_data;
	t_file			file;
}					t_asm_r;

void 		display(t_file *file);

int			main(int ac, char **av);
int 		usage(void);
int			verbose(t_asm_r *asm_r, const int level, const char *message, ...);
int			init_asm_r(t_asm_r *asm_r, char ***av);

#endif
