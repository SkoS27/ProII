/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Pedro Botana lobelle LOGIN 2: pedro.botana
 * GROUP: 2.4
 * DATE: 05 / 04 / 2022
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "types.h"
#include <stdbool.h>
#include "bid_stack.h"
#define LNULL NULL
typedef struct tnode* tPosL;
typedef struct {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidStack;
}tItemL;
struct tnode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;
tPosL findPosition(tList L,tItemL d);
//OBJETIVO: buscar la posicion del item dado en la lista
//ENTRADA:la lista y el item a buscar
//SALIDA:la posicion del item de la lista
//PRECONDICION:que el item a buscar sea un elemento de la lista

void createEmptyList(tList* L);
//OBJETIVO: Crea una lista vacia
//ENTRADA: Lista a crear
//SALIDA: Lista creada y vacia
//POSTCONDICION:que la lista se haya crreado

void updateItem(tItemL d,tPosL p,tList* L);
//OBJETIVO: modifica el contenido del elemento situado en la posicion indicada
//ENTRADA: el contenido nuevo con el que vamos a sustituir el anterior, la posicion y la lista
//SALIDA: no hay salida, simplemente se actualiza la lista
//PRECONDICION: la posicion indicada es una posicion valida de la lista
//POSTCONDICION:el orden de los elementos de la lista no se ve modificado

void deleteAtPosition(tPosL p,tList* L);
//OBJETIVO: eliminar un elemento de la lista
//ENTRADA: la posicion a eliminar y la lista
//SALIDA: no devuelve ningun valor, simplemente elimina
//PRECONDICION: la posicion indicada es una posicion valida de la lista
//POSTCONDICION: las posiciones de los elementos posteriores a la del elemento eliminado se pueden ver modificadas

tItemL getItem(tPosL p,tList L);
//OBJETIVO: devuelve el contenido del elemento de la lista que ocupa la posicion indicada
//ENTRADA: la posicion de la que queremos obtener el contenido y la lista
//SALIDA: el tItemL de la posicion dada
//PRECONDICION: la posicion indicada es una posicion valida de la lista

bool insertItem(tItemL d,tList* L);//
//OBJETIVO: insertar un nuevo elemento en la lista
//ENTRADA: el elemento a insertar, su posicion y la lista (si la posicion es LNULL se añade al final de la lista)
//SALIDA:devuelve el valor True o False, en caso de que haya insertado el elemento o en caso contrario
//PRECONDICION: la posicion indicada es una posicion valida de la lista
//POSTCONDICION: las posiciones de los elementos posteriores a la del elemento insertado se pueden ver modificadas

bool isEmptyList(tList L);
//OBJETIVO: Comprobar si la lista está vacia
//ENTRADA: la lista a comprobar
//SALIDA: booleano True o False

tPosL findItem(tProductId d, tList L);//
//OBJETIVO: devuelve la posicion del primer elemento cuyo identificador coincide con el dado
//ENTRADA: el identificador del elemento a buscar y la lista
//SALIDA: la posicion del primer elemento que coincida con el identificador(o LNULL si no existe)

tPosL first(tList L);
//OBJETIVO: localizar el primer elemento de la lista
//ENTRADA:la lista de la que queremos obtener el primer elemento
//SALIDA:la primera posicion de la lista
//PRECONDICION:que la lista no este vacia

tPosL last(tList L);
//OBJETIVO:localizarel ultimo elemento de la lista
//ENTRADA:la lista de la que queremos obtener el primer elemento
//SALIDA:la ultima posicion de la lista
//PRECONDICION:que la lista no este vacia

tPosL previous(tPosL p,tList L);
//OBJETIVO:devuelve el elemento previo al elemento indicado
//ENTRADA:la lista y la posicion de la que queremos obtener el elemento previo
//SALIDA:la posicion previa a la indicada
//PRECONDICION:la posicion indicada es una posicion valida de la lista

tPosL next(tPosL p,tList L);
//OBJETIVO: devuelve la posicion siguiente a la del elemento indicado
//ENTRADA: La lista y la posicion de la que queremos obtener la posicion siguiente
//SALIDA: la posicion posterior a la dada
//PRECONDICION: la posicion indicada es una posicion valida de la lista

bool createNode(tPosL *p);
//OBJETIVO: crea un nuevo nodo en la lista
//ENTRADA: la posicion donde creamos el nodo
//SALIDA: devuelve true si se ha creado el nodo

#endif
