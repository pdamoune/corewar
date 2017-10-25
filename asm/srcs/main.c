/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 17:13:39 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:23 by tdebarge         ###   ########.fr       */
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

void			ft_exit(int nb, t_global *global, char **line)
{
	ft_printf("ERROR n°%d : %s\n", nb, g_errors[nb - 1]);
	close(global->fdin);
	ft_free_global(global);
	DG();
	if (line && *line)
		ft_strdel(line);
	exit(0);
}

int				ft_open(t_global *global, char *str)
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

void			ft_read(t_global *global)
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

int					usage(void)
{
	ft_printf("usage: asm [-vqD] file ...");
	return (1);
}

static int			ft_strcat_check(char *dest, char *src, int *len, int authorized)
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

static int			check_header_name(t_asm *a, char *line)
{
	if (*a->file.header.prog_name)
		if (ft_strcat_check(a->file.header.prog_name, "\n", &a->file.name_len, PROG_NAME_LENGTH))
			return (verbose(a, MSG_ERROR, "Name is too long", NULL));
	while (*line && *line != '"')
	{
		a->file.header.prog_name[a->file.name_len++] = *(line++);
		if (a->file.name_len > PROG_NAME_LENGTH)
			return (verbose(a, MSG_ERROR, "Name is too long", NULL));
	}
	if (!*line)
		return (2);
	++line;
	while (ft_isspa(*line))
		++line;
	return (*line ? -1 : 0);
}

static int			check_header_comment(t_asm *a, char *line)
{
	if (*a->file.header.comment)
		if (ft_strcat_check(a->file.header.comment, "\n", &a->file.comment_len, COMMENT_LENGTH))
			return (verbose(a, MSG_ERROR, "Comment is too long", NULL));
	while (*line && *line != '"')
	{
		a->file.header.comment[a->file.comment_len++] = *(line++);
		if (a->file.comment_len > COMMENT_LENGTH)
			return (verbose(a, MSG_ERROR, "Comment is too long", NULL));
	}
	if (!*line)
		return (3);
	++line;
	while (ft_isspa(*line))
		++line;
	return (*line ? -1 : 0);
}

static int			check_header(t_asm *a, char *line)
{
	while (ft_isspa(*line))
		++line;
	if (!*line || ft_strchr(COMMENT_CHAR, *line))
		return (1);
	if (ft_isspa(ft_strcmp(line, NAME_CMD_STRING)))
	{
		if (IS_SET(a->file.flag, HEAD_NAME))
			return (verbose(a, MSG_ERROR, "Name is already set", NULL));
		SET(a->file.flag, HEAD_NAME);
		line += 5;
		while (ft_isspa(*line))
			++line;
		if (*line != '"' )
			return (verbose(a, MSG_ERROR, "Name lexical error", NULL));
		return (check_header_name(a, line + 1));
	}
	else if (ft_isspa(ft_strcmp(line, COMMENT_CMD_STRING)))
	{
		if (IS_SET(a->file.flag, HEAD_COMMENT))
			return (verbose(a, MSG_ERROR, "Comment is already set", NULL));
		SET(a->file.flag, HEAD_COMMENT);
		line += 8;
		while (ft_isspa(*line))
			++line;
		if (*line != '"' )
			return (verbose(a, MSG_ERROR, "Comment lexical error", NULL));
		return (check_header_comment(a, line + 1));
	}
	else
		return (verbose(a, MSG_ERROR, "Invalid header", NULL));
	return (1);
}

static int			check_filename(t_asm *a, char *filename)
{
	size_t		len;

	if (!(len = ft_strlen(filename)))
		return (verbose(a, MSG_ERROR, "%s: len is 0", filename));
	if (!ft_strcmp(filename + (len - 2), ".s"))
	{
		if (!(a->file.filename = (char *)malloc(len + 3)))
			return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
		ft_memcpy(a->file.filename, filename, len - 2);
		ft_memcpy(a->file.filename + len - 2, ".cor", 5);
	}
	else
	{
		if (!(a->file.filename = (char *)malloc(len + 5)))
			return (verbose(a, MSG_ERROR, "Malloc failed", NULL));
		ft_memcpy(a->file.filename, filename, len);
		ft_memcpy(a->file.filename + len, ".cor", 5);
	}
	if ((a->file.fdin = open(filename, O_RDONLY)) < 0)
	{
		return (verbose(a, MSG_ERROR,
					"%s: No such file or directory", filename));
	}
	return (0);
}

const static t_itof g_send_line_func [] =
{
	{1, &check_header},
	{2, &check_header_name},
	{3, &check_header_comment},
};

static int			do_asm(t_asm *a, char *filename)
{
	int		(*f)();
	int		ret;
	char	*line;

	ft_bzero(&a->file, sizeof(t_file));
	if (check_filename(a, filename))
		return (1);
	f = &check_header;
	while (get_next_line(a->file.fdin, &line) > 0)
	{
		if ((ret = f(a, line)) == -1)
		{
			ft_strdel(&line);
			verbose(a, MSG_ERROR, "Invalid header", NULL);
			return (1);
		}
		ft_strdel(&line);
		if (!ret && IS_SET(a->file.flag, (HEAD_COMMENT | HEAD_NAME)))
			break;
		if (ret)
			f = g_send_line_func[ret - 1].f;
		else
			f = &check_header;
	}
	ft_strdel(&line);
	t_global	*global;
	global = &a->file.global;
	global->header = a->file.header;
	global->fdin = a->file.fdin;
	ft_read(global);
	ft_open(global, a->file.filename);
	write(global->fdout, global->res, global->total_octet);
	close(global->fdin);
	ft_printf ("Writing output program to %s\n", a->file.filename);
	ft_free_map(global);
	ft_free_global(global);
	free(a->file.filename);
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
