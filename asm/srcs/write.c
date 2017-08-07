#include "../includes/op.h"

int		ft_write(global_t *global, char *string, int hexa)
{
    int fdOut;
    int nbRead;
    char buffer[1000];

    /* Ouverture du fichier de destination */
    fdOut = open("42.cor", O_WRONLY | O_CREAT, 0666);
    if (-1 == fdOut) {
		ft_exit(4, global, NULL);
        exit(EXIT_FAILURE);
    }
    /* On utilise read pour envoyer le contenu du fichier1 vers le buffer */
     nbRead = read(fdOut, buffer, sizeof(buffer));
     while (nbRead > 0) {
         nbRead = read(fdOut, buffer, sizeof(buffer));
    }
	lseek(fdOut,0,SEEK_END);
	if (hexa == 2)
	{
		write(fdOut, "0x00 0x", 8);
		lseek(fdOut,0,SEEK_END);
	}
	if (hexa == 4)
	{
		write(fdOut, "0x00 0x00 0x00 0x", 17);
		lseek(fdOut,0,SEEK_END);
	}
	write(fdOut, string, ft_strlen(string));
    close(fdOut);
    return EXIT_SUCCESS;
}
