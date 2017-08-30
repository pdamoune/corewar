#include "../includes/op.h"

void		ft_initialize_map(map_t **map, char *line)
{
	if (!(*map = (map_t*)malloc(sizeof(map_t))))
		return ;
	(*map)->line = ft_strdup(line);
    (*map)->next = NULL;
	(*map)->previous = NULL;
}

/*
**  STOCKE CHAQUE LINE DANS LA STRUCT MAP
*/

void		ft_stock_map(global_t *global, char *line)
{
    map_t	*new;
    map_t	*previous;

    new = NULL;
    previous = NULL;
    ft_initialize_map(&new, line);
    if (!global->begin_map)
        global->begin_map = new;
    else
    {
        previous = global->s_map;
        new->previous = previous;
        previous->next = new;
    }
    global->s_map = new;
}
