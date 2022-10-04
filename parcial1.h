#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#define N 10

static int id = 0;

typedef struct proceso{
int procesador;
int id_proceso;
int prioridad;
char estado[10];
}Proceso;

Proceso* scheduling[10];

void asignaEstado(Proceso*);
void ingresaProceso();
int terminaProceso();
void recorreCola();
void mostrarScheduler();