/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: **********
 * AUTHOR 2: Pedro Botana Lobelle LOGIN 2: **********
 * GROUP: 2.4
 * DATE: 22 / 02 / 2022
 */

#include "dynamic_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void createEmptyList(tList *L){
    *L==LNULL;
}

bool isEmptyList(tList L){
    return (L==LNULL);
}

tPosL first(tList L){
    return L;
}



tPosL next(tPosL p, tList L){
    return p->next;
}

tPosL previous(tPosL p,tList L){
    tPosL q;
    if (p==L)
        return LNULL;
    else {
        for (q = L; q->next != p; q = q->next);
        return q
    }
}

bool createNode(tPosL *p){
    *p=malloc(sizeof(**p));
    return *p !=NULL;
}

bool insertItem(tItemL d,tPosL p,tList *L){
    tPosL q,r;
    if(!createNode(&q))
        return false;
    else{
        q->data=d;
        q->next=LNULL;
        if (*L==LNULL){
            *L=q;
        }
        else if (p==LNULL)
        {
            r=*L;
            while (r->next!=LNULL)
                r->next=q;
        } else if (p==*L)
        {
            q->next = *L;
            *L=q;
        } else{
            q->data=p->data;
            p->data = d;
            q->next =p->next;
            p->next=q;
        }
        return true;
    }
}

tPosL last(tList L){
    tPosL q;
    for (q = L; q->next !=LNULL; q = q->next);
    return q;
}

void deleteAtPosition(tPosL p, tList *L){

}

tItemL getItem(tPosL p,tList L){

}

void updateItem(tItemL d, tPosL p,tList *L){

}

tPosL findItem(tProductId d, tList L){

}