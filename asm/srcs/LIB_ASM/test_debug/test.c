
#include "../../../includes/op.h"


/*
**  FICHIERS DE DEBUG - POUR TESTER LES FONCTIONS CODEES
*/

void        DEBUG_read_map(global_t *global)
{
    global->s_map = global->begin_map;
    ft_printf("***** START Structure MAP ***** \n");
    while (global->s_map)
    {
    	ft_printf("%s \n", global->s_map->line);
    	global->s_map = global->s_map->next;
    }
    ft_printf("***** END Structure MAP ***** \n");
}

void        DEBUG_read_labels(global_t *global)
{
    int i;
    global->s_label = global->begin_label;
    ft_printf("***** START Structure LABEL ***** \n");
    while (global->s_label)
    {
        ft_printf("/--------------- NEW LABEL n°%d --------------/\n", global->s_label->num);
        ft_printf("Name :%s \n", global->s_label->name);
        ft_printf("Content : \n");
        global->s_label->s_content = global->s_label->begin_content;
        i = 0;
        while (global->s_label->s_content)
        {

			ft_printf("Instruction %d):\n",i++);
			ft_print_lines(global->s_label->s_content->line);
			ft_printf("\n");

            global->s_label->s_content = global->s_label->s_content->next;
        }
       ft_printf("\n");
        global->s_label = global->s_label->next;

    }
    ft_printf("***** END Structure LABEL ***** \n");
}

void        DEBUG_read_content(global_t *global)
{
    global->s_label->s_content = global->s_label->begin_content;
    ft_printf("/--- START CONTENT ---/ \n");
    while (global->s_label->s_content)
    {
        ft_printf("%s \n", global->s_label->s_content->line);
        global->s_label->s_content = global->s_label->s_content->next;
    }
    ft_printf("/--- END CONTENT ---/\n\n");
}
