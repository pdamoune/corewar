
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
