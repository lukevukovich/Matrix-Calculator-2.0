#ifndef MATRIXCALCULATOR2_0_MATRIX_H
#define MATRIXCALCULATOR2_0_MATRIX_H

//Max number of rows/columns
#define MAXDIM 10

class Matrix {

public:
    //Matrix
    int ** matrix;
    //Dimensions
    int rows, cols;

    //Constructor and Destructor
    Matrix();
    ~Matrix();

    //Reset all matrix values to 0
    void resetMatrix();

    //Allocate matrix, takes in dimensions
    int ** alloc(int, int);
    //Deallocate matrix
    void dealloc();

    //Allocate matrix with new dimensions
    void setSize(int, int);
    //Returns pointer to matrix at [0][0]
    int * getMatrix();

};

#endif //MATRIXCALCULATOR2_0_MATRIX_H
