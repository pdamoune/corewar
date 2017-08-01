#include "../includes/op.h"

void	ft_initialize_label(label_t **label)
{
	if (!(*label = (label_t*)malloc(sizeof(label_t))))
		return ;
    (*label)->begin_content = NULL;
    (*label)->s_content = NULL;
    (*label)->name = NULL;
	(*label)->nb_octet = 0;
    (*label)->num = 0;
    (*label)->next = NULL;
    (*label)->previous = NULL;
}

void		ft_stock_label(global_t *global)
{
    label_t	*new;
    label_t	*previous;

    new = NULL;
    previous = NULL;
    ft_initialize_label(&new);
    if (!global->begin_label)
        global->begin_label = new;
    else
    {
        previous = global->s_label;
        new->previous = previous;
        previous->next = new;
    }
    global->s_label = new;
}
