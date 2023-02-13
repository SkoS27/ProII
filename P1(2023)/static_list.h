/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#define LNULL -1
#define Max 1000
#include <stdbool.h>
#include "types.h"

typedef int tPosL;
typedef struct {
    tItemL data[Max];
    tPosL LastPos;
}tList;

void createEmptyList(tList *L);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p,tList L);
tPosL next(tPosL p, tList L);
tItemL getItem(tPosL p, tList L);
void updateItem(tItemL d, tPosL p,tList *L);
tPosL findItem(tParticipantName d, tList L);
bool insertItem(tItemL d, tPosL p, tList *L);
void deleteAtPosition(tPosL p, tList *L);

#endif
