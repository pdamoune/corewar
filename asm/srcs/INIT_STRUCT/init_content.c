#include "../includes/op.h"

void	ft_initialize_content(content_t **content, char *line)
{
	if (!(*content = (content_t*)malloc(sizeof(content_t))))
		return ;
	(*content)->line = ft_strsplit_asm(ft_strdup_asm(line));
	(*content)->nb_octet = 0;
    (*content)->next = NULL;
	(*content)->previous = NULL;
}

/*
**  STOCKE CHAQUE LINE DANS LA STRUCT CONTENT
*/

void	ft_stock_content(global_t *global, char *line)
{
    content_t	*new;
    content_t	*previous;

    new = NULL;
    previous = NULL;
    ft_initialize_content(&new, line);
    if (!global->s_label->begin_content)
        global->s_label->begin_content = new;
    else
    {
        previous = global->s_label->s_content;
        new->previous = previous;
        previous->next = new;
    }
    global->s_label->s_content = new;
}
