/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Pedro Botana lobelle LOGIN 2: pedro.botana
 * GROUP: 2.4
 * DATE: 05 / 04 / 2022
 */

#include "product_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void createEmptyList(tList* L){
    *L = LNULL;
}

bool createNode(tPosL *p){
    *p = malloc(sizeof(struct tnode));
    return *p !=NULL;
}

void updateItem(tItemL d,tPosL p,tList* L){
    p->data=d;
}

void deleteAtPosition(tPosL p,tList* L){
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
bool insertItem(tItemL d,tList* L){
    tPosL p,q;
    if (!createNode(&q))
        return false;
    else{
        q->data=d;
        q->next=LNULL;
        if(*L==LNULL) {
            *L = q;
        }
        else if(strcmp(d.productId,(*L)->data.productId)<0)
        {
            q->next=*L;
            *L=q;
        }
        else{
            p=findPosition(*L,d);
            q->next=p->next;
            p->next=q;
        }
        return true;
    }
}
bool isEmptyList(tList L){
    return(L == LNULL);
}
tPosL findItem(tProductId d, tList L){
    tPosL p;
    for (p=L;(p!=LNULL)&&(strcmp(p->data.productId,d)!=0);p=p->next);
        if(p!=LNULL && strcmp(p->data.productId,d)==0)
            return p;
        else
            return LNULL;
}
tPosL first(tList L){
    return L;
}
tPosL last(tList L){
    tPosL p;
    for (p = L;p->next != LNULL ; p = p->next);
    return p;
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

tPosL next(tPosL p,tList L){
    return p-> next;
}

tPosL findPosition(tList L,tItemL d){
    tPosL p;
    p= first(L);
    while (p->next!=LNULL && strcmp(p->next->data.productId,d.productId)<0)
        p=p->next;
    return p;
}