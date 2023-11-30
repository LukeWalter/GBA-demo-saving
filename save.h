#ifndef SAVE_H
#define SAVE_H

#include "gba.h"

#define CARTRIDGE_RAM ((unsigned char*) 0x0E000000)

// Edit this struct to include the data you want to save
typedef struct {
    unsigned char newGame; // Make sure this is included in your save data struct!!
    
} SAVE_DATA;

extern SAVE_DATA saveData;

int loadGame();
void saveGame();

#endif