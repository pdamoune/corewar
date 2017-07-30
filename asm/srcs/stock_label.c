#include "../includes/op.h"

static int		ft_initialize_label(label_t **label)
{
	if (!(*label = (label_t*)malloc(sizeof(label_t))))
		return (0);
	(*label)->content = NULL;
    (*label)->name = NULL;
	(*label)->nb_octet = 0;
	return (0);
}

/*
**  STOCK CHAQUE LABEL & CO DANS LA STRUCT LABEL STOCKEE DANS UN TABLEAU
*/

void		ft_stock_label(global_t *global)
{
	label_t	*new;

	new = NULL;
	ft_initialize_label(&new);
	global->s_map = global->begin_map;
    while (global->s_map)
    {
    	global->s_map = global->s_map->next;
    }
	/* Créér la fonction qui va identifier les blocs avec les labels correspondants
		Fonction à compléter - EN COURS */
}
