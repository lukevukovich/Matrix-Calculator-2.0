#include "../Controller/Controller.h"

#ifndef MATRIXCALCULATOR2_0_CALCULATOR_H
#define MATRIXCALCULATOR2_0_CALCULATOR_H

/*
 * Calculator class inherits Controller class and includes
 * all calculation functions. Calculator class is an add-on
 * to Controller class
 */
class Calculator: public Controller {

private:
    //Controller controller;

public:
    Calculator() = default;

    //Functions that calculate result matrix values

    //Row sizes must be equal & column sizes must be equal
    void add();
    void sub();
    //Column size of first operand must equal row size of second operand
    void mult();
    //Performs operation on first matrix only
    void trans();

};

#endif //MATRIXCALCULATOR2_0_CALCULATOR_H
