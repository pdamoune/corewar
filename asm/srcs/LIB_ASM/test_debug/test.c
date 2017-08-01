
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

// void        DEBUG_read_labels(global_t *global)
// {
//     int i;
//     int j;
//
//     i = 0;
//     ft_printf("***** START TABLEAU label_tab ***** \n");
//     while (global->label_tab[i].content)
//     {
//         ft_printf("/---------- NEW LABEL -------/\n");
//         ft_printf("Name :%s \n", global->label_tab[i].name);
//     	ft_printf("nb_octet :%d \n", global->label_tab[i].nb_octet);
//         ft_printf("Lines of the label : \n");
//         j = 0;
//         while ((global->label_tab[i].content)[j])
//         {
//             ft_printf("%s \n", (global->label_tab[i].content)[j]);
//             j++;
//         }
//         ft_printf("End of Lines of the label : \n");
//         ft_printf("/---------- END LABEL -------/\n\n");
//         i++;
//     }
//     ft_printf("***** END TABLEAU label_tab ***** \n");
// }
