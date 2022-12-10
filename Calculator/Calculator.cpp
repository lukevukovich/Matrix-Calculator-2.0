#include <iostream>
#include "Calculator.h"

using namespace std;

//Add operand matrices
void Calculator::add() {
    int i, j;

    //Row sizes must be equal & column sizes must be equal
    if (matrix1.rows == matrix2.rows &&
        matrix1.cols == matrix2.cols) {

        //Set result matrix dimensions
        result.setSize(matrix1.rows, matrix1.cols);

        //Loop by dimensions
        for (i = 0; i < result.rows; i++) {
            for (j = 0; j < result.cols; j++) {
                //Add corresponding matrix values
                result.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
            }
        }

        //Print operand matrices
        printMatrix1();
        printMatrix2();
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

    //Row sizes must be equal & column sizes must be equal
    if (matrix1.rows == matrix2.rows &&
        matrix1.cols == matrix2.cols) {

        //Set result matrix dimensions
        result.setSize(matrix1.rows, matrix1.cols);

        //Loop by dimensions
        for (i = 0; i < result.rows; i++) {
            for (j = 0; j < result.cols; j++) {
                //Add corresponding matrix values
                result.matrix[i][j] = matrix1.matrix[i][j] - matrix2.matrix[i][j];
            }
        }

        //Print operand matrices
        printMatrix1();
        printMatrix2();
        //Print result matrix
        printResult();
    }
        //If not equal, print error message
    else
        cout << ("\nINOPERABLE MATRIX DIMENSIONS\n");

}

//Multiply operand matrices
void Calculator::mult() {
    //Column size of first operand must equal row size of second operand
    if (matrix1.cols == matrix2.rows) {
        //Set pivot to where dimensions are equal
        int pivot = matrix1.cols;

        //Set dimensions of result matrix based on matrix multiplication rules
        result.setSize(matrix1.rows, matrix2.cols);

        int i, j, k, total = 0;

        //Loop by dimension
        for (i = 0; i < result.rows; i++) {
            for (j = 0; j < result.cols; j++) {
                //Loop by pivot. matrix1 loops by column. matrix2 loops by row (because they are equal)
                for (k = 0; k < pivot; k++) {
                    //Multiply corresponding pivot values and keep running total
                    total += matrix1.matrix[i][k] * matrix2.matrix[k][j];
                }
                //Set result matrix to total variable
                result.matrix[i][j] = total;
                //Reset total
                total = 0;
            }
        }

        //Print operand matrices
        printMatrix1();
        printMatrix2();
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
    result.setSize(matrix1.cols, matrix1.rows);

    //Loop by dimension
    for (i = 0; i < result.rows; i++) {
        for (j = 0; j < result.cols; j++) {
            //Set result matrix values to opposite of operand matrix values
            result.matrix[i][j] = matrix1.matrix[j][i];
        }
    }

    //Print first operand matrix
    printMatrix1();
    //Print result matrix
    printResult();
}
