/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:43:27 by wescande          #+#    #+#             */
/*   Updated: 2017/11/04 01:59:18 by wescande         ###   ########.fr       */
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


typedef struct			s_op
{
	char				*instruc;
	int					nb_params;
	uint8_t				params[MAX_ARGS_NUMBER];
	uint8_t				op_code;
	int					cycle;
	char				*description;
	uint8_t				ocp;
	uint8_t				index;
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
	// int					fdin;
	char				*line;
	int					line_number;
	// int				nb_error;
	int					name_len;
	int					comment_len;
	t_ld				*list_know_label;
	t_ld				*list_unknow_label;
	t_header			header;
	char				prog[(2 * CHAMP_MAX_SIZE) + 1];
};

struct					s_asm
{
	uint64_t			flag;
	char				**av_data;
	t_file				file;
};

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
int						analyze_each_arguments(t_asm *a, t_op *cur_instru,
							char **arg, t_argument *parsed_args);
int						free_arguments(t_op *cur_instru, t_argument *parsed_args);
int						stock_instruction(t_asm *a, t_op *cur_instru, t_argument *parsed_args, uint8_t ocp);
int						stock_argument(t_asm *a, uint16_t pos, t_argument *arg, uint8_t index);

/*
** TOOLS
*/

int						skip_spa(char **line);
int						count_nb_args(char *line);
int						ft_spastrcmp(char *spastr, char *str);
int						ft_spastrisnumeral(const char *str);
char					*type_to_str(int type);
void 					remove_label(t_ld **rip);
t_op				*is_instruction(char **line);
uint8_t					calcul_instruction_len(uint8_t op_code, uint8_t ocp);
uint8_t					calcul_ocp(int	nb_params, t_argument *parsed_args);
uint8_t					calcul_type_from_ocp(uint8_t ocp, uint8_t index);

/*
** LABEL TREAT
*/
void					free_label(t_label *rip);
t_ld					**find_label(t_ld **head_list, char *name);
void			replace_label(t_asm *a, t_label *label, t_ld **target);
int						check_label(t_asm *a);
char					*is_label(char *line);
char					*is_arg_label(char *line);
int						analyze_arg_label(t_asm *a, char *arg,
									t_argument *parsed_args, char *end_of_label);

#endif
