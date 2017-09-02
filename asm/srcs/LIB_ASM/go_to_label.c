#include "../../includes/op.h"

long		go_to_label(char *label, global_t *global, int type)
{
	label_t		*tmp;
	int			begin_octet;
	int			label_octet;
	int			stop;

	tmp = global->s_label;
	stop = 0;
	begin_octet = global->s_label->s_content->begin_octet;
	label_octet = 0;
	global->s_label = global->begin_label;
    while (global->s_label && !stop)
    {
		if (!ft_strcmp(label, global->s_label->name))
		{
			stop = 1;
			label_octet = global->s_label->begin_content->begin_octet;
		}
        global->s_label = global->s_label->next;
    }
	global->s_label = tmp;
	if (stop)
	{
		// printf("label_octet %d\n",label_octet);
		// printf("begin_octet %d\n",begin_octet);
		// printf("resultat us = %d\n",(unsigned int)(label_octet - begin_octet));
		// printf("resultat s = %d\n",(int)(label_octet - begin_octet));
		if (type == IND_CODE)
			return((unsigned int)(label_octet - begin_octet));
		else
			return((int)(label_octet - begin_octet));
	}
	else
		ft_exit(15, global, NULL);
	return(0);
}


/*
						16					-12
0100 0000 01|06 6401 0000 0010 01|06 6401 ffff fff3 01|01 0000 0001
live2 = 0
and = 6
and = 14
live = 22

										65523 - 65535 = -12
0100 0000 01|06 6401 0000 000e 01|06 7401      fff3 01|01 0000 0001 INDIRECT
0100 0000 01|06 6401 0000 0010 01|06 6401 ffff fff3 01|01 0000 0001 DIRECT

0100 0000 01|06 6401 0000 0010 01|06 7401 ffff fff3 01|01 0000 0001 INDIRECT
0100 0000 01|06 6401 0000 0010 01|06 6401 ffff fff3 01|01 0000 0001 DIRECT
*/
