/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"
#include <string.h>

void createEmptyList(tList *L){
    L->LastPos=LNULL;/* Creamos una lista vacia igualando el tPosL LastPos a LNULL */
}
bool isEmptyList(tList L){
    return (L.LastPos==LNULL);/*Comprobamos si la lista esta vacia comparando Lastpos con LNULL*/
}
tPosL first(tList L){
    return 0;/*devolvemos la primera posicion de la lista (return 0;)*/
}
tPosL last(tList L){
    return L.LastPos;/* Devolvemos el valor de LastPos, es decir la ultima posicion*/
}
tPosL previous(tPosL p,tList L){
    if (p== first(L)){/*si la posicion dada es la primera devolvemos LNULL*/
        return LNULL;
    }
    else
        return --p;/*devolvemos la posicion p-1*/
}
tPosL next(tPosL p, tList L){
    if (p== last(L))/*si la posicion dada es la ultima devolvemos LNULL*/
        return LNULL;
    else
        return ++p;/*devolvemos la posicion p+1*/
}
tItemL getItem(tPosL p, tList L){
    return L.data[p];/* devuelve los datos en la posicion dada p*/
}
void updateItem(tItemL d, tPosL p,tList *L){
    L->data[p]=d;/*igualamos los datos de la posicion p a los nuevos datos d*/
}
tPosL findItem(tParticipantName d,tList L){
    tPosL p;
    if (L.LastPos==LNULL)
        return LNULL;/*si la lista esta vacia devuelve LNULL*/
    else{
        for (p = first(L); (p<=L.LastPos)&&(strcmp(d,L.data[p].participantName)!=0); p++);/*mientras p sea distinto de la ultima posicion avanza desde la primera hasta la ultima*/
        if (strcmp(L.data[p].participantName, d) != 0) /*comparo el productid de la posicion p con el producto que queremos encontrar*/
            return LNULL;
        else
            return p;
    }
}
bool insertItem(tItemL d, tPosL p, tList *L){
    tPosL i;
    if (L->LastPos==Max-1){
        return false;/*si la lista esta llena devolvemos false*/
    }
    else if(p==LNULL){
        L->LastPos++;/*si tPosL p es igual a LNULL insertamos el item en la ultima posicion de la lista*/
        L->data[L->LastPos]= d;
        return true;
    }
    else{
        L->LastPos++;
        for (i = L->LastPos; i>= p+1 ; i--) {
            L->data[i]=L->data[i-1];}/*recorremos la lista desde la ultima posicion a la posicion donde vamos a insertar el nuevo item y lo insertamos*/
        L->data[p]=d;
        return true;/*devolvemos true ya que se ha podido insertar el nuevo elemento*/
    }
}
void deleteAtPosition(tPosL p, tList *L){
    tPosL i;
    L->LastPos--;/*reducimos la lista una posicion*/
    for ( i = p; i <=L->LastPos ; i++)/*desde la posicion a eliminar recorremos la lista hasta la ultima posicion sustituyendo los datos de la posicion en la que estamos por los de la posicion siguiente*/
        L->data[i]=L->data[i+1];
}
