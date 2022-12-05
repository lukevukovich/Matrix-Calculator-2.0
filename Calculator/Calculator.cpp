#include <iostream>
#include "Calculator.h"

using namespace std;

//Add operand matrices
void Calculator::add() {
    int i, j;

    //Row sizes must be equal & column sizes must be equal
    if (d1[0] == d2[0] && d1[1] == d2[1]) {

        //Set result matrix dimensions
        d3[0] = d1[0];
        d3[1] = d1[1];

        //Loop by dimensions
        for (i = 0; i < d3[0]; i++) {
            for (j = 0; j < d3[1]; j++) {
                //Add corresponding matrix values
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        //Print operand matrices
        printOperand(FIRST);
        printOperand(SECOND);
        //Print result matrix
        printResult();
    }
    //If not equal, print error message
    else
        cout << ("\nINOPERABLE MATRIX DIMENSIONS\n");

}

//Subtract operand matrices
//Exact same as add() function, except corresponding matrix values are subtracted
void Calculator::sub() {
    int i, j;

    if (d1[0] == d2[0] && d1[1] == d2[1]) {

        d3[0] = d1[0];
        d3[1] = d1[1];

        for (i = 0; i < d3[0]; i++) {
            for (j = 0; j < d3[1]; j++) {
                matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        printOperand(FIRST);
        printOperand(SECOND);
        printResult();
    }
    else
        cout << ("\nINOPERABLE MATRIX DIMENSIONS\n");

}

//Multiply operand matrices
void Calculator::mult() {
    //Column size of first operand must equal row size of second operand
    if (d1[1] == d2[0]) {
        //Set pivot to where dimensions are equal
        int pivot = d1[1];
        //Set dimensions of result matrix based on matrix multiplication rules
        d3[0] = d1[0];
        d3[1] = d2[1];

        int i, j, k, total = 0;

        //Loop by dimension
        for (i = 0; i < d3[0]; i++) {
            for (j = 0; j < d3[1]; j++) {
                //Loop by pivot. matrix1 loops by column. matrix2 loops by row (because they are equal)
                for (k = 0; k < pivot; k++) {
                    //Multiply corresponding pivot values and keep running total
                    total += matrix1[i][k] * matrix2[k][j];
                }
                //Set result matrix to total variable
                matrix3[i][j] = total;
                //Reset total
                total = 0;
            }
        }

        //Print operand matrices
        printOperand(FIRST);
        printOperand(SECOND);
        //Print result matrix
        printResult();
    }
    else
        //Print error if dimension pre-reqs are not met
        cout << ("\nINOPERABLE MATRIX DIMENSIONS\n");

}

//Transpose first operand matrix
void Calculator::trans() {
    int i, j;

    //Set dimensions of result matrix to opposite of operand matrix
    d3[0] = d1[1];
    d3[1] = d1[0];

    //Loop by dimension
    for (i = 0; i < d3[0]; i++) {
        for (j = 0; j < d3[1]; j++) {
            //Set result matrix values to opposite of operand matrix values
            matrix3[i][j] = matrix1[j][i];
        }
    }

    //Print first operand matrix
    printOperand(FIRST);
    //Print result matrix
    printResult();
}
