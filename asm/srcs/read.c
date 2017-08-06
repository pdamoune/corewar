#include "../includes/op.h"

void		ft_exit(int nb, global_t *global, char **line)
{
	char	*errors[20];

	errors[1] = "Le nombre d'arguments est différent de 2";
	errors[2] = "Problème avec le get next line";
	errors[10] = "Ceci n'est pas une instruction";
	errors[11] = "Le nombre d'arguments pour cette instruction n'est pas valide";
	errors[12] = "Cet argument ne correspond pas à celui attendu";
	errors[19] = NULL;
	// nb = 0;
	ft_printf("ERROR n°%d : %s\n", nb, errors[nb]);
    free(global); // Penser à free la global en cas d'erreur (fct ft_free.c à créer)
    if (line && *line)
        ft_strdel(line);
	exit(0);
}

/*
**  LIS LE FICHIER ET STOCK CHAQUE LINE DANS LA STRUCT MAP
*/

int			main(int argc, char **argv)
{
	char		*line;
	global_t	*global;
    int			gnl;
    int			fd;

    ft_initialize_global(&global);
    if (argc != 2)
        ft_exit(1, global, &line);
	line = NULL;
    fd = open(argv[1], O_RDONLY);
	while ((gnl = get_next_line(fd, &line)))
	{
        if (gnl == -1)
			ft_exit(2, global, &line);
		ft_stock_map(global, line);
		free(line);
        global->nb_lines++;
	}
	ft_controller(global);
	get_next_line(-2, NULL);
	return (0);
}
