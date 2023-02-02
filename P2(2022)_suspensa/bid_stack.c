/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carmelo Alejandro Garcia Almeida LOGIN 1: carmelo.garcia
 * AUTHOR 2: Pedro Botana lobelle LOGIN 2: pedro.botana
 * GROUP: 2.4
 * DATE: 05 / 04 / 2022
 */

#include "bid_stack.h"
void createEmptyStack(tStack *Stack){
    Stack->top=SNULL;
}
bool push(tItemS d,tStack *Stack){
    if (Stack->top==SMAX-1)
        return false;
    else{
        Stack->top++;
        Stack->data[Stack->top]=d;
        return true;
    }
}
void pop(tStack *Stack){
    Stack->top--;
}
tItemS peek(tStack Stack){
    return Stack.data[Stack.top];
}
bool isEmptyStack(tStack Stack){
    return (Stack.top==SNULL);
}