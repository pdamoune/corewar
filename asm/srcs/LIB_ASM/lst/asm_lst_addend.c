#include "../../../includes/op.h"

void	asm_lst_addend(map_t **map, map_t *new)
{
	map_t *temp;

	temp = *map;
	if (new && *map)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*map = new;
}
