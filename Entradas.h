#ifndef ENTRADAS_H_INCLUDED
#define ENTRADAS_H_INCLUDED
typedef struct{
    char idCompra[10];
    int sector;
    int fila;
    int butaca;
    float precio;
    char estado[10];
}tEntrada;


#endif // ENTRADAS_H_INCLUDED
