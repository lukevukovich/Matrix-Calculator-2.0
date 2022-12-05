#include <iostream>
#include <cctype>
#include <climits>
#include "Controller.h"

using namespace std;

//Set specific operand matrix values
//Takes in matrix/dimension values & which operand matrix to set
void Controller::setOperand(int m[][MATRIX], int d[], MATRIX_ENUM matrix) {
    int i, j;

    //If first operand matrix
    if (matrix == FIRST) {
        //Set dimension attribute
        d1[0] = d[0];
        d1[1] = d[1];
        //Loop by dimensions
        for (i = 0; i < d1[0]; i++) {
            for (j = 0; j < d1[1]; j++)
                //Set values of matrix attribute
                matrix1[i][j] = m[i][j];
        }
    }

    //If second operand matrix
    else if (matrix == SECOND) {
        d2[0] = d[0];
        d2[1] = d[1];
        for (i = 0; i < d2[0]; i++) {
            for (j = 0; j < d2[1]; j++)
                matrix2[i][j] = m[i][j];
        }
    }
}

//Reset values & dimensions of all three matrices
void Controller::resetAll() {
    int i, j;

    for (i = 0; i < MATRIX; i++) {
        for (j = 0; j < MATRIX; j++) {
            matrix1[i][j] = 0;
            matrix2[i][j] = 0;
            matrix3[i][j] = 0;
        }
    }

    for (i = 0; i < DIM; i++) {
        d1[i] = 0;
        d2[i] = 0;
        d3[i] = 0;
    }
}

//Print specific operand matrix in formatted form
void Controller::printOperand(MATRIX_ENUM matrix) {
    int i, j;

    //Print header
    cout << "\n(" << operation <<  ") MATRIX " << matrix + 1 << ":\n";

    //If first operand matrix
    if (matrix == FIRST) {
        //Loop by dimensions
        for (i = 0; i < d1[0]; i++) {
            cout << ("[");
            for (j = 0; j < d1[1]; j++) {
                //Print value
                cout << matrix1[i][j];
                //Print comma if needed
                if (j + 1 != d1[1])
                    cout << (", ");
            }
            cout << ("]\n");
        }
    }
    //If second operand matrix
    else if (matrix == SECOND) {
        for (i = 0; i < d2[0]; i++) {
            cout << ("[");
            for (j = 0; j < d2[1]; j++) {
                cout << matrix2[i][j];
                if (j + 1 != d2[1])
                    cout << (", ");
            }
            cout << ("]\n");
        }
    }
}

//Print result matrix
//Same process as printOperand function
void Controller::printResult() {
    int i, j;

    cout << "\n(" << operation << ") MATRIX RESULT:\n";

    for (i = 0; i < d3[0]; i++) {
        cout << ("[");
        for (j = 0; j < d3[1]; j++) {
            cout << matrix3[i][j];
            if (j + 1 != d3[1])
                cout << (", ");
        }
        cout << ("]\n");
    }
}

//Get input for a matrix. Set specific operand matrix values to input values
void Controller::operandInput(MATRIX_ENUM matrix) {
    //Print header
    cout << "\n(" << operation << ") MATRIX " << matrix + 1 <<" INPUT:\n";

    //Create matrix & dimensions for input
    int m[MATRIX][MATRIX];
    int d[DIM];

    //Get row input
    cout << "Enter Matrix Rows (1-" << MATRIX << "):";
    cin >> d[0];

    //Fully error check input
    //If row is smaller than 1 or bigger than set matrix size
    while (!cin.good() || d[0] < 1 || d[0] > 10) {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for a valid value
        cout << "Enter Matrix Rows (1-" << MATRIX << "):";
        cin >> d[0];
    }

    //Get column input
    cout << "Enter Matrix Columns (1-" << MATRIX << "):";
    cin >> d[1];

    //Fully error check input
    //If row is smaller than 1 or bigger than set matrix size
    while (!cin.good() || d[1] < 1 || d[1] > 10) {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for a valid value
        cout << "Enter Matrix Columns (1-" << MATRIX << "):";
        cin >> d[1];
    }

    cout << ("\n");

    int i, j;

    //Loop by dimension input
    for (i = 0; i < d[0]; i++) {
        for (j = 0; j < d[1]; j++) {
            //Get individual matrix value input
            cout << "Enter Matrix[" << i << "][" << j << "] Value:";
            cin >> m[i][j];

            //Fully error check input
            //If input is smaller or bigger than set max value
            while (!cin.good() || m[i][j] > MAXVAL || m[i][j] < -(MAXVAL)) {
                //Clear invalid value
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                //Keep trying for a valid value
                cout << "Enter Matrix[" << i << "][" << j << "] Value:";
                cin >> m[i][j];
            }
        }
    }

    //Set all input values to an operand matrix
    setOperand(m, d, matrix);
}

//Operation attribute getter and setter
void Controller::setOperation(char o) {
    operation = (char) tolower(o);
}

char Controller::getOperation() {
    return (char) tolower(operation);
}

//Get user input for operation
//Returns input value
char Controller::operationInput() {
    char o;

    //Get operation input
    cout << ("ENTER OPERATION:");
    cin >> o;

    //If value is not an operation or is not quit
    while (o != '+' && o != '-' &&
            o != '*' && tolower(o) != 't' && tolower(o) != 'x') {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for valid value
        cout << ("ENTER OPERATION:");
        cin >> o;
    }

    return o;
}

//Choice attribute getter and setter
void Controller::setChoice(char c) {
    choice = (char) tolower(c);
}

char Controller::getChoice() {
    return (char) tolower(choice);
}

//Get user input for choice
//Returns input value
char Controller::choiceInput() {
    char c;

    //Get choice input
    cout << ("KEEP PREVIOUS DATA? (y/n):");
    cin >> c;

    //If value is not y/n or is not quit
    while (tolower(c) != 'y' && tolower(c) != 'n') {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for valid value
        cout << ("KEEP PREVIOUS DATA? (y/n):");
        cin >> c;
    }

    return c;
}