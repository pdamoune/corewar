#include "../includes/op.h"

/*
**  UNE FOIS LE FICHIER LU, LE CONTROLLER VA NOUS PERMETTRE DE TRAITER LES INFORMATIONS STOCKEES
*/

void		ft_controller(global_t *global)
{
	// DEBUG_read_map(global);
    ft_stock_label(global);
	DEBUG_read_labels(global);
}
