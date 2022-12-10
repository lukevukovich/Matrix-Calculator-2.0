#include <iostream>
#include <cctype>
#include <climits>
#include "Controller.h"

using namespace std;

//Print first operand matrix in formatted form
void Controller::printMatrix1() {
    int i, j;

    //Print header
    cout << "\n(" << operation <<  ") MATRIX 1:\n";

    //Loop by dimensions
    for (i = 0; i < matrix1.rows; i++) {
        cout << ("[");
        for (j = 0; j < matrix1.cols; j++) {
            //Print value
            cout << matrix1.matrix[i][j];
            //Print comma if needed
            if (j + 1 != matrix1.cols)
                cout << (", ");
        }
        cout << ("]\n");
    }
}

//Print second operand matrix in formatted form
void Controller::printMatrix2() {
    int i, j;

    //Print header
    cout << "\n(" << operation <<  ") MATRIX 2:\n";

    //Loop by dimensions
    for (i = 0; i < matrix2.rows; i++) {
        cout << ("[");
        for (j = 0; j < matrix2.cols; j++) {
            //Print value
            cout << matrix2.matrix[i][j];
            //Print comma if needed
            if (j + 1 != matrix2.cols)
                cout << (", ");
        }
        cout << ("]\n");
    }
}

//Print result matrix in formatted form
//Same process as other matrix print functions
void Controller::printResult() {
    int i, j;

    cout << "\n(" << operation << ") MATRIX RESULT:\n";

    for (i = 0; i < result.rows; i++) {
        cout << ("[");
        for (j = 0; j < result.cols; j++) {
            cout << result.matrix[i][j];
            if (j + 1 != result.cols)
                cout << (", ");
        }
        cout << ("]\n");
    }
}

//Get input for  first operand matrix
void Controller::inputMatrix1() {
    //Print header
    cout << "\n(" << operation << ") MATRIX 1 INPUT:\n";

    int r, c, temp;

    //Get row input
    cout << "Enter Matrix Rows (1-" << MAXDIM << "):";
    cin >> r;

    //Fully error check input
    //If row is smaller than 1 or bigger than set matrix size
    while (!cin.good() || r < 1 || r > MAXDIM) {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for a valid value
        cout << "Enter Matrix Rows (1-" << MAXDIM << "):";
        cin >> r;
    }

    //Get column input
    cout << "Enter Matrix Columns (1-" << MAXDIM << "):";
    cin >> c;

    //Fully error check input
    //If row is smaller than 1 or bigger than set matrix size
    while (!cin.good() || c < 1 || c > MAXDIM) {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for a valid value
        cout << "Enter Matrix Columns (1-" << MAXDIM << "):";
        cin >> c;
    }

    //Allocate matrix with dimensions
    matrix1.setSize(r, c);

    cout << ("\n");

    int i, j;

    //Loop by dimension input
    for (i = 0; i < matrix1.rows; i++) {
        for (j = 0; j < matrix1.cols; j++) {
            //Get individual matrix value input
            cout << "Enter Matrix[" << i << "][" << j << "] Value:";
            cin >> temp;

            //Fully error check input
            //If input is smaller or bigger than set max value
            while (!cin.good() || temp > MAXVAL || temp < -(MAXVAL)) {
                //Clear invalid value
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                //Keep trying for a valid value
                cout << "Enter Matrix[" << i << "][" << j << "] Value:";
                cin >> temp;
            }

            //Set matrix value to valid input value
            matrix1.matrix[i][j] = temp;
        }
    }
}

//Get input for a matrix. Set specific operand matrix values to input values
void Controller::inputMatrix2() {
    //Print header
    cout << "\n(" << operation << ") MATRIX 2 INPUT:\n";

    int r, c, temp;

    //Get row input
    cout << "Enter Matrix Rows (1-" << MAXDIM << "):";
    cin >> r;

    //Fully error check input
    //If row is smaller than 1 or bigger than set matrix size
    while (!cin.good() || r < 1 || r > MAXDIM) {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for a valid value
        cout << "Enter Matrix Rows (1-" << MAXDIM << "):";
        cin >> r;
    }

    //Get column input
    cout << "Enter Matrix Columns (1-" << MAXDIM << "):";
    cin >> c;

    //Fully error check input
    //If row is smaller than 1 or bigger than set matrix size
    while (!cin.good() || c < 1 || c > MAXDIM) {
        //Clear invalid value
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Keep trying for a valid value
        cout << "Enter Matrix Columns (1-" << MAXDIM << "):";
        cin >> c;
    }

    //Allocate matrix with dimensions
    matrix2.setSize(r, c);

    cout << ("\n");

    int i, j;

    //Loop by dimension input
    for (i = 0; i < matrix2.rows; i++) {
        for (j = 0; j < matrix2.cols; j++) {
            //Get individual matrix value input
            cout << "Enter Matrix[" << i << "][" << j << "] Value:";
            cin >> temp;

            //Fully error check input
            //If input is smaller or bigger than set max value
            while (!cin.good() || temp > MAXVAL || temp < -(MAXVAL)) {
                //Clear invalid value
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                //Keep trying for a valid value
                cout << "Enter Matrix[" << i << "][" << j << "] Value:";
                cin >> temp;
            }

            //Set matrix value to valid input value
            matrix2.matrix[i][j] = temp;
        }
    }
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