/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Pedro Botana lobelle LOGIN 2: pedro.botana
 * GROUP: 2.4
 * DATE: 05 / 04 / 2022
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include <stdbool.h>
#define SNULL -1
#define SMAX 1000
typedef struct {
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;
typedef int tPosS;
typedef struct Stack{
    tItemS data[SMAX];
    tPosS top;
}tStack;

void createEmptyStack(tStack *Stack);
//OBJETIVO:crear una pila vacia
//ENTRADA:la pila a crear
//SALIDA:la pila creada
//PRECONDICION:que la pila esté inicializada
//POSTCONDICION:la pila no tiene elementos

bool push(tItemS d,tStack *Stack);
//OBJETIVO:insertar un elemento en la cima de la pila
//ENTRADA:el item a insertar y la pila
//SALIDA:devuelve true o false en funcion de que el elemento sea apilado

void pop(tStack *Stack);
//OBJETIVO:elimina de la pila el elemento situado en la cima de la pila
//ENTRADA:la pila
//SALIDA: la pila modificada sin el elemento de la cima
//PRECONDICION:la pila no esta vacia

tItemS peek(tStack Stack);
//OBJETIVO:recupera el elemento de la cima sin eliminarlo
//ENTRADA:la pila de la que recuperar el elemento
//SALIDA:el item de la cima
//PRECONDICION:la pila no esta vacia

bool isEmptyStack(tStack Stack);
//OBJETIVO:determinar si la pila está vacia o no
//ENTRADA:la pila que queremos comprobar si esta vacia
//SALIDA:valor booleano true o false

#endif
