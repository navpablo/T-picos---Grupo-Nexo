#ifndef TP_GRUPAL_H_INCLUDED
#define TP_GRUPAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define COLOR_TITULO    11
#define COLOR_MENU_PRINCIPAL      14
#define COLOR_TEXTO     15
#define MAXF 30
#define MAXC 45
#define IDENTIFICADOR_REPETIDO -111
#define ERROR_ARCHIVO_LECTURA -888
#define ERROR_ARCHIVO_ESCRITURA -999
#define INSERCION_ID 999

typedef struct{
    int fila;
    int columna;
    int disponibilidad;
}tUbicacion;

typedef struct{
    unsigned id;
    char nombre[15];
    unsigned capacidad;
    float precio;
    int filas;
    int columnas;
    tUbicacion ubicaciones[MAXF][MAXC];
}tSector;


#endif // TP_GRUPAL_H_INCLUDED
