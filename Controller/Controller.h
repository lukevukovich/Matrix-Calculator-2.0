#ifndef MATRIXCALCULATOR2_0_CONTROLLER_H
#define MATRIXCALCULATOR2_0_CONTROLLER_H

#include "../Matrix/Matrix.h"

//Max matrix value allowed
#define MAXVAL 999

/*
 * Controller class includes all data input & display functions
 * needed to control the program.
 */
class Controller {

private:
    //Operation input character
    char operation;
    //Choice to keep previous data
    char choice;

public:
    //Operand matrices
    Matrix matrix1 = Matrix();
    Matrix matrix2 = Matrix();
    //Result matrix
    Matrix result = Matrix();

    //Get specific operand data input
    void inputMatrix1();
    void inputMatrix2();

    //Print specific operand matrirx
    void printMatrix1();
    void printMatrix2();
    //Print result matrix
    void printResult();

    //Set operation char
    void setOperation(char);
    //Get operation char
    char getOperation();
    //Get user input for operation, does not set operation
    //Returns user input
    char operationInput();

    //Set choice char
    void setChoice(char);
    //Get choice char
    char getChoice();
    //Get user input for choice, does not set choice
    //Returns user input
    char choiceInput();
};

#endif //MATRIXCALCULATOR2_0_CONTROLLER_H
