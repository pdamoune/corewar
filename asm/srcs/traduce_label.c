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
	// printf("*******line = %s - index :%d**********\n",line, index);
	if (index >= 0 && index < 19)
		ft_pointeur_tab(global, index, line);
	else
		printf("<%s> error index %d\n", line, index);
}

/*
** PARCOURE LA STRUCT LABEL pour récupérer les lignes d'instructions et les traiter
*/
void		ft_browse_label(global_t *global)
{
	int		i;

	global->s_label = global->begin_label;
    printf("***** START Structure LABEL ***** \n");
    while (global->s_label)
    {
        printf("/--------------- NEW LABEL n°%d --------------/\n", global->s_label->num);
        printf("Name :%s \n", global->s_label->name);
        printf("Content : \n");
        global->s_label->s_content = global->s_label->begin_content;
        while (global->s_label->s_content)
        {
			printf("Instruction %d):\n",i++);
			i = 0;
			while (global->s_label->s_content->line[i])
			{
				ft_traduce_label(global, global->s_label->s_content->line[i]);
				i++;
			}
			printf("\n");
            global->s_label->s_content = global->s_label->s_content->next;
        }
       printf("\n");
        global->s_label = global->s_label->next;

    }
}
