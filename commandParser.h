#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "roomManip.h"
#include "inventory.h"
#include "fileIO.h"

void processCommand(const char *command, ROOM **current_room, LEVEL **current_level, INVENTORY *inventory);
#endif
