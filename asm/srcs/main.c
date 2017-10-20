/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:13:39 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/20 17:36:20 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static char		*g_errors[20] =
{
	"Le nombre d'arguments en ligne de commande est différent de 2",
	"Erreur dans l'ouverture du fichier de départ",
	"Lecture du fichier impossible",
	"Erreur dans l'ouverture du fichier de destination",
	"Le nom du fichier est trop long",
	"Le commentaire du fichier est trop long",
	"Le champion a mangé trop de nougat, il est trop gros",
	"Lexical error",
	"Le parametre de aff n'est pas un registre",
	"Ceci n'est pas une instruction valide",
	"Le nombre d'arguments pour cette instruction n'est pas valide",
	"Cet argument ne correspond pas aux arguments prévus",
	"Le nombre d'octets renseignés pour ce DIRECT n'est pas correct",
	"Problème de conversion de base en hexa",
	"Le label recherché n'existe pas",
	"Le header donne n'est ni un name, ni un comment",
};

void			ft_exit(int nb, t_global *global, char **line)
{
	ft_printf("ERROR n°%d : %s\n", nb, g_errors[nb - 1]);
	close(global->fdin);
	ft_free_global(global);
	if (line && *line)
		ft_strdel(line);
	exit(0);
}

int				ft_open(t_global *global, char *str)
{
	int		magic_bis;

	magic_bis = COREWAR_EXEC_MAGIC;
	global->header.magic = INTREV32(magic_bis);
	global->fdout = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (global->fdout == -1)
	{
		ft_exit(4, global, NULL);
	}
	else
		write(global->fdout, &global->header, sizeof(t_header));
	return (EXIT_SUCCESS);
}

/*
**  LIS LE FICHIER ET STOCK CHAQUE LINE DANS LA STRUCT MAP
*/

void			ft_read(t_global *global, char *filename, char *line)
{
	int			gnl;
	int			k;

	global->fdin = open(filename, O_RDONLY, 0666);
	if (-1 == global->fdin)
		ft_exit(2, global, &line);
	while ((gnl = get_next_line(global->fdin, &line)))
	{
		k = 0;
		if (gnl == -1 || !ft_isascii(line[0]))
			ft_exit(3, global, &line);
		while (line[k] == ' ' || line[k] == '\t')
			k++;
		if (!ft_strchr(COMMENT_CHAR, line[k]))
			ft_stock_map(global, line);
		free(line);
		global->nb_lines++;
	}
	ft_controller(global);
}

int				main(int argc, char **argv)
{
	char		*line;
	t_global	*global;
	int			i;
	size_t		len;
	char		*title;

	i = 0;
	ft_initialize_global(&global);
	if (argc < 2)
		ft_exit(1, global, &line);
	line = NULL;
	while (++i < argc)
	{
		len = ft_strstr(argv[i], ".s") ?
		ft_strstr(argv[i], ".s") - argv[i] : ft_strlen(argv[i]);
		title = malloc(len + 5);
		ft_memcpy(title, argv[i], len);
		ft_memcpy(title + len, ".cor", 5);
		ft_read(global, argv[i], line);
		ft_open(global, title);
		write(global->fdout, global->res, global->total_octet);
		close(global->fdin);
		ft_putstr("Writing output program to ");
		ft_putendl(title);
	}
	return (0);
}
