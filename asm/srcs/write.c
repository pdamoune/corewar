#include "../includes/op.h"

int		ft_write(global_t *global, int fdIn, char *string)
{
    int fdOut;
    int nbRead;
    char buffer[1000];

    /* Ouverture du fichier de destination */
    fdOut = open("42.cor", O_WRONLY | O_CREAT, 0666);
    if (-1 == fdOut) {
        close(fdIn);
		ft_exit(4, global, NULL);
        exit(EXIT_FAILURE);
    }
    /* On utilise read pour envoyer le contenu du fichier1 vers le buffer */
     nbRead = read(fdOut, buffer, sizeof(buffer));
     while (nbRead > 0) {
         nbRead = read(fdOut, buffer, sizeof(buffer));
    }
	write(fdOut, string, ft_strlen(string));
    printf("La copie a du s'effectuer, verifiez le fichier de destination");
    close(fdOut);
    return EXIT_SUCCESS;
}
