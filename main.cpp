#include <iostream>
#include <cctype>
#include <unistd.h>
#include "Controller/Controller.h"
#include "Calculator/Calculator.h"

using namespace std;

/*
 * Matrix Calculator 2.0 so far adds:
 * -OOP
 * -Input error checking
 * -Choice to keep previous matrix data
 */

int main() {
    //Keeps track of number of times program runs through while loop
    int programCount = 0;

    //Operation and choice variables
    char o, c;

    bool quit = false, keepPrevData = false;

    //Calculator object that controls entire program
    Calculator calculator = Calculator();

    while (!quit) {

        cout << ("\nMATRIX CALCULATOR:\n(+) Add\n(-) Subtract\n(*) Multiply\n(t) Transpose\n(x) Quit\n");

        //Get operation input
        o = calculator.operationInput();
        calculator.setOperation(o);

        //Only ask to keep previous data after first pass through
        if (programCount > 0 && tolower(calculator.getOperation()) != 'x') {
            //Get input to keep previous data
            c = calculator.choiceInput();
            calculator.setChoice(c);

            //If yes, set boolean value
            if (calculator.getChoice() == 'y')
                keepPrevData = true;
            else
                keepPrevData = false;
        }

        //If user does not opt to keep prev data
        if (!keepPrevData) {
            //Set all matrix values to 0
            calculator.resetAll();

            if (calculator.getOperation() != 'x') {
                //Perform first matrix data input
                calculator.operandInput(FIRST);

                if (calculator.getOperation() != 't')
                    //Perform second matrix data input
                    calculator.operandInput(SECOND);
            }
        }

        //Perform corresponding operation
        switch (calculator.getOperation()) {
            case '+':
                calculator.add();
                break;
            case '-':
                calculator.sub();
                break;
            case '*':
                calculator.mult();
                break;
            case 't':
            case 'T':
                calculator.trans();
                break;
            case 'x':
            case 'X':
                //Exit loop if x is entered
                cout << ("\nQUIT CALCULATOR\n");
                quit = true;
                break;
        }

        //Add to program counter
        programCount++;

    }

    sleep(1);
}
