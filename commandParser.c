#include "commandParser.h"
#include "roomManip.h"
#include "inventory.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// process user commands
void processCommand(const char *command, ROOM **current_room, LEVEL **current_level, INVENTORY *inventory) {
	if (strncmp(command, "move", 4) == 0) {
    	char direction = command[5]; // Take direction from the command
    	ROOM *next_room = NULL;

    


