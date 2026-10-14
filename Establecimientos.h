#ifndef ESTABLECIMIENTOS_H_INCLUDED
#define ESTABLECIMIENTOS_H_INCLUDED
#define MAX_SECTORES 15
#include "TPGrupal.h"
#define ERROR_APERTURA_ARCHIVO -1
#define TODO_OK 0

typedef struct{
    unsigned id;
    char nombre[30];
    char direccion[30];
    unsigned capacidadTotal;
    tSector sectores[MAX_SECTORES];
}tEstablecimiento;

int crearArchEstablecimiento();
void inicializarSector(tSector* sector);
#endif // ESTABLECIMIENTOS_H_INCLUDED
