#include "../includes/op.h"


void	indirect_param(global_t *global, char *line)
{
	// label_t *test;
	//
	// test = NULL;
	if (ft_strstart(line, "%:"))
	{
		printf("<%s> = INDIRECT 11 + %s\n", line, ft_strstart(line, "%:"));
		/* DEBUG pour tester la fonction go_to_label */
		//test = go_to_label(ft_strstart(line, "%:"),global);
		//printf("Retour de test : %s", test->name);

	}
	else
		printf("<%s> \n", line);
	global->i = 0;
}
