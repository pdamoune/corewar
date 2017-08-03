#include "../includes/op.h"

/*
**  UNE FOIS LE FICHIER LU, LE CONTROLLER VA NOUS PERMETTRE DE TRAITER LES INFORMATIONS STOCKEES
*/

void		ft_controller(global_t *global)
{
	// DEBUG_read_map(global);
    ft_parse_label(global);
	//DEBUG_read_labels(global);
	ft_browse_label(global);
}

/* Explications
ligne d'instruction au hasard, on admet que blabla = 42, au pif
and     %12,%:blabla,r1
and, son OPcode, c'est 0x06
passons au codage des parametres
% signifie DIRECT, %: signifie INDIRECT
binaire = 10110100
10 pour DIRECT(le premier param est direct) 11 pour IND(comme le 2eme param)
01 pour signifier un registre, et 00 pour arriver jusqu'a 8bits.
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
