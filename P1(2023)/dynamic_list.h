/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <stdbool.h>
#include "types.h"
#define LNULL NULL
typedef struct tnode* tPosL;
struct tnode{
    tItemL data;
    tPosL next;
}; typedef tPosL tList;

void createEmptyList(tList *L);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL next(tPosL p,tList l);
tPosL previous(tPosL p,tList L);
bool createNode(tPosL *p);
bool insertItem(tItemL d,tPosL p,tList *L);
void deleteAtPosition(tPosL p, tList *L);
tItemL getItem(tPosL p,tList L);
void updateItem(tItemL d, tPosL p,tList *L);
tPosL findItem(tParticipantName d, tList L);
#endif