/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "jury_list.h"

#define MAX_BUFFER 255

void create(tJuryName juryName, tNumVotes totalVoters, tListJ *listaJ);
void new(tJuryName juryName, tParticipantName participantName, tEUParticipant Eur, tListJ *listaJ);
void vote(tJuryName juryName, tParticipantName participantName, tListJ *listaJ);
void discualify(tParticipantName participantName, tListJ *listaJ);
void Remove(tListJ *listaJ);
void stats(tListJ *listaJ);
void winners(tListJ *listaJ);
tEUParticipant conversorBool(char *Eur);
tNumVotes conversorInt(char *votes);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *lJ) {
    printf("********************\n");
    switch (command) {
        case 'C':
            printf("%s %c: jury %s totalvoters %s\n", commandNumber, command, param1, param2);
            create(param1, conversorInt(param2), lJ);
            break;
        case 'N':
            printf("%s %c: jury %s participant %s location %s\n", commandNumber, command, param1, param2, param3);
            new(param1, param2, conversorBool(param3), lJ);
            break;
        case 'V':
            printf("%s %c: jury %s participant %s\n", commandNumber, command, param1, param2);
            vote(param1, param2, lJ);
            break;
        case 'D':
            printf("%s %c: participant %s\n", commandNumber, command, param1);
            discualify(param1, lJ);
            break;
        case 'S':
            printf("%s %c:\n",commandNumber, command);
            stats(lJ);

            break;
        case 'R':
            printf("%s %c:\n",commandNumber, command);
            Remove(lJ);
            break;
        case 'W':
            printf("%s %c:\n",commandNumber, command);
            winners(lJ);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tListJ lj;
    createEmptyListJ(&lj);
    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &lj);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "create.txt";

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

void create(tJuryName juryName, tNumVotes totalVoters, tListJ *listaJ){
    tItemJ jury;
    strcpy(jury.juryName, juryName);
    jury.totalVoters= totalVoters, jury.validVotes=0, jury.nullVotes=0;
    createEmptyListP(&jury.participantList);

    if(findItemJ(juryName, *listaJ)==NULLJ && insertItemJ(jury, listaJ))
        printf("* Create: jury %s totalvoters %d\n",juryName, totalVoters);
    else printf("+ Error: Create not possible\n");

}

void new(tJuryName juryName, tParticipantName participantName,tEUParticipant Eur, tListJ *listaJ){
    tPosJ p = findItemJ(juryName, *listaJ);
    if(p!=NULLJ && listaJ->data[p].validVotes+listaJ->data[p].nullVotes <= listaJ->data[p].totalVoters && findItemP(participantName, listaJ->data[p].participantList) == NULLP) {
            tItemP votante;
            strcpy(votante.participantName, participantName);
            votante.numVotes = 0;
            votante.EUParticipant = Eur;

            if (insertItemP(votante, &listaJ->data[p].participantList))
                printf("* New: jury %s participant %s location %s\n", listaJ->data[p].juryName,
                       votante.participantName,
                       votante.EUParticipant == true ? "eu" : "non-eu");
            else printf("+ Error: New not possible");
    }else printf("+ Error: New not possible\n");
}

void vote(tJuryName juryName, tParticipantName participantName, tListJ *listaJ){
    tPosJ p = findItemJ(juryName, *listaJ);
    if(p!=NULLJ){
        tPosP aux = findItemP(participantName,listaJ->data[p].participantList);
        if(aux!=NULLP){
            tItemP votante = getItemP(aux, listaJ->data[p].participantList);
            votante.numVotes++;
            listaJ->data[p].validVotes++;
            updateItemP(votante, aux, &listaJ->data[p].participantList);
            printf("* Vote: jury %s participant %s location %s numvotes %d\n", listaJ->data[p].juryName,votante.participantName, votante.EUParticipant == true ? "eu" : "non-eu", votante.numVotes);
        }else {
            printf("+ Error: Vote not possible. Participant %s not found in jury %s. NULLVOTE\n", participantName,listaJ->data[p].juryName);
            listaJ->data[p].nullVotes++;
        }
    }else printf("+ Error: Vote not possible\n");
}

void discualify(tParticipantName participantName, tListJ *listaJ){
    int i = 0;
    if(!isEmptyListJ(*listaJ)) {
        while (i<=listaJ->LastPos) {
            tPosP p = findItemP(participantName, listaJ->data[i].participantList);
            if (p != NULLP) {
                tItemP votante = getItemP(p, listaJ->data[i].participantList);
                listaJ->data[i].validVotes -= votante.numVotes;
                listaJ->data[i].nullVotes += votante.numVotes;
                deleteAtPositionP(p, &listaJ->data[i].participantList);
                printf("Jury %s\nParticipant %s disqualified\n\n",listaJ->data[i].juryName, participantName);
            }
            else printf("Jury %s\nNo participant %s\n\n",listaJ->data[i].juryName, participantName);
            i++;
        }
    }
    else printf("+ Error: Disqualify not possible\n");
}

void stats(tListJ *listaJ){
    int i = 0;
    if(!isEmptyListJ(*listaJ)) {
        while (i<=listaJ->LastPos) {
            printf("Jury %s\n",listaJ->data[i].juryName);
            tPosP p = firstP(listaJ->data[i].participantList);
            if(isEmptyListP(listaJ->data[i].participantList)) {
                printf("No participants\n");
            }
            else {
                for (; p != NULLP; p = nextP(p, listaJ->data[i].participantList)){
                    if (listaJ->data[i].validVotes == 0)
                        printf("Participant %s location %s numvotes %d (%.2f%%)\n", p->data.participantName,
                               p->data.EUParticipant == true ? "eu" : "non-eu",
                               p->data.numVotes, 0.00);
                    else
                        printf("Participant %s location %s numvotes %d (%.2f%%)\n", p->data.participantName,
                               p->data.EUParticipant == true ? "eu" : "non-eu",
                               p->data.numVotes, ((float)p->data.numVotes / (float)listaJ->data[i].validVotes) * 100.00);
                }
            }
            printf("Nullvotes %d\n", listaJ->data[i].nullVotes);
            printf("Participation: %d votes from %d voters (%.2f%%)\n\n",listaJ->data[i].validVotes+listaJ->data[i].nullVotes,
                   listaJ->data[i].totalVoters, ((float)(listaJ->data[i].validVotes+listaJ->data[i].nullVotes) / (float)listaJ->data[i].totalVoters ) *100.00);

            i++;
        }
    }else printf("+ Error: Stats not possible\n");
}

void Remove(tListJ *listaJ){
    int i = 0;
    if(!isEmptyListJ(*listaJ)) {
        while (i<=listaJ->LastPos) {
            if(listaJ->data[i].validVotes==0){
                printf("* Remove: jury %s\n", listaJ->data[0].juryName);
                for (tPosP p= listaJ->data[i].participantList; p->next!=NULLP ; p= listaJ->data[i].participantList) {
                    deleteAtPositionP(p, &listaJ->data[i].participantList);
                }
                deleteAtPositionJ(i,listaJ);
            } else i++;
        }
    }else printf("+ Error: Remove not possible\n");
}

void winners(tListJ *listaJ){
    int i = 0;
    if(!isEmptyListJ(*listaJ)) {
        while (i<=listaJ->LastPos) {
            printf("Jury %s\n", listaJ->data[i].juryName);
            if (!isEmptyListP(listaJ->data[i].participantList)) {
                tItemP eur, noeur;
                bool empateEur = true, empateNoEur = true;
                tPosP p = firstP(listaJ->data[i].participantList);
                tPosP a = p, b = p;
                for (bool aux = true; aux == true && nextP(a, listaJ->data[i].participantList) != NULLP; a = nextP(a, listaJ->data[i].participantList)) {
                    if (a->data.EUParticipant) {
                        eur = a->data;
                        aux = false;
                    }
                }
                for (bool aux = true; aux == true && nextP(b, listaJ->data[i].participantList) !=NULLP; b = nextP(b, listaJ->data[i].participantList)) {
                    if (!b->data.EUParticipant) {
                        noeur = b->data;
                        aux = false;
                    }
                }
                for (; p != NULLP; p = nextP(p, listaJ->data[i].participantList)) {
                    if (p->data.EUParticipant && p->data.numVotes >= eur.numVotes) {
                        empateEur = false;
                        if(strcmp(p->data.participantName, eur.participantName) != 0 && p->data.numVotes == eur.numVotes){
                            empateEur=true;
                        }
                        eur = p->data;
                    }
                    if (!p->data.EUParticipant && p->data.numVotes >= noeur.numVotes) {
                        empateNoEur = false;
                        if(strcmp(p->data.participantName, noeur.participantName) != 0 && p->data.numVotes == noeur.numVotes){
                            empateNoEur=true;
                        }
                        noeur = p->data;
                    }
                }
                if (!empateEur) printf("Location eu: Participant %s numvotes %d\n", eur.participantName, eur.numVotes);
                else printf("Location eu: No winner\n");
                if (!empateNoEur)
                    printf("Location non-eu: Participant %s numvotes %d\n\n", noeur.participantName, noeur.numVotes);
                else printf("Location non-eu: No winner\n\n");
            } else printf("Location eu: No winner\nLocation non-eu: No winner\n\n");
            i++;
        }
    }else printf("+ Error: Winners not possible");
}




tEUParticipant conversorBool(char *Eur){
    if(strcmp(Eur,"eu")==0)
        return true;
    else
        return false;
}

tNumVotes conversorInt(char *votes){
    int num = (int)atof(votes);
    return num;
}