/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:57:40 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/12 17:12:15 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/libft.h"

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define ARG_CODE				4


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

/*
*****************************************************************************
*****************************************************************************
*****************************************************************************
*/
/*
**  STRUCTURES DE BASES DE L'ASM
*/

typedef struct		global_s
{
	int				nb_empty;
	int	    		nb_lines;
	char			**index_tab;
	int				total_octet;
	int	    		i;
	int	    		j;
	int	    		k;
	int	    		fdIn;
	int				fdOut;
	struct map_s	*begin_map;
	struct map_s	*s_map;
	struct label_s	*begin_label;
	struct label_s	*s_label;
	struct header_s	header;
	char			res[CHAMP_MAX_SIZE + 1];
	int				res_pc;
}					global_t;

typedef struct		label_s
{
	struct content_s	*begin_content;
	struct content_s	*s_content;
	char				*name;
	int					index;
	int					num;
	struct label_s		*next;
	struct label_s		*previous;

}					label_t;

typedef struct		content_s
{
	char				**line;
	int					nb_octet;
	int					begin_octet;
	char				*instruction;
	struct content_s	*next;
	struct content_s	*previous;
}					content_t;

typedef struct		map_s
{
	char			*line;
	struct map_s	*next;
	struct map_s	*previous;
}					map_t;

typedef	struct	s_var
{
	int				chaine;
	int				mot;
	int				lettre;
	struct s_var	*next;
}				t_var;

/*
**   DEFINE
*/
#define EMPTY_LINE				1
#define COMMENT					2
#define WITH_LABEL				3
#define EMPTY_LABEL		       	4
#define HEADER		     	    5

#define OCTET					0
#define STOCK					1
/*
**   FONCTIONS DE L'ASM
*/
void	ft_controller(global_t *global);
void	ft_parse_label(global_t *global);
void	ft_exit(int nb, global_t *global, char **line);
int		ft_write(global_t *global, char *string, int size);
void	ft_read(global_t *global, char *filename, char *line);
int		ft_find_index(global_t *global, char *line);
void	ft_counting(global_t *global, char *inst_line);
void	ft_browse_file_counting(global_t *global);
void	ft_browse_content(global_t *global);
void	ft_get_opcode(global_t *global, char *line);
void	ft_calcul_octet(global_t *global, char **line, int arg_ind);
void	ft_parse_header(global_t *global);
int		ft_open(global_t *global, char *str);
void	ft_str_is_header(global_t *global);
/*
**   FONCTIONS FREE
*/
void	ft_free_global(global_t *global);
void	ft_free_map(global_t *global);
void	ft_free_labels(global_t *global);
void	ft_free_content(global_t *global);
/*
**   FONCTIONS INIT_STRUCT DE L'ASM
*/
void	ft_initialize_global(global_t **global);
void	ft_initialize_map(map_t **map, char *line);
void	ft_stock_map(global_t *global, char *line);
void	ft_initialize_label(label_t **label);
void	ft_stock_label(global_t *global);
void	ft_initialize_content(content_t **content, char *line);
void	ft_stock_content(global_t *global, char *line);
void	ft_browse_label(global_t *global, int type);
void	ft_initialize_header(header_t **header);
void	ft_initialize_content_null(content_t **content, char *line);
/*
**   LIBRAIRIES ASM (en complément de LIBFT)
*/
int		is_labelchars(int c);
char	*ft_strstart(const char *big, const char *little);
char	*ft_strstart_modif(const char *big, const char *little);
char	*ft_big_till_space(char *big);
char	*ft_strsubc(char **s, char c);
char	*ft_strdup_asm(const char *s);
char	**ft_strsplit_spa(char const *str);
char	**ft_strsplit_virg(char const *str);
char	**ft_strsplit_cmt(char const *str);
char	**ft_split_tab(char **tab1);
void	ft_print_lines(char **tab);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_arg(char *arg, int param, int type);
char	*ft_convert_hexa(global_t *global, char *arg, int type, int nb_octet);
int		ft_isstrdigit(char *s);
int		ft_isdigitspace(char *s);
int		ft_isstrint(char *s);
void	ft_free_tab(char **tab);
int		ft_strlen_tab(char **tab);
int		go_to_label(char *label, global_t *global);
char	*ft_free_strjoin(char **s1, char **s2);
/*
**   FONCTIONS DE TESTS POUR DEBUG -- A supprimer
*/
void	DEBUG_read_map(global_t *global);
void	DEBUG_read_labels(global_t *global);
void	DEBUG_read_content(global_t *global);
void	ft_print_words_tables(char **tab);
/*
**   FONCTIONS DE TRADUCTIONS
*/
enum				e_conversion
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
	direct = 16,
	indirect = 22,
	R = 17,
	Name_CMD_STRING = 18,
	Comment_CMD_STRING = 19,
	Comment_CHAR = 20,
	Other_CMD_STRING = 21,
};
void	ft_pointeur_tab(global_t *global, int index, int one_arg, int arg_ind);
char	*(*p_tab[25])(global_t *, char **line);
// char	*live_instruct(global_t *global, char **line);
char	*ld_instruct(global_t *global, char **line);
char	*st_instruct(global_t *global, char **line);
char	*add_instruct(global_t *global, char **line);
char	*and_instruct(global_t *global, char **line);
char	*sub_instruct(global_t *global, char **line);
char	*and_instruct(global_t *global, char **line);
char	*or_instruct(global_t *global, char **line);
char	*xor_instruct(global_t *global, char **line);
// char	*zjmp_instruct(global_t *global, char **line);
char	*ldi_instruct(global_t *global, char **line);
char	*sti_instruct(global_t *global, char **line);
// char	*fork_instruct(global_t *global, char **line);
char	*lld_instruct(global_t *global, char **line);
char	*lldi_instruct(global_t *global, char **line);
// char	*lfork_instruct(global_t *global, char **line);
char	*aff_instruct(global_t *global, char **line);
// char	*direct_param(global_t *global, char **line);
// char	*indirect_param(global_t *global, char **line);
// char	*register_param(global_t *global, char **line);
// char	*cmd_string(global_t *global, char **line);
// char	*comments_string(global_t *global, char **line);
// char	*others_string(global_t *global, char **line);
/*
**	SOUS-FONCTIONS DE TRADUCTION
*/
void	ft_get_values(global_t *global, char **line, int arg_ind);
void        general_fct(global_t *global, int one_arg, char *arg_tmp, int arg_ind);
char	*ft_compose_arg_and_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_ld_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_st_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_add_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_sub_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_or_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_xor_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_ldi_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_sti_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_lld_bis(global_t *global, char **line, int i, char **arg);
char	*ft_compose_arg_lldi_bis(global_t *global, char **line, int i, char **arg);
