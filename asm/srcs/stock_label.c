#include "../includes/op.h"

/*
**  IDENTIFIE LE TYPE DE LIGNES
** 1) ligne vide - EMPTY_LINE
** 2) ligne de commentaire - COMMENT
** 3) instruction avec LABEL_CHAR - WITH_LABEL
** 4) instruction sans LABEL_CHAR ou autre - EMPTY_LABEL
** 5) instruction de header - HEADER
*/
int		ft_kind_of_line(char *line)
{
	int 	i;

	i = 0;
	if (line[i] == '\n')
		return (EMPTY_LINE);
	else if (line[i] == COMMENT_CHAR)
		return (COMMENT);
    /*  Ajouter la condition pour les headers
    else if (line[i] == ???)
        return (HEDAER);*/
	while (line[i])
	{
		while (is_labelchars(line[i]))
			i++;
		if (line[i] == LABEL_CHAR)
			return (WITH_LABEL);
		else
		{
			while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
					i++;
			return (EMPTY_LABEL);
		}
		i++;
	}
	return (0);
}

/*
**  STOCK LES DONNEES DANS UNE STRUCTURE LABEL
*/
void		ft_sort_lines(global_t *global)
{
    if (global->s_map && ft_kind_of_line(global->s_map->line) == HEADER)
	{
        ft_stock_content(global, global->s_map->line);
		global->s_label->name = "Comments";
	}
    else if (global->s_map && ft_kind_of_line(global->s_map->line) == COMMENT)
    {
        ft_stock_content(global, global->s_map->line);
        global->s_label->name = "Header";
    }
	else
	{
		while (global->s_map && (ft_kind_of_line(global->s_map->line)
        == WITH_LABEL || ft_kind_of_line(global->s_map->line) == EMPTY_LABEL))
		{
            ft_stock_content(global, global->s_map->line);
			global->s_map = global->s_map->next;
		}
        if (global->s_map)
            global->s_map = global->s_map->previous;
	}
    if (global->s_map)
        global->s_map = global->s_map->next;
	if (global->s_map && ft_kind_of_line(global->s_map->line) == EMPTY_LINE)
		ft_init_new_label(global);
}

void		ft_stock_label(global_t *global)
{
    ft_init_new_label(global); /* global->s_label est initialisé sur un 1er maillon */
    global->s_map = global->begin_map;
    while (global->s_map)
    {
        while (global->s_map && ft_kind_of_line(global->s_map->line)
                == EMPTY_LINE)
            global->s_map = global->s_map->next;
		ft_sort_lines(global);
        if (global->s_map)
		      global->s_map = global->s_map->next;
    }
}
