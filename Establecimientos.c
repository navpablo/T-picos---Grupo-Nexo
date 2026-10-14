#include "Establecimientos.h"
#define LIBRE 0
#define OCUPADO 1



void inicializarSector(tSector* sector) {
    for(int f = 0; f < sector->filas; f++) {
        for(int c = 0; c < sector->columnas; c++) {
            // Aquí SÍ puedes usar [f][c] sin ningún problema
            sector->ubicaciones[f][c].disponibilidad = 0;
        }
    }
}

/**
typedef struct{
    unsigned id;
    char nombre[15];
    unsigned capacidad;
    float precio;
    int filas;
    int columnas;
    tUbicacion ubicaciones[MAXF][MAXC];
}tSector;
{
    unsigned id;
    char nombre[30];
    char direccion[30];
    unsigned capacidadTotal;
    tSector sectores[MAX_SECTORES];
} tEstablecimiento;
**/
int crearArchEstablecimiento()
{
    int i;
    tEstablecimiento auxest[]= {
                                {1111,
                                "Estadio Monumental",
                                "Av.José Figueroa Alcorta 7597",
                                85018,
                                {
                                    {1, "Platea Baja", 15000, 45000.0, 10, 20} // Solo defines los datos base del sector
                                }
                                },
                            {
                                2222,
                                "Estadio Velez Sarfield",
                                "Av.Juan.B Justo 920",
                                49540,
                            {
                              {1, "Platea Baja", 15000, 45000.0, 10, 20},
                                {2, "Popular", 45018, 15000.0, 15, 30}
                            }
                            // Solo defines los datos base del sector
                            },

                        {
                            3333,
                            "Luna Park",
                            "Av. Corrientes 990",
                            10000,
                        {
                           {1, "Campo", 5000, 25000.0, 20, 25},        // Sector 0
                            {2, "Pullman", 3000, 35000.0, 10, 10}
                        }
                               // Sector 1
                        }
                            };


    int cantEstablecimientos = 3;

    for(i=0;i<cantEstablecimientos;i++)
    {
        inicializarSector(auxest->sectores);
    }


    FILE *pf= fopen("Establecimiento.bin","wb");
    if(!pf)
    {
        printf("\nError en la creacion del archivo establecimiento");
        return ERROR_APERTURA_ARCHIVO;
    }


    fclose(pf);
    return TODO_OK;
}
