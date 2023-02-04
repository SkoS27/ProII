//TITLE: PROGRAMMING II LABS            SUBTITLE: P0
//
//AUTHOR 1: CARMELO ALEJANDRO GARCIA ALMEIDA    LOGIN 1: carmelo.garcia
//AUTHOR 2: MANUEL LAGO TIELAS                  LOGIN 2: m.lago.tielas
//
//GROUP: 4.4                                    DATE: 04/02/2023

#include <stdlib.h>
#include "rational_pointer.h"

Rational createRational(int n, int d) {
    Rational temp;
    temp= malloc(sizeof(*temp));
    temp->num= n;
    temp->den= d;
    return temp;
}
int numerator(Rational r) {
    return r->num;
}
int denominator(Rational r) {
    return r->den;
}
Rational sum(Rational r1, Rational r2) {
    Rational s;
    s = malloc(sizeof(*s));
    s->num = r1->num * r2->den + r2->num * r1->den;
    s->den = r1->den * r2->den;
    return s;
}