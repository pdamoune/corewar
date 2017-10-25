/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:13:39 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 18:52:48 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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

void				ft_exit(int nb, t_global *global, char **line)
{
	ft_printf("ERROR n°%d : %s\n", nb, g_errors[nb - 1]);
	close(global->fdin);
	ft_free_global(global);
	DG();
	if (line && *line)
		ft_strdel(line);
	exit(0);
}

int					ft_open(t_global *global, char *str)
{
	int		magic_bis;

	magic_bis = COREWAR_EXEC_MAGIC;
	global->header.magic = bswap_32(magic_bis);
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

void				ft_read(t_global *global)
{
	int			gnl;
	int			k;
	char		*line;

	while ((gnl = get_next_line(global->fdin, &line)) > 0)
	{
		k = 0;
		if (gnl == -1 || !ft_isascii(line[0]))
			ft_exit(3, global, &line);
		while (line[k] == ' ' || line[k] == '\t')
			k++;
		if (!ft_strchr(COMMENT_CHAR, line[k]))
			ft_stock_map(global, line);
		global->nb_lines++;
		free(line);
	}
	ft_controller(global);
}

static t_cliopts	g_read_opts[] =
{
	{'D', "debug", DEBUG, 0, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	{'c', "continue", CONTINUE, 0, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int					ft_strcat_check(char *dest,
			char *src, int *len, int authorized)
{
	while (*src)
	{
		if (*len > authorized)
			return (-1);
		dest[*len] = *src;
		++(*len);
		++src;
	}
	dest[*len] = '\0';
	return (0);
}

int					main(int ac, char **av)
{
	t_asm		a;
	int			ret;

	if (ac == 1)
		return (usage());
	ft_bzero(&a, sizeof(t_asm));
	if ((cliopts_get(av, g_read_opts, &a)))
		return (ft_perror("asm") && usage());
	if (!a.av_data)
		return (usage());
	ret = 0;
	while (*a.av_data)
	{
		ret += do_asm(&a, *a.av_data++);
		if (ret && IS_UNSET(a.flag, CONTINUE))
			return (ret);
	}
	return (ret);
}
