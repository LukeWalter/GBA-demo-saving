#include "gba.h"
#include "print.h"

#include "save.h"

u16 oldButtons;
u16 buttons;

int aPresses;
int bPresses;

void initialize();
void update();

int main() {

    initialize();

    while (1) {

        oldButtons = buttons;
        buttons = REG_BUTTONS;

        update();
        waitForVBlank();

    } // while

    return 0;

} // main

void initialize() {

    oldButtons = 0;
    buttons = REG_BUTTONS;

    // Initialize save data here

    aPresses = 0;
    bPresses = 0;
    
    mgba_open();
    mgba_printf("Press A and B to increase the counters!");
    mgba_printf("Press START to save the counters!");
    mgba_printf("Starting values: A(%d) B(%d)", aPresses, bPresses);

} // initialize

void update() {

    if (BUTTON_PRESSED(BUTTON_A)) {
        mgba_printf("A presses: %d", ++aPresses);

    } // if

    if (BUTTON_PRESSED(BUTTON_B)) {
        mgba_printf("B presses: %d", ++bPresses);

    } // if

    if (BUTTON_PRESSED(BUTTON_START)) {
        // saveGame();
        mgba_printf("Game Saved! A(%d) B(%d)", aPresses, bPresses);

    } // if

} // update