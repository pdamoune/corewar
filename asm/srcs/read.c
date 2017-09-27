#include "../includes/op.h"

void		ft_exit(int nb, global_t *global, char **line)
{
	char	*errors[20];

	errors[1] = "Le nombre d'arguments en ligne de commande est différent de 2";
	errors[2] = "Erreur dans l'ouverture du fichier de départ";
	errors[3] = "Problème avec le get next line";
	errors[4] = "Erreur dans l'ouverture du fichier de destination";
	errors[5] = "Le nom du fichier est trop long";
	errors[6] = "Le commentaire du fichier est trop long";
	errors[9] = "Le parametre de aff n'est pas un registre";
	errors[10] = "Ceci n'est pas une instruction valide";
	errors[11] = "Le nombre d'arguments pour cette instruction n'est pas valide";
	errors[12] = "Cet argument ne correspond pas aux arguments prévus pour cette instruction";
	errors[13] = "Le nombre d'octets renseignés pour ce DIRECT n'est pas correct";
	errors[14] = "Problème de conversion de base en hexa";
	errors[15] = "Le label recherché n'existe pas";
	errors[19] = NULL;
	// nb = 0;
	ft_printf("ERROR n°%d : %s\n", nb, errors[nb]);
	close(global->fdIn);
    ft_free_global(global);
    if (line && *line)
        ft_strdel(line);
	exit(0);
	// exit(EXIT_FAILURE);
}

int			ft_open(global_t *global)
{
	int		magic_bis;
	int		magic_ter;

	magic_bis = COREWAR_EXEC_MAGIC;
	magic_ter = INTREV32(magic_bis);
	global->fdOut = open("42.cor", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (global->fdOut == -1)
	{
		ft_exit(4, global, NULL);
	}
	else
		write(global->fdOut, &magic_ter, 4);
	return(EXIT_SUCCESS);
}

/*
**  LIS LE FICHIER ET STOCK CHAQUE LINE DANS LA STRUCT MAP
*/

int			main(int argc, char **argv)
{
	char		*line;
	global_t	*global;
    int			gnl;

    ft_initialize_global(&global);
    if (argc != 2)
        ft_exit(1, global, &line);
	line = NULL;
    global->fdIn = open(argv[1], O_RDONLY, 0666);
	if (-1 == global->fdIn)
		ft_exit(2, global, &line);
	ft_open(global);
	while ((gnl = get_next_line(global->fdIn, &line)))
	{
		if (gnl == -1)
			ft_exit(3, global, &line);
		ft_stock_map(global, line);
		free(line);
		global->nb_lines++;
	}
	/* DEBUG Philippe */
	// char str[5];
	// int *i;
	// str[0] = 1;
	// i = (int *)&str[1];
	// *i = INTREV32(1);
	// int fd;
	// fd = open("coucou", O_WRONLY | O_CREAT, 0666);
	// // str = (char *)&i;
	// write(fd, str, 5);
	/* Fin debug Philippe */

	ft_controller(global);
	close(global->fdIn);
	return (0);
}
