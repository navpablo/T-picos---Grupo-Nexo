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

    pfescritura= NULL;
    pflectura = NULL;

    ptrChar = nuevoEvento.id;
    while (ptrChar < nuevoEvento.id + 10)
    {
        *ptrChar = '\0';
        ptrChar++;
    }

    // 2. Ingreso de datos por teclado
    printf("=== ALTA DE NUEVO EVENTO ===\n");
    printf("Ingrese ID del evento (max 9 chars): ");
    scanf("%s", nuevoEvento.id);

    pflectura=fopen("Eventos.bin","rb");
    if(pflectura!=NULL)
    {
        fread(&eventoActual,sizeof(tEvento),1,pflectura);
        while(!feof(pflectura))
        {
            if (strcmp(eventoActual.id, nuevoEvento.id) == 0)
            {
                idRepetido = 1;

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

    printf("Ingrese nombre del evento: ");
    scanf("%s", nuevoEvento.nombre);

    printf("Ingrese tipo de evento: ");
    scanf("%s", nuevoEvento.tipoEvento);

    printf("Ingrese ID de establecimiento: ");
    scanf("%u", &nuevoEvento.idEstablecimiento);

    printf("Ingrese fecha y hora (ej: 202610152030): ");
    scanf("%llu", &nuevoEvento.fechaHora);

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

    fclose(pflectura);
    fclose(pfescritura);

    printf("¡Evento registrado y ordenado por ID con éxito!\n");
    return INSERCION_ID;
}
