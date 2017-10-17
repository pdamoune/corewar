/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_r.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:27:04 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/18 00:18:48 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_R_H
# define ASM_R_H

# include <libft.h>
# include <op.h>
# include <errno.h>

# define FILE_EXT		"des"

# define DEBUG			(1 << 0)
# define VERBOSE		(1 << 1)
# define QUIET			(1 << 2)

# define MSG_STD		0
# define MSG_INFO		1
# define MSG_WARNING	2
# define MSG_DEBUG		3
# define MSG_ERROR		4
# define MSG_SUCESS		5

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_file
{
	char			*filename;
	t_header		header;
	char			prog[CHAMP_MAX_SIZE + 1];
}					t_file;

typedef struct		s_asm_r
{
	uint64_t		flag;
	char			**av_data;
	t_file			file;
}					t_asm_r;

typedef struct		s_op
{
	char	*label;
	int		nb_params;
	int		params[MAX_ARGS_NUMBER];
	int		op_code;
	int		cycle;
	char	*description;
	int		ocp;
	int		index;
}					t_op;

int		usage(void);
int		verbose(t_asm_r *asm_r, const int level, const char *message, ...);
int		main(int ac, char **av);
int		init_file(t_asm_r *asm_r, t_file *file, char *filename);
int		create_file(t_asm_r *asm_r, t_file *file);
int		instru(t_asm_r *asm_r, int fd, t_op op, char **prog);
void	get_type(unsigned char ocp, int nb_params, unsigned int *type);
unsigned int	get_value(char *prog, t_op op, unsigned int type, int *pc_inc);

#endif
