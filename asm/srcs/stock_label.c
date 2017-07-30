#include "../includes/op.h"

static 	label_t		*ft_initialize_label(global_t *global)
{
	label_t	*label;

	if (!(label = (label_t*)malloc(sizeof(label_t))))
		return (NULL);
	if (!(label->content = (char**)malloc((global->nb_lines + 1) * sizeof(char*))))
		return (0);
    label->name = NULL;
	label->nb_octet = 0;
	return (label);
}

/*
**  IDENTIFIE LE TYPE DE LIGNES
** 1) ligne vide - EMPTY_LINE
** 2) ligne de commentaire - COMMENT
** 3) instruction avec LABEL_CHAR - WITH_LABEL
** 4) instruction sans LABEL_CHAR ou autre - EMPTY_LABEL
*/
int		ft_kind_of_line(char *line)
{
	int 	i;

	i = 0;
	if (line[i] == '\n')
		return (EMPTY_LINE);
	else if (line[i] == COMMENT_CHAR)
		return (COMMENT);
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
**  STOCK LES DONNEES DANS LE TABLEAU label_tab
*/
void		ft_sort_lines(global_t *global, char *line, int *i, int *j)
{
	if (ft_kind_of_line(line) == COMMENT ||
		line[0] == '.' )
	{
		global->label_tab[*i].content[*j++] = ft_strdup(line);
		global->label_tab[*i].name = "Commentaires";
	}
	else
	{
		while (ft_kind_of_line(line) == WITH_LABEL ||
				ft_kind_of_line(line) == EMPTY_LABEL)
		{
			global->label_tab[*i].content[*j++] = ft_strdup(line);
			global->s_map = global->s_map->next;
		}
	}
	if (ft_kind_of_line(line) == EMPTY_LINE)
	{
		global->label_tab[*i].content[*j] = NULL;
		*j = 0;
	}
}

/*
**  STOCK CHAQUE LABEL & CO DANS LA STRUCT LABEL STOCKEE DANS UN TABLEAU
*/

void		ft_stock_label(global_t *global)
{
	int i;
	int j;

	if (!(global->label_tab = (label_t*)malloc((global->nb_lines + 1) *sizeof(label_t))))
		return ;
	global->s_map = global->begin_map;
	i = 0;
	j = 0;
    while (global->s_map)
    {
		global->label_tab[i] = *ft_initialize_label(global);
		//ft_sort_lines(global, global->s_map->line, &i, &j);
		i++;
		global->s_map = global->s_map->next;
    }
	global->label_tab[i].content = NULL;
	// DEBUG_read_labels(global);
	/* Créér la fonction qui va identifier les blocs avec les labels correspondants
		Fonction à compléter - EN COURS */
}
