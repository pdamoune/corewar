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

int			main(int argc, char **argv)
{
	char		*line;
	global_t	*global;
    int			gnl;
	int			fd;

    global = ft_initialize_global();
    if (argc != 2)
        ft_exit(1, global, &line);
	line = NULL;
    fd = open(argv[1], O_RDONLY);
	while ((gnl = get_next_line(fd, &line)))
	{
        if (gnl == -1)
			ft_exit(3, global, &line);
		ft_stock(global, line);
		free(line);
	}
	// ft_execute(global); fonction à utiliser pour travailler sur le fichier
	get_next_line(-2, NULL);
    DEBUG_read_map(global);
	return (0);
}
