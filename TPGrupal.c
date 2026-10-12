#include "TPGrupal.h"

int ValidarUser(char *idUsuario)
{
    int caracter, idValido;
    char ingresoId[10], *salto;

    do
    {
        caracter = getchar();

    }while(caracter != '\n' && caracter != EOF);

    idValido = 0;

    do
    {
        printf("Escriba su ID de usuario (8 caracteres):  ");

        if (fgets(ingresoId, sizeof ingresoId, stdin) == NULL)
        {
            printf("No se pudo leer el ID.\n");
            return 1;
        }

         salto = strchr(ingresoId, '\n');

        if (salto != NULL)
        {
            *salto = '\0';
        }

        if (strlen(ingresoId) > 8)
        {
            do
            {
                caracter = getchar();

            }while(caracter != '\n' && caracter != EOF);

            printf("\n El ID no puede superar los 8 caracteres.\n");
        }
        else if (strlen(ingresoId) < 8)
        {
            printf("\n El ID debe tener exactamente 8 caracteres.\n");
        }
        else
        {
            strcpy(idUsuario, ingresoId);
            idValido = 1;
        }

    } while (!idValido);

    return 0;
}
