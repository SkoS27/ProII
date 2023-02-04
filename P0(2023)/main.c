//TITLE: PROGRAMMING II LABS            SUBTITLE: P0
//
//AUTHOR 1: CARMELO ALEJANDRO GARCIA ALMEIDA    LOGIN 1: carmelo.garcia
//AUTHOR 2: MANUEL LAGO TIELAS                  LOGIN 2: m.lago.tielas
//
//GROUP: 4.4                                    DATE: 04/02/2023

#include <stdio.h>
#include "rational_pointer.h"
//#include "rational_struct.h"
int main () {
    Rational r1, r2, r3, r4, s;
    r1 = createRational(2, 3);
    r2 = createRational(5, 7);
    r3 = createRational(7, 3);
    r4 = createRational(5, 4);
    s = sum(r1, r2);
    printf("The sum is %d/ %d\n", numerator(s), denominator(s));
    s = sum(r3, r4);
    printf("The sum is %d/ %d\n", numerator(s), denominator(s));
}