#include <iostream>
#include <cctype>
#include <unistd.h>
#include "Controller/Controller.h"

using namespace std;

int main() {
    //Keeps track of number of times program runs through while loop
    int programCount = 0;

    char o, c;
    bool quit = false, keepPrevData = false;

    Controller controller = Controller();

    while (!quit) {

        cout << ("\nMATRIX CALCULATOR:\n(+) Add\n(-) Subtract\n(*) Multiply\n(t) Transpose\n(x) Quit\n");

        //Get operation input
        o = controller.getOperationInput();
        controller.setOperation(o);

        //Only ask to keep previous data after first pass through
        if (programCount > 0 && tolower(controller.getOperation()) != 'x') {
            //Get input to keep previous data
            c = controller.getChoiceInput();
            controller.setChoice(c);

            if (controller.getChoice() == 'y')
                keepPrevData = true;
            else
                keepPrevData = false;
        }

        if (!keepPrevData) {
            //Set all matrix values to 0
            controller.resetAll();

            if (controller.getOperation() != 'x') {
                //Perform first matrix data input
                controller.operandInput(FIRST);

                if (controller.getOperation() != 't')
                    //Perform second matrix data input
                    controller.operandInput(SECOND);
            }
        }

        //Perform corresponding operation
        switch (controller.getOperation()) {
            case '+':
                controller.add();
                break;
            case '-':
                controller.sub();
                break;
            case '*':
                controller.mult();
                break;
            case 't':
            case 'T':
                controller.trans();
                break;
            case 'x':
            case 'X':
                //Quit and break if x is entered
                cout << ("\nQUIT CALCULATOR\n");
                quit = true;
                break;
        }

        programCount++;

    }

    sleep(1);
}
