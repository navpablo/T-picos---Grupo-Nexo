#ifndef EVENTOS_H_INCLUDED
#define EVENTOS_H_INCLUDED
#define DISPONIBLE 1
#define CANCELADO -1
#define FINALIZADO 2

typedef struct{
    char id[10];
    char nombre[30];
    char tipoEvento[30];
    unsigned idEstablecimiento;
    unsigned long long fechaHora;
    int estado;
}tEvento;


#endif // EVENTOS_H_INCLUDED
