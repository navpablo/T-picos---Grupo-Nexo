#include "TPGrupal.h"
#include "Eventos.h"
int main()
{
    setlocale(LC_ALL, ""); // Para ñ o tildes
    int opcion, eventoUser, eventoAdmin;
    char idUsuario[9];

    do
    {
        printf("\n=== SISTEMA DE GESTION DE EVENTOS ===\n");
        printf("Seleccione el perfil de inicio de sesión:\n");
        printf("1. ADMIN\n");
        printf("2. USER\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1: // MENÚ ADMIN
                do {
                    printf("\n--- Menú ADMINISTRADOR ---\n");
                    printf("1. Dar Alta evento/s\n");
                    printf("2. Buscar evento\n");
                    printf("3. Gestionar evento\n");
                    printf("4. Consultar establecimiento\n");
                    printf("5. Consultar ventas\n");
                    printf("6. Conteo de entradas\n");
                    printf("7. Reporte de ocupacion\n");
                    printf("0. Volver al menú principal\n");
                    printf("Opción: ");
                    scanf("%d", &eventoAdmin);

                    switch(eventoAdmin)
                    {
                        case 1:
                            AltaEvento();
                         break;
                        case 2: break;
                        case 3: break;
                        case 4: break;
                            //consultarEstablecimiento();
                        case 5: break;
                        case 6: break;
                        case 7: break;
                        case 0: printf("Volviendo...\n"); break;
                        default: printf("Opción inválida.\n"); break;
                    }
                } while(eventoAdmin != 0);
                break;

            case 2: // MENÚ USER

                ValidarUser(idUsuario);

                do {
                    printf("\n--- Menú USUARIO (%s) ---\n", idUsuario);
                    printf("1. Comprar entrada/s\n");
                    printf("2. Consultar Entrada/s\n");
                    printf("3. Cancelar entrada/s\n");
                    printf("4. Consultar eventos\n");
                    printf("5. Consultar establecimiento\n");
                    printf("6. Consultar ubicacion y capacidad\n");
                    printf("0. Volver al menú principal\n");
                    printf("Opción: ");
                    scanf("%d", &eventoUser);

                    switch(eventoUser)
                    {
                        case 1: break;
                        case 2: break;
                        case 3: break;
                        case 4:
                            consultarEventos();
                             break;
                        case 5: break;
                        case 6: break;
                        case 0: printf("Volviendo...\n"); break;
                        default: printf("Opción inválida.\n"); break;
                    }
                } while(eventoUser != 0);
                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("\nOpción inválida, inténtelo de nuevo.\n");
                break;
        }
    }
    while(opcion != 0);

    printf("Hasta pronto!\n");
    return 0;
}
