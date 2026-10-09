#ifndef ESTABLECIMIENTOS_H_INCLUDED
#define ESTABLECIMIENTOS_H_INCLUDED
#define MAX_SECTORES 15

typedef struct{
    unsigned id;
    char nombre[30];
    char direccion[30];
    unsigned capacidadTotal;
    tSector sectores[MAX_SECTORES];
}tEstablecimiento;


#endif // ESTABLECIMIENTOS_H_INCLUDED
