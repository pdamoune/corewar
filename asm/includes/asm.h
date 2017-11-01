/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:43:27 by wescande          #+#    #+#             */
/*   Updated: 2017/11/01 12:17:32 by wescande         ###   ########.fr       */
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

typedef struct s_asm	t_asm;
typedef struct s_file	t_file;

int						verbose(t_asm *a, const int level,
			const char *message, ...);
int						ft_strcat_check(char *dest,
			char *src, int *len, int authorized);
int						do_asm(t_asm *a, char *filename);
int						usage(void);
int						check_header(t_asm *a, char *line);
int						check_header_name(t_asm *a, char *line);
int						check_header_comment(t_asm *a, char *line);

typedef struct			s_op
{
	char				*label;
	int					nb_params;
	int					params[MAX_ARGS_NUMBER];
	int					op_code;
	int					cycle;
	char				*description;
	int					ocp;
	int					index;
}						t_op;

// typedef struct			s_global
// {
// 	int					nb_empty;
// 	int					nb_lines;
// 	int					total_octet;
// 	int					i;
// 	int					j;
// 	int					k;
// 	int					i_tab;
// 	int					fdin;
// 	int					fdout;
// 	struct s_map		*begin_map;
// 	struct s_map		*s_map;
// 	struct s_label		*begin_label;
// 	struct s_label		*s_label;
// 	struct s_header		header;
// 	char				res[(2 * CHAMP_MAX_SIZE) + 1];
// 	int					res_pc;
// }						t_global;

typedef struct			s_label
{
	char				*label;
	int					pos_instru;
	int					pos_label;
	t_lx				list_label;
}						t_label;


union				u_value
{
	char			reg;
	short			ind;
	short			index_dir;
	int				dir;
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
	// int					nb_error;
	int					name_len;
	int					comment_len;
	t_lx				list_know_label;
	t_lx				list_unknow_label;
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

typedef struct			s_label
{
	struct s_content	*begin_content;
	struct s_content	*s_content;
	char				*name;
	int					index;
	int					num;
	struct s_label		*next;
	struct s_label		*previous;

}						t_label;

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

/*
**   FONCTIONS DE L'ASM
*/
int		init_asm(t_asm *a, char *filename, int (**f)());


void					ft_controller(t_global *global);
void					ft_parse_label(t_global *global);
void					ft_exit(int nb, t_global *global, char **line);
int						ft_write(t_global *global, char *string, int size);
void					ft_read(t_global *global);
int						ft_find_i(char *line);
void					ft_counting(t_global *global, char *inst_line);
void					ft_browse_file_counting(t_global *global);
void					ft_browse_content(t_global *global);
void					ft_get_opcode(t_global *global, char *line);
void					ft_calcul_octet(t_global *global, char **line);
void					ft_parse_header(t_global *global);
void					ft_comment_is_done(t_global *global, char *com);
int						ft_open(t_global *global, char *str);
void					ft_str_is_header(t_global *global);
char					*ft_strstrchr(char *line, char *pool);
void					ft_erase_cmt(char *line);
/*
**   FONCTIONS FREE
*/
void					ft_free_global(t_global *global);
void					ft_free_map(t_global *global);
void					ft_free_labels(t_global *global);
void					ft_free_content(t_global *global);
/*
**   FONCTIONS INIT_STRUCT DE L'ASM
*/
void					ft_initialize_global(t_global **global);
void					ft_initialize_map(t_map **map, char *line);
void					ft_stock_map(t_global *global, char *line);
void					ft_initialize_label(t_label **label);
void					ft_stock_label(t_global *global);
void					ft_initialize_content(t_content **content, char *line);
void					ft_stock_content(t_global *global, char *line);
void					ft_browse_label(t_global *global, int type);
void					ft_initialize_header(t_header **header);
void					ft_initialize_content_null(t_content **content,
	char *line);
/*
**   LIBRAIRIES ASM (en complément de LIBFT)
*/
int						is_labelchars(int c);
char					*ft_strstart(const char *big, const char *little);
char					*ft_strchrstart(const char *big, const char *little);
char					*ft_str_mod(const char *big, const char *little);
char					*ft_big_till_space(char *big);
int						ft_strsubc_nb(char *s, char c);
char					*ft_strdup_asm(const char *s);
char					**ft_strsplit_spa(char const *str);
char					**ft_strsplit_virg(char const *str);
char					**ft_strsplit_cmt(char const *str);
char					**ft_split_tab(char **tab1);
void					ft_print_lines(char **tab);
char					*ft_convert_base(char *nbr,
	int len_from, int len_to);
char					*ft_arg(char *arg, int param, int type);
char					*ft_convert_hexa(t_global *global,
	char *arg, int type, int nb_octet);
int						ft_isstrdigit(char *s);
int						ft_isdigitspace(char *s);
int						ft_isstrint(char *s);
int						ft_strlen_tab(char **tab);
int						go_to_label(char *label, t_global *global);
char					*ft_free_strjoin(char **s1, char **s2);
char					*ft_strndup(char *s, int i);

/*
**   FONCTIONS DE TRADUCTIONS
*/

char					*ft_central(t_global *global, char **line);
char					*ft_central2(t_global *global,
		char **line, int i, char **arg);
char					*ft_central3(t_global *global,
		char **line, int i, char **arg);

/*
**	SOUS-FONCTIONS DE TRADUCTION
*/
void					ft_get_values(t_global *global, char **line);
void					gal_fct(t_global *global, char *arg_tmp);

#endif
