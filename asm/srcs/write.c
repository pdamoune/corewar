#include "../includes/op.h"

int		ft_write(global_t *global, char *string, int size)
{
    int nbRead;
    char buffer[1000];

    /* Ouverture du fichier de destination */
    global->fdOut = open("42.cor", O_RDWR, 0666);
    if (-1 == global->fdOut) {
		ft_exit(4, global, NULL);
        exit(EXIT_FAILURE);
    }
    /* On utilise read pour envoyer le contenu du fichier1 vers le buffer */
     nbRead = read(global->fdOut, buffer, sizeof(buffer));
     while (nbRead > 0) {
         nbRead = read(global->fdOut, buffer, sizeof(buffer));
    }
	lseek(global->fdOut,0,SEEK_END);
	write(global->fdOut, string, size);
	// string = NULL;
	// write(fdOut, "01", 1);
    close(global->fdOut);
    return EXIT_SUCCESS;
}