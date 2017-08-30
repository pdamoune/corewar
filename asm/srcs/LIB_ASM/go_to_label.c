#include "../../includes/op.h"

label_t        *go_to_label(char *s, global_t *global)
{
    global->s_label = global->begin_label;
    while (global->s_label)
    {
		if (!ft_strcmp(s, global->s_label->name))
			return(global->s_label);
        global->s_label = global->s_label->next;
    }
	ft_exit(15, global, NULL);
    return(NULL);
}
