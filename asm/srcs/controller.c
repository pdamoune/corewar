#include "../includes/op.h"

/*
**  UNE FOIS LE FICHIER LU, LE CONTROLLER VA NOUS PERMETTRE DE TRAITER LES INFORMATIONS STOCKEES
*/

void		ft_pointeur_tab(global_t *global, int index)
{
	p_tab[live] = ft_th_live_instruct;
	p_tab[ld] = ld_instruct;
	p_tab[st] = st_instruct;
	p_tab[add] = add_instruct;
	p_tab[sub] = sub_instruct;
	p_tab[and] = ft_th_and_instruct;
	p_tab[or] = or_instruct;
	p_tab[xor] = xor_instruct;
	p_tab[zjmp] = zjmp_instruct;
	p_tab[ldi] = ldi_instruct;
	p_tab[sti] = sti_instruct;
	p_tab[FORK] = fork_instruct;
	p_tab[lld] = lld_instruct;
	p_tab[lldi] = lldi_instruct;
	p_tab[lfork] = lfork_instruct;
	p_tab[aff] = aff_instruct;
	p_tab[direct] = direct_param;
	p_tab[indirect] = indirect_param;
	p_tab[R] = register_param;
	p_tab[Name_CMD_STRING] = cmd_string;
	p_tab[Comment_CMD_STRING] = cmd_string;
	p_tab[Comment_CHAR] = comments_string;
	p_tab[Other_CMD_STRING] = others_string;


	p_tab[index](global);
}

void		ft_controller(global_t *global)
{
	// DEBUG_read_map(global);
    ft_parse_label(global);
	//DEBUG_read_labels(global);
	ft_browse_file_counting(global);
	ft_browse_content(global);
//	ft_browse_label(global, OCTET);
//	ft_browse_label(global, STOCK);
}

/* Explications
ligne d'instruction au hasard, on admet que blabla = 42, au pif
and     %12,%:blabla,r1
and, son OPcode, c'est 0x06
passons au codage des parametres
% signifie DIRECT, %: signifie INDIRECT
binaire = 10110100
<FAUX>
10 pour DIRECT(le premier param est direct) 11 pour IND(comme le 2eme param)
01 pour signifier un registre, et 00 pour arriver jusqu'a 8bits.
</FAUX>
10110100 = 0xB2 en hexa.
pour le moment on a donc 0x06 0xB2
maintenant faut traduire les valeurs.
une valeur directe est sur 2 ou 4 octets (2 ou 4 chiffres en hexa)
une valeur indirecte est sur 2octets.
un registre sur 1 octet.
%12 = 0x00 0x00 0x00 0x0B
%:blabla = 42 = 0x00 0x2A
r1 -> les registres ont un numero. c'est ce numero qu'on va transformer en hexa.
ici REG_NUMBER de r1 = 1 donc
r1 = 0x01
on a au resultat 0x06 0xB2 0x00 0x00 0x00 0x0B 0x00 0x2A 0x01
Voila, tu me dis si c'est pas clair, on aura l'occasion d'y revenir.*/
