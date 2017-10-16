/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:41:29 by pdamoune          #+#    #+#             */
/*   Updated: 2017/10/16 20:07:59 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_r.h>

static t_cliopts	g_read_opts[] =
{
	// {'d', "dump", DUMP, 0, init_dump, 1},
	{'D', "debug", DEBUG, 0, NULL, 0},
	// {'g', "graphic", WILL_GRAPHIC, 0, NULL, 0},
	// {'i', "introduce", INTRO, 0, NULL, 0},
	// {'k', "kill", KILL, 0, NULL, 0},
	// {'m', "music", MUSIC, 0, NULL, 0},
	// {'n', "number", 0, 0, init_number, 2},
	// {'o', "operation", OPERATION, 0, NULL, 0},
	{'q', "quiet", QUIET, VERBOSE, NULL, 0},
	// {'s', "sound", SOUND, 0, NULL, 0},
	{'v', "verbose", VERBOSE, QUIET, NULL, 0},
	// {'V', "voice", VOICE, 0, NULL, 0},
	// {'z', "zaz", ZAZ, 0, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

static int		analyze_header(t_asm_r *asm_r, t_header *header)
{
	if ((header->magic = INTREV32(header->magic)) != COREWAR_EXEC_MAGIC)
		return (verbose(asm_r, MSG_ERROR,
				"Invalid magic: %x: Magic number should be %x",
				header->magic, COREWAR_EXEC_MAGIC));
	else if (header->prog_name[PROG_NAME_LENGTH])
		return (verbose(asm_r, MSG_ERROR,
				"Invalid name: Should be null terminated '%c' (%d)",
				header->prog_name[PROG_NAME_LENGTH],
				header->prog_name[PROG_NAME_LENGTH]));
	else if ((header->prog_size = INTREV32(header->prog_size)) > CHAMP_MAX_SIZE)
		return (verbose(asm_r, MSG_ERROR,
				"Invalid program size: %u: Max program size is %d",
				header->prog_size, CHAMP_MAX_SIZE));
	else if (!header->prog_size)
		return (verbose(asm_r, MSG_ERROR,
				"Invalid program size: Program cannot be empty", NULL));
	else if (header->comment[COMMENT_LENGTH])
	{
		return (verbose(asm_r, MSG_ERROR,
				"Invalid comment: Should be null terminated '%c' (%d)",
				header->comment[COMMENT_LENGTH],
				header->comment[COMMENT_LENGTH]));
	}
	return (0);
}

int				init_data(t_asm_r *asm_r, int fd, t_file *file)
{
	int		n_read;

	if ((n_read = read(fd, &(file->header), sizeof(t_header)))
				!= sizeof(t_header))
	{
		return (verbose(asm_r, MSG_ERROR,
				"Invalid header: %d: Failed to read full header (%d)",
				n_read, sizeof(t_header)));
	}
	if (analyze_header(asm_r, &(file->header)))
		return (1);
	else if ((n_read = read(fd, file->prog, CHAMP_MAX_SIZE + 1))
					!= (int)file->header.prog_size)
	{
		return (verbose(asm_r, MSG_ERROR,
				"Invalid program: %d: Program size expected is %u",
				n_read, file->header.prog_size));
	}
	return (0);
}

int			analizer(t_file *file)
{
	display(file);

	return (1);
}

int				init_file(t_asm_r *asm_r, t_file *file, char *filename)
{
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} %s",
				filename, strerror(errno))); // TODO Gestion erreur puis fichier suivant
	}
	if (init_data(asm_r, fd, file))
	{
		close(fd);
		return (verbose(asm_r, MSG_ERROR, "{yel}%s:{red} Invalid champion file",
				filename));
	}
	close(fd);
	return (0);
}

int			init_asm_r(t_asm_r *asm_r, char ***av)
{
	if ((cliopts_get(*av, g_read_opts, asm_r)))
		return (ft_perror("asm-r") && usage());

	if (asm_r->av_data)
	{
		while (*asm_r->av_data)
		{
			asm_r->file.filename = *asm_r->av_data;
			if (init_file(asm_r, &asm_r->file, *asm_r->av_data++))
				return (1);
			analizer(&asm_r->file);
		}
	}

	return (0);
}
