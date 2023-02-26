/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carmelo Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Manuel Lago Tielas LOGIN 2: m.lago.tielas
 * GROUP: 4.4
 * DATE: 26 / 02 / 23
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


void readTasks(char *filename, int *nullvotes, int *totalvotes);
void processCommand(char *commandNumber, char command, char *param1, char *param2, int *nullvotes, int *totalvotes, tList *lista);
void New(tParticipantName Pais, char *Eur, tList *list);
void Vote(tParticipantName Pais, int *nullvotes, int *totalvotes, tList *list);
void Disqualify(tParticipantName Pais, int *nullvotes, int *totalvotes, tList *list);
void Stats(tList *list,int nullvotes, int totalvotes, char *param1);



int main(int nargs, char **args) {
    char *file_name = "disqualify2.txt";
    int nullvotes=0,totalvotes=0;
    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &nullvotes, &totalvotes);

    return 0;
}

void processCommand(char *commandNumber, char command, char *param1, char *param2,int *nullvotes, int *totalvotes, tList *lista) {
    switch (command) {
        case 'N':
            printf("\n********************\n");
            printf("%s %c: participant %s location %s", commandNumber, command, param1, param2);
            New(param1, param2, lista);
            break;
        case 'V':
            printf("\n********************\n");
            printf("%s %c: participant %s", commandNumber, command, param1);
            Vote(param1, nullvotes,totalvotes, lista);
            break;
        case 'D':
            printf("\n********************\n");
            printf("%s %c: participant %s", commandNumber, command, param1);
            Disqualify(param1, nullvotes, totalvotes, lista);
            break;
        case 'S':
            printf("\n********************\n");
            printf("%s %c: totalvoters %s",commandNumber,command,param1);
            Stats(lista, *nullvotes,*totalvotes, param1);
            break;
        default:
            break;
    }
}

void readTasks(char *filename, int *nullvotes, int *totalvotes) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tList lista;
    createEmptyList(&lista);

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, nullvotes,totalvotes, &lista);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

void New (tParticipantName Pais, char *Eur, tList *list){
    //Creación do producto utilizado
    tItemL votante;
    strcpy(votante.participantName, Pais);  //Asociación de product co producto.productId.
    votante.numVotes = 0;

    if(strcmp(Eur,"eu")==0)
        votante.EUParticipant = true;
    else
        votante.EUParticipant = false;  //Asociación de category co producto.productCategory.


    if((findItem(votante.participantName, *list)==LNULL) && (insertItem(votante, LNULL, list)==true))
        // Si la posición es nula, se inserta el elemento en la lista en el caso de que sea verdadero.
        printf("\n* New: participant %s location %s", votante.participantName, votante.EUParticipant == true ? "eu" : "non-eu");

    else // Se a posición é distinta a nula ou o insertItem sexa falso porque non se pode insertar, manda unha mensaxe de erro.
        printf("\n+ Error: New not possible");
}

void Vote(tParticipantName Pais,int *nullvotes, int *totalvotes, tList *list) {
    if (isEmptyList(*list)) {
        printf("\n+ Error: Vote not possible. Participant %s not found. NULLVOTE", Pais);
    } else {
        tPosL p = findItem(Pais, *list);
        if (p == LNULL) {
            (*nullvotes)++;
            printf("\n+ Error: Vote not possible. Participant %s not found. NULLVOTE", Pais);
        } else {
            tItemL votante = getItem(p, *list);
            votante.numVotes++;
            (*totalvotes)++;
            updateItem(votante, p, list);
            printf("\n* Vote: participant %s location %s numvotes %i", votante.participantName,
                   votante.EUParticipant == true ? "eu" : "non-eu", votante.numVotes);
        }

    }
}

void Disqualify(tParticipantName Pais, int *nullvotes, int *totalvotes, tList *list){
    if(!isEmptyList(*list)){
        tPosL p = findItem(Pais,*list);
        int nulos_pais;
        if (p == LNULL) {
            printf("\n+ Error: Disqualify not possible. Participant %s not found.", Pais);
        } else {
            tItemL votante = getItem(p, *list);
            nulos_pais=votante.numVotes;
            *nullvotes+=nulos_pais;
            *totalvotes-=nulos_pais;
            printf("\n* Disqualify: participant %s location %s", votante.participantName,
                   votante.EUParticipant == true ? "eu" : "non-eu");
            deleteAtPosition(p, list);
        }
    }
}

void Stats(tList *list,int nullvotes, int totalvotes, char *param1) {
    tPosL p;
    if (!isEmptyList(*list)) {
        p = first(*list);
        while (p != LNULL) {
            tItemL participant = getItem(p, *list);
            if (totalvotes == 0) {
                printf("\nParticipant %s location %s numvotes %d (%.2f%%)", participant.participantName,
                       participant.EUParticipant == true ? "eu" : "non-eu", participant.numVotes,
                       0.00);
            } else {
                printf("\nParticipant %s location %s numvotes %d (%.2f%%)", participant.participantName,
                       participant.EUParticipant == true ? "eu" : "non-eu", participant.numVotes,
                       (((float)participant.numVotes / (float)totalvotes) * 100.00));
            }
            p = next(p, *list);
        }
        printf("\nNull votes %d", nullvotes);
        printf("\nParticipation: %d votes from %s voters (%.2f%%)", totalvotes+nullvotes, param1,
               ((totalvotes+nullvotes) / atof(param1)) * 100.00);
    }else {
            printf("\n+ Error: Stats not possile");
        }
    }

