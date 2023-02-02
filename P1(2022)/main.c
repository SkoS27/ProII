/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Pedro Botana Lobelle LOGIN 2: pedro.botana
 * GROUP: 2.4
 * DATE: 20 / 03 / 22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void New(char *param1, char *param2, char *param3, char *param4,tList *L);
//OBJETIVO:Añade un un producto nuevo a la lista previamente inicializada y creada
//ENTRADA:la id de producto, la id del vendedor, la categoria del producto, el precio del producto y la lista pasada como parametro
//SALIDA:no hay salida, es una funcion void, añade el elemento indicado a la lista
//PRECONDICION: la lista tiene que estar previamente creada e inicializada

void Stats(tList *L);
//OBJETIVO: Mostrar por pantalla los productos de la lista y los que hay en determinada categoria
//ENTRADA: la lista pasada como parametro
//SALIDA: se imprimen los elementos de la lista
//PRECONDICION: la lista tiene que estar previamente creada e inicializada

void Bid(char *param1, char *param2, char *param4,tList *L);
//OBJETIVO: registrar el numero y el dinero pujado por un producto
//ENTRADA: el id de producto, el id del comprador, el valor a pujar y la lista pasada como puntero
//SALIDA:ninguna, es simplemente un registro y actualizacion de la lista
//PRECONDICION: la lista tiene que estar previamente creada e inicializada

void Delete(char *param1,tList *L);
//OBJETIVO: eliminar un elemento de la lista
//ENTRADA: el producto a eliminar y la lista como puntero
//SALIDA: ninguna, es una funcion destructora


void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
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

			processCommand(commandNumber, command[0], param1, param2, param3, param4, &L);
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
	strcpy(producto.productId,param1);
	strcpy(producto.seller,param2);
	producto.bidCounter = 0;
	producto.productPrice= atof(param4);

	if(strcmp(param3,"painting")==0)
		producto.productCategory = painting;
	else
		producto.productCategory = book;

	if(findItem(producto.productId,*L) !=LNULL){

		printf("+ Error: New not possible\n");
	}
	else {

		if (insertItem(producto, LNULL, L) == true) {
			printf("* New: product %s seller %s category %s price %.2f\n", producto.productId, producto.seller, param3,
				   producto.productPrice);
		} else
			printf("+ Error: New not possible\n");

	}
}

void Stats(tList *L) {//no funciona el if-else y el for crea bucle infinito
	float bookprice = 0,bookaverage = 0,paintingprice = 0,paintingaverage = 0;
	int countbook = 0, countpainting = 0;
	tPosL p;
	if (!isEmptyList(*L)) {
		p= first(*L);
		while (p != LNULL){//en dinamica no funciona el for pero  en estatica for infinito
			tItemL producto = getItem(p, *L);
			printf("Product %s seller %s category %s price %.2f bids %2d\n", producto.productId, producto.seller, (producto.productCategory == painting ? "painting" : "book"),producto.productPrice,producto.bidCounter);
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
	}
	else{
		printf("+ Error: Stats not possile\n");
	}

}
void Bid(char *param1, char *param2, char *param3,tList *L){//no funciona el if-else o parece que no funciona
	tItemL producto;
	if(findItem(param1,*L) != LNULL){ // Si el elemento existe en la lista
		producto=getItem(findItem(param1,*L),*L);
		if (strcmp(param2,producto.seller)!=0){
			if(atof(param3) > producto.productPrice){
				producto.productPrice=atof(param3);
				producto.bidCounter++;
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
void Delete(char *param1,tList *L) {
	tPosL p;
	tItemL producto;
	if ((p=findItem(param1,*L)) !=LNULL) {
		producto = getItem(p, *L);
		printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", producto.productId, producto.seller,producto.productCategory == painting ? "painting" : "book", producto.productPrice, producto.bidCounter);
		deleteAtPosition(p, L);//elimina el elemento de la lista
	} else {
		printf("+ Error: Delete not possible\n");
	}
}



