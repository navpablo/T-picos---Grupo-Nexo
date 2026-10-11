#include "Eventos.h"
#include "TPGrupal.h"

/**
|||||||||||||||||ADMINISTRADOR||||||||||||||||||
**/

int AltaEvento()
{
    FILE *pfescritura;
    FILE *pflectura;
    tEvento nuevoEvento;
    tEvento eventoActual;
    char *ptrChar;
    int idRepetido=0;
    int idInsertado=0;
     int c;
    pfescritura= NULL;
    pflectura = NULL;

    ptrChar = nuevoEvento.id;
    while (ptrChar < nuevoEvento.id + 10)
    {
        *ptrChar = '\0';
        ptrChar++;
    }
    while ((c = getchar()) != '\n' && c != EOF);
    // 2. Ingreso de datos por teclado
    printf("=== ALTA DE NUEVO EVENTO ===\n");
    printf("\nIngrese ID del evento (max 9 chars): ");

    fflush(stdout);
    if (fgets(nuevoEvento.id, sizeof(nuevoEvento.id), stdin) != NULL)
    {
        nuevoEvento.id[strcspn(nuevoEvento.id, "\n")] = '\0';
    }



    pflectura = fopen("Eventos.bin", "rb");
    if(pflectura != NULL)
    {
        // El while lee y evalúa en un solo paso de forma segura
        while(fread(&eventoActual, sizeof(tEvento), 1, pflectura) == 1)
        {
            if (strcmp(eventoActual.id, nuevoEvento.id) == 0)
            {
                idRepetido = 1;
                break; // Si ya lo encontró, salimos de una vez
            }
        }
        fclose(pflectura);
    }

    if(idRepetido)
    {
        printf("Error: Ya existe un evento con el identificador '%s'.\n", nuevoEvento.id);

        return IDENTIFICADOR_REPETIDO;
    }

    /**Ya validado el ID que no esta repetido , el administrador escribe los demas datos.**/

    printf("\nIngrese nombre del evento: ");
    fflush(stdout);
    if (fgets(nuevoEvento.nombre, sizeof(nuevoEvento.nombre), stdin) != NULL)
    {
        nuevoEvento.nombre[strcspn(nuevoEvento.nombre, "\n")] = '\0';
    }

    printf("\nIngrese tipo de evento: ");
    fflush(stdout);
    if (fgets(nuevoEvento.tipoEvento, sizeof(nuevoEvento.tipoEvento), stdin) != NULL)
    {
        nuevoEvento.tipoEvento[strcspn(nuevoEvento.tipoEvento, "\n")] = '\0';
    }

    printf("\nIngrese ID de establecimiento: ");
    fflush(stdout);
    scanf("%u", &nuevoEvento.idEstablecimiento);

    printf("\nIngrese fecha y hora (ej: 202610152030): ");
    fflush(stdout);
    scanf("%llu", &nuevoEvento.fechaHora);

    nuevoEvento.estado = 1;

    // Limpiar el Enter pendiente del último scanf
    while ((c = getchar()) != '\n' && c != EOF);

    nuevoEvento.estado = 1;

    pflectura = fopen("Eventos.bin","rb");
    pfescritura = fopen("Eventostemp.bin","wb");


    if(!pfescritura)
    {
        printf("\nError al Abrir archivo Eventos escritura");
        return ERROR_ARCHIVO_ESCRITURA;
    }

    if (pflectura != NULL)
    {
        while (fread(&eventoActual, sizeof(tEvento), 1, pflectura) == 1)
        {
            // Si encontramos su lugar alfabético/numérico y aún no se insertó
            if (!idInsertado && strcmp(nuevoEvento.id, eventoActual.id) < 0)
            {
                fwrite(&nuevoEvento, sizeof(tEvento), 1, pfescritura);
                idInsertado = 1;
            }
            // Escribimos el evento actual del archivo original
            fwrite(&eventoActual, sizeof(tEvento), 1, pfescritura);
        }
        fclose(pflectura);
    }

    // Si el archivo estaba vacío o el ID nuevo es el mayor de todos, va al final
    if (!idInsertado)
    {
        fwrite(&nuevoEvento, sizeof(tEvento), 1, pfescritura);
    }

    fclose(pfescritura);

    remove("Eventos.bin");
    rename("Eventostemp.bin","Eventos.bin");
    fflush(stdout);
    printf("¡Evento registrado y ordenado por ID con éxito!\n");

    return INSERCION_ID;
}

/**
    //////////////////////USUARIO/////////////////////////////////
**/

void imprimirFechaHora(unsigned long long fechaHora)
{
    unsigned long long temp = fechaHora;

    int minuto = temp % 100;
    temp /= 100;

    int hora = temp % 100;
    temp /= 100;

    int dia = temp % 100;
    temp /= 100;

    int mes = temp % 100;
    temp /= 100;

    int anio = temp; // Lo que queda es el año

    // Muestra en formato DD/MM/YYYY - HH:MM
    printf("%02d/%02d/%d - %02d:%02d\n", dia, mes, anio, hora, minuto);
}

int consultarEventos()
{
    FILE *pf=fopen("Eventos.bin","rb");
    if(!pf)
    {
        printf("\nError a la apertura de archivo Eventos");
        return ERROR_ARCHIVO_LECTURA;
    }
    tEvento eventoActual;

    fread(&eventoActual,sizeof(tEvento),1,pf);
    printf("\n\t|||||||||||||||EVENTOS||||||||||||||||\n");
    while(!feof(pf))
    {
        printf("\n||||||||||||||||||||||||||||||||||||||||||");
        printf("\nID: %s",eventoActual.id);
        printf("\nNOMBRE: %s",eventoActual.nombre);
        printf("\nTIPO: %s",eventoActual.tipoEvento);
        printf("\nESTADO: %d",eventoActual.estado);
        printf("\nID ESTABLECIMIENTO: %u",eventoActual.idEstablecimiento);
        printf("\nFECHA/HORA: ");
        imprimirFechaHora(eventoActual.fechaHora);
        fread(&eventoActual,sizeof(tEvento),1,pf);
        printf("\n||||||||||||||||||||||||||||||||||||||||||");
    }

    fclose(pf);

    return 1;
}
