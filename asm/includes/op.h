/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:57:40 by clegoube          #+#    #+#             */
/*   Updated: 2017/07/26 21:57:04 by clegoube         ###   ########.fr       */
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
**  STRUCTURES DE BASES DE L'ASM
*/

typedef struct		global_s
{
	char			**gnl_tab; /* A voir si on conserve ou supprime */
	int				nb_empty;
    int	    		nb_lines;
    struct map_s	*begin_map;
	struct map_s	*s_map;
	struct label_s	*label_tab; /* Tableau de strcutures */
}					global_t;

typedef struct		label_s
{
	char			**content;
	char			*name;
	int				nb_octet;
}					label_t;

typedef struct		map_s
{
	char			*line;
    struct map_s	*next;
	struct map_s	*previous;
}					map_t;

/*
**   FONCTIONS DE L'ASM
*/
void		ft_stock_map(global_t *global, char *line);
void		ft_controller(global_t *global);
void		ft_stock_label(global_t *global);

/*
**   LIBRAIRIES ASM (en complément de LIBFT)
*/

/*
**   FONCTIONS DE TESTS POUR DEBUG -- A supprimer
*/
void        DEBUG_read_map(global_t *global);
