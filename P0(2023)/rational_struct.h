//TITLE: PROGRAMMING II LABS            SUBTITLE: P0
//
//AUTHOR 1: CARMELO ALEJANDRO GARCIA ALMEIDA    LOGIN 1: carmelo.garcia
//AUTHOR 2: MANUEL LAGO TIELAS                  LOGIN 2: m.lago.tielas
//
//GROUP: 4.4                                    DATE: 04/02/2023


#ifndef PROII_P0_RATIONAL_STRUCT_H
#define PROII_P0_RATIONAL_STRUCT_H

typedef struct Data Rational;
struct Data {
    int num;
    int den;
};
Rational createRational(int n, int d);
int numerator(Rational r);
int denominator(Rational r);
Rational sum(Rational r1, Rational r2);

#endif //PROII_P0_RATIONAL_STRUCT_H
