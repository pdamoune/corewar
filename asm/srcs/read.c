#include "../includes/op.h"

void		ft_exit(int nb, global_t *global, char **line)
{
	nb = 0;
	ft_printf("ERROR n°%d\n", nb);
    free(global); // Penser à free la global en cas d'erreur (fct ft_free.c)
    if (line && *line)
        ft_strdel(line);
	exit(0);
}

global_t	*ft_initialize_global(void)
{
	global_t *global;

	if (!(global = (global_t*)malloc(sizeof(global_t))))
		return (NULL);
	global->nb_empty = 0;
	global->begin_map = NULL;
	global->label_tab = NULL;
	global->gnl_tab = NULL;
	return (global);
}

map_t	*ft_initialize_map(void)
{
	map_t *map;

	if (!(map = (map_t*)malloc(sizeof(map_t))))
		return (NULL);
	map->line = NULL;
	map->next = NULL;
	return (map);
}

int			main(void)
{
	char		*line;
	global_t	*global;
	int			gnl;

	global = ft_initialize_global();
	line = NULL;
	gnl = get_next_line(0, &line);
    ft_printf("%s\n",line);
	if (gnl == 0 || gnl == -1)
		ft_exit(2, global, &line);
	free(line);
	while ((gnl = get_next_line(0, &line)))
	{
        ft_printf("%s\n",line);
        if (gnl == -1)
			ft_exit(3, global, &line);
		// ft_stocke(global, &line); fonction à utiliser pour stocker les donnees du fichier
		free(line);
	}
	// ft_execute(global); fonction à utiliser pour travailler sur le fichier
	get_next_line(-2, NULL);
	return (0);
}
