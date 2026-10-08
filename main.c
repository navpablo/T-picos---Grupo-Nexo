#include "TP Grupal.h"

int main()
{
    setlocale(LC_ALL, ""); //Para ñ o tildes
    int opcion;
    char idUsuario[9];

    do{
        printf("=== SISTEMA DE GESTION DE EVENTOS ===\n");
        printf("Seleccione el perfil de inicio de sesión:\n");
        printf("1. ADMIN\n");
        printf("2. USER\n");
        printf("0. Salir\n");
        printf("Opción");

        if (scanf("%d",opcion)!=1)
        {

        }
    }while(opcion!=0);

    printf("Hello world!\n");
    return 0;
}
