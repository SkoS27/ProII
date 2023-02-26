/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carmelo Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Manuel Lago Tielas LOGIN 2: m.lago.tielas
 * GROUP: 4.4
 * DATE: 26 / 02 / 23
 */


#include "dynamic_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void createEmptyList(tList *L){
    *L = LNULL;
}

bool isEmptyList(tList L){
    return(L == LNULL);
}

tPosL first(tList L){
    return L;
}

tPosL next(tPosL p, tList L){
    return p-> next;
}

tPosL previous(tPosL p,tList L){
    tPosL q;
    if (p==first(L)) {
        return LNULL;
    }
    else {
        for (q = L;q->next!=p;q=q->next);
        return q;
    }
}

bool createNode(tPosL *p){
    *p = malloc(sizeof(struct tnode));
    return *p !=NULL;
}

bool insertItem(tItemL d,tPosL p,tList *L){
    tPosL q, r;
    if (!createNode(&q))
        return false;
    else{
        q->data=d;
        q->next=LNULL;
        if (*L==LNULL)
            *L=q;
        else if (p==LNULL){
            for (r=*L; r->next!=LNULL; r=r->next);
            r->next=q;
        }
        else if (p==*L){
            q->next=p;
            *L=q;
        }
        else{
            q->data=p->data;
            p->data=d;
            q->next=p->next;
            p->next=q;
        }
        return true;
    }
}

tPosL last(tList L){
    tPosL p;
    for (p = L;p->next != LNULL ; p = p->next);
    return p;
}

void deleteAtPosition(tPosL p, tList *L){
    tPosL q;
    if (p==*L)
        *L = (*L)->next;
    else if(p->next == LNULL){
        for (q= *L; q->next != p; q = q->next);
        q->next =LNULL;
    }
    else{
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p=q;
    }
    free(p);
}

tItemL getItem(tPosL p,tList L){
    return p->data;
}

void updateItem(tItemL d, tPosL p,tList *L){
    p->data=d;
}

tPosL findItem(tParticipantName d, tList L){
    tList p;
    if(isEmptyList(L)) {
        p = LNULL;
    }else{
        for (p=L;(p!=LNULL)&&(strcmp(p->data.participantName, d)!=0);p=p->next);
    }
    return p;
}