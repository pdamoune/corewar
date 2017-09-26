#include "../includes/op.h"


void	lfork_instruct(global_t *global)
{
	/* Debug */
	printf("<%s> = 0x01\n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
	 /*End Debug */
	printf("nb_octet STOCK = %d \n", global->s_label->s_content->nb_octet);
	/* OPCODE  */
	global->s_label->s_content->instruction[0] = 15;

	/* Get the values */
	ft_get_values(global, global->s_label->s_content->line, 1, 1);

	/* Write the instruction */
	ft_write(global, global->s_label->s_content->instruction, global->s_label->s_content->nb_octet);

	/* DEBUG */
    printf("value instruction : ");
	int i = 0;
	while(i < global->s_label->s_content->nb_octet)
		printf("0x%X ", global->s_label->s_content->instruction[i++]);
	printf("\n");
	/* Fin DEBUG */
}
