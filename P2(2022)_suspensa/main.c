/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Pedro Botana Lobelle LOGIN 2: pedro.botana
 * GROUP: 2.4
 * DATE: 20 / 04 / 22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "product_list.h"

#define MAX_BUFFER 255

void New(char *param1, char *param2, char *param3, char *param4,tList *L);
//OBJETIVO:Añade un un producto nuevo a la lista previamente inicializada y creada(e inicializa la pila de pujas del producto)
//ENTRADA:la id de producto, la id del vendedor, la categoria del producto, el precio del producto y la lista pasada como parametro
//SALIDA:no hay salida, es una funcion void, añade el elemento indicado a la lista
//PRECONDICION: la lista tiene que estar previamente creada e inicializada

void Stats(tList *L);
//OBJETIVO: Mostrar por pantalla los productos de la lista, los que hay en determinada categoria junto a su media y la mayor puja de los productos en lista
//ENTRADA: la lista pasada como parametro
//SALIDA: se imprimen los elementos de la lista
//PRECONDICION: la lista tiene que estar previamente creada e inicializada
void Bid(char *param1, char *param2, char *param4,tList *L);
//OBJETIVO: registrar el numero de pujas y añadir la nueva puja a su respectiva pila de pujas
//ENTRADA: el id de producto, el id del comprador, el valor a pujar y la lista pasada como puntero
//SALIDA:ninguna, es simplemente un registro y actualizacion de la lista
//PRECONDICION: la lista y la pila tienen que estar previamente creadas e inicializadas

void TopBid(tList *L);
//OBJETIVO:recorre la lista buscando la mayor puja de cada elemento y su porcentaje de incremento de precio.Se seleciona el elemento con mayor porcentaje y se muestra por pantalla
//ENTRADA:la lista en la que tenemos que buscar la mejir puja
//SALIDA:ninguna, simplemente muestra por pantalla un determinado mensaje dependiendo de una condicion
//PRECONDICION: que exista la lista a comprobar y que existan pilas dentro de esos items de la lista

void Delete(char *param1,tList *L);
//OBJETIVO: eliminar un elemento de la lista
//ENTRADA: el producto a eliminar y la lista como puntero
//SALIDA: ninguna, es una funcion destructora

void Award(char *param1,tList *L);
//OBJETIVO: Asignar el ganador de la puja
//ENTRADA:el id del producto y la lista de productos
//SALIDA:no tiene salida,unicamente mestrala puja ganadora por pantalla

void Withdraw(char *param1,char *param2,tList *L);
//OBJETIVO: retirar la maxima puja de un producto
//ENTRADA:el  id de producto, el uusuario que pujó y la lista
//SALIDA: no tiene salida, solo se elimina la ultima puja deun producto y se muestra por pantalla

void Remove(tList *L);
//OBJETIVO:Eliminar los productos sin pujas
//ENTRADA:la lista en la que queremos eliminar los productos sin pujas
//SALIDA:la lista es modificada, ya que se eliminan los elementos sin pujas de la lista

void DeleteStack(tStack *stack);
//OBJETIVO:Eliminar una pila
//ENTRADA:la pilaa eliminar
//SALIDA:una pila vacia

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4,tList *L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s N: product %s seller %s category %s price %s\n", commandNumber, param1, param2, param3, param4);
            New(param1,param2, param3,param4, L);
            break;
        case 'S':
            printf("********************\n");
            printf("%s S\n", commandNumber);
            Stats(L);
            break;
        case 'B':
            printf("********************\n");
            printf("%s B: product %s bidder %s price %s \n",commandNumber,param1,param2,param3);
            Bid(param1,param2,param3,L);
            break;
        case 'D':
            printf("********************\n");
            printf("%s D: product %s\n",commandNumber,param1);
            Delete(param1,L);
            break;
        case 'A':
            printf("********************\n");
            printf("%s A: product %s \n", commandNumber, param1);
            Award(param1,L);
            break;
        case 'W':
            printf("********************\n");
            printf("%s W: product %s bidder %s\n", commandNumber, param1, param2);
            Withdraw(param1,param2,L);
            break;
        case 'R':
            printf("********************\n");
            printf("%s R\n", commandNumber);
            Remove(L);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    tList L;
    createEmptyList(&L);

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4,&L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}

void New(char *param1, char *param2, char *param3, char *param4,tList *L){
    tItemL producto;
    tStack Stack; //inicializar pila
    createEmptyStack(&Stack);
    strcpy(producto.productId,param1);
    strcpy(producto.seller,param2);
    producto.bidCounter = 0;
    producto.productPrice= atof(param4);
    producto.bidStack = Stack;

    if(strcmp(param3,"painting")==0)
        producto.productCategory = painting;
    else
        producto.productCategory = book;

    if(findItem(producto.productId,*L) !=LNULL){

        printf("+ Error: New not possible\n");
    }
    else {

        if (insertItem(producto,L) == true) {
            printf("* New: product %s seller %s category %s price %.2f\n", producto.productId, producto.seller, param3,
                   producto.productPrice);
        } else
            printf("+ Error: New not possible\n");

    }
}

void Stats(tList *L) {
    float bookprice = 0,bookaverage = 0,paintingprice = 0,paintingaverage = 0;
    int countbook = 0, countpainting = 0;
    tPosL p;
    if (!isEmptyList(*L)) {
        p= first(*L);
        while (p != LNULL){
            tItemL producto = getItem(p, *L);
            printf("Product %s seller %s category %s price %.2f", producto.productId, producto.seller, (producto.productCategory == painting ? "painting" : "book"),producto.productPrice,producto.bidCounter);
            if (!isEmptyStack(producto.bidStack)) {//muestra la mayor puja del producto
                printf(" bids %2d top bidder %s\n",producto.bidCounter,producto.bidStack.data->bidder);
            }
            else {
                printf(". No bids\n");
            }
            if(producto.productCategory == 1){
                countpainting++;
                paintingprice+=producto.productPrice;
            }
            else{
                countbook++;
                bookprice+=producto.productPrice;
            }
            p = next(p,*L);
        }
        printf("\nCategory  Products    Price  Average\n");
        if (countbook == 0)
            bookaverage = 0;
        else {
            bookaverage = bookprice / countbook;
        }
        printf("Book      %8d %8.2f %8.2f\n",countbook,bookprice,bookaverage);
        if (countpainting == 0)
            paintingaverage = 0;
        else {
            paintingaverage = paintingprice / countpainting;
        }
        printf("Painting  %8d %8.2f %8.2f\n",countpainting,paintingprice,paintingaverage);
        TopBid(L);
    }
    else{
        printf("+ Error: Stats not possile\n");
    }

}

void Bid(char *param1, char *param2, char *param3,tList *L){
    tItemL producto;
    if(findItem(param1,*L) != LNULL){ // Si el elemento existe en la lista
        producto=getItem(findItem(param1,*L),*L);
        if (strcmp(param2,producto.seller)!=0){//si el vendedor y el pujador es el mismo
            if(atof(param3) > (producto.productPrice || peek(producto.bidStack).productPrice)){//si la puja es mayor al precio o a la puja anterior
                tItemS d;
                d.productPrice=atof(param3);
                strcpy(d.bidder,param2);
                producto.bidCounter++;
                push(d,&producto.bidStack);
                updateItem(producto, findItem(param1, *L), L);
                printf("* Bid: product %s seller %s category %s price %.2f bids %d\n",producto.productId,producto.seller,producto.productCategory == painting ? "painting" : "book",producto.productPrice,producto.bidCounter);
            }
            else
                printf("+ Error: Bid not possible\n");
        }
        else
            printf("+ Error: Bid not possible\n");
    } else
        printf("+ Error: Bid not possible\n");
}

void TopBid(tList *L){
    tPosL p;
    tItemL d;
    p=first(*L);
    float porcentaje;
    porcentaje=0;
    while (p != LNULL){
        tItemS S;
        tItemL i;
        float f=0;
        i= getItem(p,*L);
        S= peek(i.bidStack);
        f=(((S.productPrice-i.productPrice)*100)/i.productPrice);
        if(f>porcentaje){
            porcentaje=f;
            d=i;
        }
        else;
        p=next(p,*L);
    }
    if(porcentaje>0){
        printf("Top bid: Product %s seller %s category %s price %.2f bidder %s top price %2.f increase %3.2f%\n",d.productId,d.seller,d.productCategory == painting ? "painting" : "book",d.productPrice,
               peek(d.bidStack).bidder, peek(d.bidStack).productPrice,porcentaje);
    }
    else
        printf("Top bid not possible\n");
}

void Delete(char *param1,tList *L){
    tPosL p;
    tItemL producto;
    if ((p=findItem(param1,*L)) !=LNULL) {
        producto = getItem(p, *L);
        printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", producto.productId, producto.seller,producto.productCategory == painting ? "painting" : "book", producto.productPrice, producto.bidCounter);
        //pop para eliminar los elementos de la pia
        deleteAtPosition(p, L);//elimina el elemento de la lista
    } else {
        printf("+ Error: Delete not possible\n");
    }
}

void Award(char *param1,tList *L){
    tPosL p;
    tItemL producto;
    if((p= findItem(param1,*L)) !=LNULL){
        producto= getItem(p,*L);
        printf("* Award: product %s bidder %s category %s price %.2f\n",producto.productId,peek(producto.bidStack).bidder,producto.productCategory == painting ? "painting" : "book",
               peek(producto.bidStack).productPrice);
        DeleteStack(&producto.bidStack);
        deleteAtPosition(p, L);
    } else
        printf("+ Error: Award not possible\n");
}

void Withdraw(char *param1,char *param2,tList *L){//problema con el stats no detecta la eliminacion de la puja
    tPosL p;
    tItemL producto;
    if((p= findItem(param1,*L)) !=LNULL) {
        producto = getItem(p, *L);
        if (!isEmptyStack(producto.bidStack)) {
            if (peek(producto.bidStack).bidder != param2) {
                printf("* Withdraw: product %s bidder %s category %s price %.2f bids  %d\n", producto.productId, param2,producto.productCategory == painting ? "painting" : "book",peek(producto.bidStack).productPrice, producto.bidCounter);
                pop(&producto.bidStack);
                producto.bidCounter = producto.bidCounter - 1;
                updateItem(producto,p,L);
            } else
                printf("+ Error: withdraw not possible\n");;
        } else
            printf("+ Error: withdraw not possible\n");
    }
    else
        printf("+ Error: withdraw not possible\n");
}

void Remove(tList *L) {
    tPosL p = first(*L);
    int count;
    count = 0;
    while (p != LNULL) {
        tItemL producto;
        producto = getItem(p, *L);
        if (isEmptyStack(producto.bidStack)) {
            printf("Removing product %s seller %s category %s price %.2f bids  %d\n", producto.productId,producto.seller, producto.productCategory == painting ? "painting" : "book", producto.productPrice,producto.bidCounter);
            deleteAtPosition(p,L);
            count++;
        }
        p= next(p,*L);
    }
    if(count==0){
        printf("+ Error: Remove not possible\n");
    }
}

void DeleteStack(tStack *stack){
    while (stack->top != SNULL){
        pop(stack);
    }
}