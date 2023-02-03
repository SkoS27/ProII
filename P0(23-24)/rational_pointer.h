//
// Created by Carmelo on 03/02/2023.
//

#ifndef PROII_P0_RATIONAL_POINTER_H
#define PROII_P0_RATIONAL_POINTER_H

typedef struct Data* Rational;
struct Data {
    int num;
    int den;
};
Rational createRational(int n, int d);
int numerator(Rational r);
int denominator(Rational r);
Rational sum(Rational r1, Rational r2);

#endif //PROII_P0_RATIONAL_POINTER_H
