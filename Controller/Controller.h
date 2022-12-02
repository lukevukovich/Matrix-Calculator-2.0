#ifndef MATRIXCALCULATOR2_0_CONTROLLER_H
#define MATRIXCALCULATOR2_0_CONTROLLER_H

//Max number of rows/columns
#define MATRIX 10

//Size of dimension arrays : 0 = rows, 1 = cols
#define DIM 2

//Max matrix value allowed
#define MAXVAL 999

enum MATRIX_ENUM {FIRST, SECOND};

class Controller {

private:
    int matrix1[MATRIX][MATRIX]{};
    int matrix2[MATRIX][MATRIX]{};
    int matrix3[MATRIX][MATRIX]{};

    int d1[DIM]{}, d2[DIM]{}, d3[DIM]{};

    char operation{};
    char choice{};

public:

    Controller() = default;

    void resetAll();

    void setOperand(int[][MATRIX], int[], MATRIX_ENUM);
    void printOperand(MATRIX_ENUM);
    void printResult();

    void operandInput(MATRIX_ENUM);

    void setOperation(char);
    char getOperation();

    char getOperationInput();

    void setChoice(char);
    char getChoice();

    char getChoiceInput();

    void add();
    void sub();
    void mult();
    void trans();
};

#endif //MATRIXCALCULATOR2_0_CONTROLLER_H
