#include <iostream>
#include <cctype>
#include "Controller.h"

using namespace std;

void Controller::setOperand(int m[][MATRIX], int d[], MATRIX_ENUM matrix) {
    int i, j;

    if (matrix == FIRST) {
        d1[0] = d[0];
        d1[1] = d[1];
        for (i = 0; i < d1[0]; i++) {
            for (j = 0; j < d1[1]; j++)
                matrix1[i][j] = m[i][j];
        }
    }

    else if (matrix == SECOND) {
        d2[0] = d[0];
        d2[1] = d[1];
        for (i = 0; i < d2[0]; i++) {
            for (j = 0; j < d2[1]; j++)
                matrix2[i][j] = m[i][j];
        }
    }
}

void Controller::resetAll() {
    int i, j;

    for (i = 0; i < MATRIX; i++) {
        for (j = 0; j < MATRIX; j++) {
            matrix1[i][j] = 0;
            matrix2[i][j] = 0;
            matrix3[i][j] = 0;
        }
    }

    for (i = 0; i < 2; i++) {
        d1[i] = 0;
        d2[i] = 0;
        d3[i] = 0;
    }
}

void Controller::printOperand(MATRIX_ENUM matrix) {
    int i, j;

    cout << "\n(" << operation <<  ") MATRIX " << matrix << ":\n";

    if (matrix == FIRST) {
        for (i = 0; i < d1[0]; i++) {
            cout << ("[");
            for (j = 0; j < d1[1]; j++) {
                cout << matrix1[i][j];
                if (j + 1 != d1[1])
                    cout << (", ");
            }
            cout << ("]\n");
        }
    }
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

void Controller::operandInput(MATRIX_ENUM matrix) {
    cout << "\n(" << operation << ") MATRIX " << matrix <<" INPUT:\n";

    int m[MATRIX][MATRIX];
    int d[DIM];

    cout << "Enter Matrix Rows (1-" << MATRIX << "):";
    cin >> d[0];

    while (d[0] < 1 || d[0] > 10) {
        cout << "Enter Matrix Rows (1-" << MATRIX << "):";
        cin >> d[0];
    }

    cout << "Enter Matrix Columns (1-" << MATRIX << "):";
    cin >> d[1];
    while (d[1] < 1 || d[1] > 10) {
        cout << "Enter Matrix Columns (1-" << MATRIX << "):";
        cin >> d[1];
    }

    cout << ("\n");

    int i, j;

    for (i = 0; i < d[0]; i++) {
        for (j = 0; j < d[1]; j++) {
            cout << "Enter Matrix[" << i << "][" << j << "] Value:";
            cin >> m[i][j];

            while (m[i][j] > MAXVAL || m[i][j] < -(MAXVAL)) {
                cout << "Enter Matrix[" << i << "][" << j << "] Value:";
                cin >> m[i][j];
            }
        }
    }

    setOperand(m, d, matrix);
}

void Controller::setOperation(char o) {
    operation = (char) tolower(o);
}

char Controller::getOperation() {
    return (char) tolower(operation);
}

char Controller::getOperationInput() {
    char o;
    cout << ("ENTER OPERATION:");
    cin >> o;

    while (o != '+' && o != '-' &&
            o != '*' && tolower(o) != 't' && tolower(o) != 'x') {
        cout << ("ENTER OPERATION:");
        cin >> o;
    }

    return o;
}

void Controller::setChoice(char c) {
    choice = (char) tolower(c);
}

char Controller::getChoice() {
    return (char) tolower(choice);
}

char Controller::getChoiceInput() {
    char c;
    cout << ("KEEP PREVIOUS DATA? (y/n):");
    cin >> c;

    while (tolower(c) != 'y' && tolower(c) != 'n') {
        cout << ("KEEP PREVIOUS DATA? (y/n):");
        cin >> c;
    }

    return c;
}

void Controller::add() {
    int i, j;

    if (d1[0] == d2[0] && d1[1] == d2[1]) {

        d3[0] = d1[0];
        d3[1] = d1[1];

        for (i = 0; i < d3[0]; i++) {
            for (j = 0; j < d3[1]; j++) {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        printOperand(FIRST);
        printOperand(SECOND);
        printResult();
    }
    else
        cout << ("\nINOPERABLE MATRIX DIMENSIONS\n");

}

void Controller::sub() {
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

void Controller::mult() {
    if (d1[1] == d2[0]) {
        int pivot = d1[1];
        d3[0] = d1[0];
        d3[1] = d2[1];

        int i, j, k, tot = 0;

        for (i = 0; i < d3[0]; i++) {
            for (j = 0; j < d3[1]; j++) {
                for (k = 0; k < pivot; k++) {
                    tot += matrix1[i][k] * matrix2[k][j];
                }
                matrix3[i][j] = tot;
                tot = 0;
            }
        }

        printOperand(FIRST);
        printOperand(SECOND);
        printResult();
    }
    else
        cout << ("\nINOPERABLE MATRIX DIMENSIONS\n");

}

void Controller::trans() {
    int i, j;

    d3[0] = d1[1];
    d3[1] = d1[0];

    for (i = 0; i < d3[0]; i++) {
        for (j = 0; j < d3[1]; j++) {
            matrix3[i][j] = matrix1[j][i];
        }
    }
    printOperand(FIRST);
    printResult();
}