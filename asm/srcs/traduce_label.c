#include "../includes/op.h"

/*
** FONCTIOn QUI VA TRADUIRE LES INSTRUCTIONS
*/

int		ft_find_index(global_t *global, char *line)
{
	int i;

	i = 0;
	while (global->index_tab[i])
	{
		if (ft_strstart(line, global->index_tab[i]))
			return(i);
		i++;
	}
	return(i);
}

void		ft_traduce_label(global_t *global, char *line)
{
	int index;

	index = ft_find_index(global,line);
	printf("index %d\n", index);
	if (index >= 0 && index < 18)
		ft_pointeur_tab(global, index);
	else if (index >= 18 && index <= 21)
		ft_pointeur_tab(global, index);
	else
		ft_exit(10, global, NULL);
}



/*s
** PARCOURE LA STRUCT LABEL pour récupérer les lignes d'instructions et calculer le nombre d'octets.
*/
void		ft_browse_label(global_t *global, int type)
{
	global->s_label = global->begin_label;
    printf("***** START Structure LABEL ***** \n");
	/* A voir si on modifie ce code */
	while (!ft_strcmp(global->s_label->name, "HEADER") || !ft_strcmp(global->s_label->name, "COMMENTS") )
		global->s_label = global->s_label->next;
	/* Fin du code */
    while (global->s_label)
    {
        printf("/--------------- NEW LABEL n°%d --------------/\n", global->s_label->num);
        printf("Name :%s \n", global->s_label->name);
        printf("Content : \n");

        global->s_label->s_content = global->s_label->begin_content;
        while (global->s_label->s_content)
        {
			if (type == OCTET)
			{
				global->s_label->s_content->nb_octet++;
				global->s_label->s_content->begin_octet = global->total_octet;
				ft_traduce_label(global, global->s_label->s_content->line[0]);
				global->total_octet += global->s_label->s_content->nb_octet;
			}
			else if (type == STOCK)
				ft_traduce_label(global, global->s_label->s_content->line[0]);

			/* DEBUG */
			printf("begin_octet : %d\n", global->s_label->s_content->begin_octet);
			printf("nb_octet : %d\n", global->s_label->s_content->nb_octet);
			printf("global->total_octet : %d\n\n", global->total_octet);
			/* FIN DEBUG */
            global->s_label->s_content = global->s_label->s_content->next;
        }
       printf("\n");
        global->s_label = global->s_label->next;
    }
}
