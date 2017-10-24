/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:57:40 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/24 15:36:29 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# include <stdio.h>
# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/libft.h"

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define ARG_CODE				4

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			"#;"
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char			t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

/*
*****************************************************************************
*****************************************************************************
*****************************************************************************
*/
/*
**  STRUCTURES DE BASES DE L'ASM
*/

typedef struct					s_op
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

typedef struct			s_global
{
	int					nb_empty;
	int					nb_lines;
	char				**index_tab;
	int					total_octet;
	int					i;
	int					j;
	int					k;
	int					i_tab;
	int					fdin;
	int					fdout;
	struct s_map		*begin_map;
	struct s_map		*s_map;
	struct s_label		*begin_label;
	struct s_label		*s_label;
	struct s_header		header;
	char				res[(2 * CHAMP_MAX_SIZE) + 1];
	int					res_pc;
}						t_global;

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

# define EMPTY_LINE				1
# define COMMENT				2
# define WITH_LABEL				3
# define EMPTY_LABEL	       	4
# define HEADER		     	    5

# define OCTET					0
# define STOCK					1

/*
**   FONCTIONS DE L'ASM
*/

void					ft_controller(t_global *global);
void					ft_parse_label(t_global *global);
void					ft_exit(int nb, t_global *global, char **line);
int						ft_write(t_global *global, char *string, int size);
void					ft_read(t_global *global, char *filename, char *line);
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

enum					e_conversion
{
	live = 0,
	ld = 13,
	st = 8,
	add = 1,
	sub = 2,
	and = 3,
	or = 4,
	xor = 5,
	zjmp = 6,
	ldi = 12,
	sti = 7,
	FORK = 9,
	lld = 11,
	lldi = 10,
	lfork = 14,
	aff = 15,
};

char	*ft_central(t_global *global, char **line);
char	*ft_central2(t_global *global, char **line, int i, char **arg);
char	*ft_central3(t_global *global, char **line, int i, char **arg);

void					ft_g_ptr_tab(t_global *global,
	int index, int one_arg, int arg_ind);
char					*(*g_ptr_tab[25])(t_global *, char **line);
char					*ld_instruct(t_global *global, char **line);
char					*st_instruct(t_global *global, char **line);
char					*add_instruct(t_global *global, char **line);
char					*and_instruct(t_global *global, char **line);
char					*sub_instruct(t_global *global, char **line);
char					*and_instruct(t_global *global, char **line);
char					*or_instruct(t_global *global, char **line);
char					*xor_instruct(t_global *global, char **line);
char					*ldi_instruct(t_global *global, char **line);
char					*sti_instruct(t_global *global, char **line);
char					*lld_instruct(t_global *global, char **line);
char					*lldi_instruct(t_global *global, char **line);
char					*aff_instruct(t_global *global, char **line);
/*
**	SOUS-FONCTIONS DE TRADUCTION
*/
void					ft_get_values(t_global *global, char **line);
void					gal_fct(t_global *global, char *arg_tmp);
char					*ft_arg_and_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_ld_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_st_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_add_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_sub_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_or_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_xor_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_ldi_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_sti_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_lld_bis(t_global *global,
	char **line, int i, char **arg);
char					*ft_arg_lldi_bis(t_global *global,
	char **line, int i, char **arg);

#endif
