#include "../includes/op.h"

/*
** FONCTIOn QUI VA TRADUIRE LES INSTRUCTIONS
*/
void		ft_traduce_label(global_t *global, char *line)
{
	/* Actuellement cette fonction n'a aucun sens et ne veut rien dire en l'état,
	Je me suis juste amusée!!

	Il faut entièrement la coder et analyser chaque instruction qu'il faudra transformer
	Par contre, j'ai une question -> Dans quoi on stocke la valeur en hexa ?
	Est-ce qu'on crée un tableau de nos instructions ? */

	if (!ft_strcmp(line, "live"))
		printf("<%s> = 0x01 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
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
    	printf("nb_octet :%d \n", global->s_label->nb_octet);
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
