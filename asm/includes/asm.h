/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:43:27 by wescande          #+#    #+#             */
/*   Updated: 2017/11/01 22:32:36 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <libft.h>
# include <op.h>

# define VERBOSE		(1 << 0)
# define QUIET			(1 << 1)
# define DEBUG			(1 << 2)
# define CONTINUE		(1 << 3)

# define HEAD_NAME		(1 << 0)
# define HEAD_COMMENT	(1 << 1)
# define LEN_WARNING	(1 << 2)
# define LEN_ERROR		(1 << 3)

# define MSG_STD		0
# define MSG_INFO		1
# define MSG_WARNING	2
# define MSG_DEBUG		3
# define MSG_ERROR		4
# define MSG_SUCESS		5
# define MSG_STD_G		6

# define PROG_SIZE		a->file.header.prog_size

typedef struct s_asm	t_asm;
typedef struct s_file	t_file;

int						verbose(t_asm *a, const int level,
			const char *message, ...);
int						ft_strcat_check(char *dest,
			char *src, int *len, int authorized);
int						do_asm(t_asm *a, char *filename);
int						usage(void);
int						check_file_content(t_asm *a, char *line);
int						check_header(t_asm *a, char *line);
int						check_header_name(t_asm *a, char *line);
int						check_header_comment(t_asm *a, char *line);
int						init_name_header(t_asm *a, char *line);
int						init_comment_header(t_asm *a, char *line);
int						init_asm(t_asm *a, char *filename, int (**f)());
// static int				check_filename(t_asm *a, char *filename);

/*** TOOLS */
int						skip_spa(char **line);
int						check_label(t_asm *a);
char					*is_label(char *line);
int						count_nb_args(char *line);
int						ft_spastrcmp(char *spastr, char *str);

typedef struct			s_op
{
	char				*instruc;
	int					nb_params;
	int					params[MAX_ARGS_NUMBER];
	int					op_code;
	int					cycle;
	char				*description;
	int					ocp;
	int					index;
}						t_op;

typedef struct			s_label
{
	char				*label;
	int					pos_instru;
	int					pos_label;
}						t_label;


union				u_value
{
	unsigned char	reg;
	unsigned short	ind;
	unsigned short	index_dir;
	unsigned int	dir;
};

typedef struct			s_argument
{
	int					type;
	union u_value		value;
	t_label				*label;
}						t_argument;

struct					s_file
{
	uint64_t			flag;
	char				*filename;
	int					fdin;
	char				*line;
	int					line_number;
	// int				nb_error;
	int					name_len;
	int					comment_len;
	t_ld				*list_know_label;
	t_ld				*list_unknow_label;
	t_header			header;
	char				prog[(2 * CHAMP_MAX_SIZE) + 1];
	// t_global			global;
};

struct					s_asm
{
	uint64_t			flag;
	char				**av_data;
	t_file				file;
};

// typedef struct			s_label
// {
// 	struct s_content	*begin_content;
// 	struct s_content	*s_content;
// 	char				*name;
// 	int					index;
// 	int					num;
// 	struct s_label		*next;
// 	struct s_label		*previous;
//
// }						t_label;

typedef struct			s_content
{
	char				**line;
	int					nb_octet;
	int					begin_octet;
	char				*instruction;
	struct s_content	*next;
	struct s_content	*previous;
}						t_content;

typedef struct			s_map
{
	char				*line;
	struct s_map		*next;
	struct s_map		*previous;
}						t_map;

typedef	struct			s_var
{
	int					chaine;
	int					mot;
	int					lettre;
	struct s_var		*next;
}						t_var;

/*
**   DEFINE
*/

# define EMPTY_LINE		1
# define COMMENT		2
# define WITH_LABEL		3
# define EMPTY_LABEL	4
# define HEADER			5

# define OCTET			0
# define STOCK			1
# define G_L_C			global->s_label->s_content
# define ITAB			global->i_tab

#endif
