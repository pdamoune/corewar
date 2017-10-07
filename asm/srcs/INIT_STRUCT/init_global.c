#include "../includes/op.h"

char	**ft_index_tab()
{
	char **tab;

	if (!(tab = (char **)malloc(25 * sizeof(*tab))))
		return (NULL);

	tab[0] = ft_strdup("live");
	tab[1] = ft_strdup("add");
	tab[2] = ft_strdup("sub");
	tab[3] = ft_strdup("and");
	tab[4] = ft_strdup("or");
	tab[5] = ft_strdup("xor");
	tab[6] = ft_strdup("zjmp");
	tab[7] = ft_strdup("sti");
	tab[8] = ft_strdup("st");
	tab[9] = ft_strdup("fork");
	tab[10] = ft_strdup("lldi");
	tab[11] = ft_strdup("lld");
	tab[12] = ft_strdup("ldi");
	tab[13] = ft_strdup("ld");
	tab[14] = ft_strdup("lfork");
	tab[15] = ft_strdup("aff");
	tab[16] = ft_strdup("%");
	tab[17] = ft_strdup("r");
	tab[18] = ft_strdup(NAME_CMD_STRING);
	tab[19] = ft_strdup(COMMENT_CMD_STRING);
	tab[20] = ft_strdup("#");
	tab[21] = ft_strdup(".");
	tab[22] = ft_strdup("");
	tab[23] = NULL;
	return (tab);
}

/*
**  INITIALISE LA GLOBALE UTILISEE DANS TOUT LE PROGRAMME
*/

void	ft_initialize_global(global_t **global)
{

	if (!(*global = (global_t*)malloc(sizeof(global_t))))
		return ;
    (*global)->nb_empty = 0;
	(*global)->nb_lines = 0;
	(*global)->i = 0;
	(*global)->j = 0;
	(*global)->k = 0;
	(*global)->total_octet = 0;
	(*global)->fdIn = 0;
	(*global)->fdOut = 0;
	(*global)->begin_map = NULL;
	(*global)->s_map = NULL;
	(*global)->begin_label = NULL;
	(*global)->s_label = NULL;
	(*global)->header = NULL;
	(*global)->str_till_now = NULL;
	(*global)->index_tab = ft_index_tab();
}

void	ft_initialize_header(header_t **new)
{
	unsigned int	magic_bis;

	magic_bis = COREWAR_EXEC_MAGIC;
	if (!(*new = (header_t*)malloc(sizeof(header_t))))
		return ;
	(*new)->magic = INTREV32(magic_bis);
	ft_bzero((*new)->prog_name, PROG_NAME_LENGTH + 1);
	(*new)->prog_size = 0;
	ft_bzero((*new)->comment, COMMENT_LENGTH + 1);
}