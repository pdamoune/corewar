#include "../includes/op.h"

void	ft_initialize_content(content_t **content, char *line)
{
	char **tab1;
	char **tab2;

	tab1 = NULL;
	tab2 = NULL;
	if (!(*content = (content_t*)malloc(sizeof(content_t))))
		return ;
	tab1 = ft_strsplit_cmt(ft_strdup_asm(line));
	if (ft_strlen_tab(tab1) > 1)
		tab2 = ft_strsplit_virg(tab1[0]);
	else
		tab2 = ft_strsplit_virg(ft_strdup_asm(line));
	(*content)->line = ft_split_tab(tab2);
	// if (tab1)
	// 	ft_free_tab(tab1);
	// if (tab2)
	// 	ft_free_tab(tab2);
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
