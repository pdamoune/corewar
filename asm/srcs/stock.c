#include "../includes/op.h"

static int		ft_initialize_map(map_t **map, char *line)
{
	if (!(*map = (map_t*)malloc(sizeof(map_t))))
		return (0);
	(*map)->line = ft_strdup(line);
    (*map)->next = NULL;
	(*map)->previous = NULL;
	return (0);
}

void		ft_stock(global_t *global, char *line)
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
