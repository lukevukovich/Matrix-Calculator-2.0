#include "Matrix.h"
#include <iostream>

//Constructor
Matrix::Matrix() {
    //Allocate matrix to max dimensions
    matrix = alloc(MAXDIM, MAXDIM);
    //Set all values to 0
    resetMatrix();
}

//Deconstructor
Matrix::~Matrix() {
    //Deallocate and delete matrix
    dealloc();
}

//Set all matrix values to 0
void Matrix::resetMatrix() {
    int i, j;

    //Loop through matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            matrix[i][j] = 0;
    }
}

//Allocate and create matrix
int ** Matrix::alloc(int r, int c) {
    int i;

    //Set attributes
    rows = r;
    cols = c;

    //Create double pointer with proper dimensions
    int ** new_matrix = new int *[rows];
    for (i = 0; i < rows; i++) {
        new_matrix[i] = new int[cols];
    }

    //Return created matrix
    return new_matrix;
}

//Deallocate and delete matrix
void Matrix::dealloc() {
    int i;

    //Loop through rows and delete each row's pointer
    for (i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    //delete entire matrix
    delete [] matrix;
}

//Set matrix size
void Matrix::setSize(int r, int c) {
    //If dimensions are greater than 0
    if (r > 0 && c > 0) {
        //Set dimensions
        rows = r;
        cols = c;

        //Deallocate and delete matrix
        dealloc();
        //Allocate matrix with new dimensions
        matrix = alloc(rows, cols);
        //Set all values to 0
        resetMatrix();
    }
}

//Get matrix
int * Matrix::getMatrix() {
    //Return pointer to location [0][0]
    int * start = matrix[0];

    return start;
}
