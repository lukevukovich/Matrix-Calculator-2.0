#ifndef MATRIXCALCULATOR2_0_CONTROLLER_H
#define MATRIXCALCULATOR2_0_CONTROLLER_H

//Max number of rows/columns
#define MATRIX 10

//Size of dimension arrays : 0 = rows, 1 = cols
#define DIM 2

//Max matrix value allowed
#define MAXVAL 999

//Enum used to select specific operand
enum MATRIX_ENUM {FIRST, SECOND};

/*
 * Controller class includes all data input & display functions
 * needed to control the program.
 */
class Controller {

protected:
    //Operand matrices
    int matrix1[MATRIX][MATRIX]{};
    int matrix2[MATRIX][MATRIX]{};
    //Result matrix
    int matrix3[MATRIX][MATRIX]{};

    //Dimensions of matrices : 0 = rows, 1 = cols
    int d1[DIM]{}, d2[DIM]{}, d3[DIM]{};

    //Operation input character
    char operation{};
    //Choice to keep previous data
    char choice{};

public:

    Controller() = default;

    //Resets all matrix and dimension values
    void resetAll();

    //Set specific operand matrix
    void setOperand(int[][MATRIX], int[], MATRIX_ENUM);
    //Print specific operand matrirx
    void printOperand(MATRIX_ENUM);
    //Print result matrix
    void printResult();

    //Get specific operand data input
    void operandInput(MATRIX_ENUM);

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
