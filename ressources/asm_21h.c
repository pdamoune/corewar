#include "../includes/op.h"

void		ft_exit(int nb, global_t *global, char **line)
{
	char	*errors[20];

	errors[1] = "Le nombre d'arguments en ligne de commande est différent de 2";
	errors[2] = "Erreur dans l'ouverture du fichier de départ";
	errors[3] = "Problème avec le get next line";
	errors[4] = "Erreur dans l'ouverture du fichier de destination";
	errors[10] = "Ceci n'est pas une instruction valide";
	errors[11] = "Le nombre d'arguments pour cette instruction n'est pas valide";
	errors[12] = "Cet argument ne correspond pas aux arguments prévus pour cette instruction";
	errors[13] = "Le nombre d'octets renseignés pour ce DIRECT n'est pas correct";
	errors[14] = "Problème de conversion de base en hexa";
	errors[19] = NULL;
	// nb = 0;
	ft_printf("ERROR n°%d : %s\n", nb, errors[nb]);
	close(global->fdIn);
    free(global); // Penser à free la global en cas d'erreur (fct ft_free.c à créer)
    if (line && *line)
        ft_strdel(line);
	exit(0);
	// exit(EXIT_FAILURE);
}

/*
**  LIS LE FICHIER ET STOCK CHAQUE LINE DANS LA STRUCT MAP
*/

// 0xae6f7c10
// 0xae6f7c11
//
// 00000000 00000000 00000000 00101010

#include <limits.h>

int			main(int argc, char **argv)
{
	// char		*line;
	// global_t	*global;
    // int			gnl;

	(void)&argc;
	(void)&argv;

	char	comment[COMMENT_LENGTH];

	ft_bzero(&comment, COMMENT_LENGTH);
	ft_strcpy(comment, "coucou");
	write("file_name", comment, PROG_NAME_LENGTH)
	write("file_name", prog_name, COMMENT_LENGTH)

	char str[5];

	int *i;

	str[0] = 1;

	i = (int *)&str[1];


	*i = INTREV32(42);

	int fd;
	fd = open("coucou", O_WRONLY);


	// str = (char *)&i;

	write(fd, str, 5);

	// char str[255];
	// int fd;
	//
	// while (i < 255)
	// {
	// 	str[i] = i;
	// 	i++;
	// }

	// write(fd, str, 255);
    // ft_initialize_global(&global);
    // if (argc != 2)
    //     ft_exit(1, global, &line);
	// line = NULL;
    // global->fdIn = open(argv[1], O_RDONLY, 0666);
	// if (-1 == global->fdIn)
	// 	ft_exit(2, global, &line);
	// while ((gnl = get_next_line(global->fdIn, &line)))
	// {
    //     if (gnl == -1)
	// 		ft_exit(3, global, &line);
	// 	ft_stock_map(global, line);
	// 	free(line);
    //     global->nb_lines++;
	// }
	// ft_controller(global);
	// close(global->fdIn);
	return (0);
}
