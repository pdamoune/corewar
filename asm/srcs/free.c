#include "../includes/op.h"

void        ft_free_global(global_t *global)
{
	ft_free_tab(global->index_tab);
	//ft_free_map(global);
	ft_free_labels(global);
	free(global);
}

void        ft_free_map(global_t *global)
{
	map_t	*tmp;

    global->s_map = global->begin_map;
    while (global->s_map)
    {
		if (global->s_map->line)
			free(global->s_map->line);
		tmp = global->s_map->next;
		free(global->s_map);
		global->s_map = tmp;
	}
}

void        ft_free_labels(global_t *global)
{
	label_t	*tmp;

    global->s_label = global->begin_label;
    while (global->s_label)
    {
        ft_free_content(global);
		free(global->s_label->name);
		tmp = global->s_label->next;
		free(global->s_label);
		global->s_label = tmp;
	}
}

void       ft_free_content(global_t *global)
{
	content_t	*tmp;

	global->s_label->s_content = global->s_label->begin_content;
	while (global->s_label->s_content)
	{
		if (global->s_label->s_content->line)
			ft_free_tab(global->s_label->s_content->line);
		free(global->s_label->s_content->instruction);
		tmp = global->s_label->s_content->next;
		free(global->s_label->s_content);
		global->s_label->s_content = tmp;
	}
}
