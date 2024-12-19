#ifndef FILE_IO_H
#define FILE_IO_H

#include "roomManip.h"
#include "inventory.h"

void saveGame(LEVEL *level, INVENTORY *inventory, const char *filename);
void loadGame(LEVEL **level, INVENTORY **inventory, const char *filename);

#endif
