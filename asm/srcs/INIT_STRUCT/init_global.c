#include "../includes/op.h"

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
	(*global)->begin_map = NULL;
	(*global)->s_map = NULL;
	(*global)->begin_label = NULL;
	(*global)->s_label = NULL;
}
