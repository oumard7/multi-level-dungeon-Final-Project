#include <stdio.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "stringManip.h"
#include "commandParser.h"
#include "inventory.h"
#include "roomManip.h"
int main() {
	srand(time(NULL)); // to generate random number
	int level_count = 3, level_size = 5; // Dungeon dimensions
	LEVEL *dungeon = NULL;    
	INVENTORY *inventory = createInventory(5); // Initialize inventory
	// Create multiple dungeon levels
	LEVEL *last_level = NULL;
	for (int i = 1; i <= level_count; i++) { // imcremnt from from Level 1
    	LEVEL *new_level = createLevel(i, level_size);
    	if (!dungeon) {
        	dungeon = new_level; // Set the first level
    	} else {
        	last_level->next = new_level; // Link the last level to the new one so i can travel through the different levels
    	}
    	last_level = new_level; // Update the last level pointer
	}

	LEVEL *current_level = dungeon;         	// Start at Level 1 and first room
	ROOM *current_room = current_level->start_room; 

	    printf("Welcome to the Multi-Level Dungeon Explorer!\n");
	char command[36];
		while (1) {
    		printf("\nYou are in Room [%d]\n", current_room->id);
    		displayExits(current_room); // Display exits
	    	printf("Enter a command:");
	    	fgets(command, sizeof(command), stdn);
	    	trim(command); // Trim the whitespace from input

		if (strcmp(command, "quit") == 0) {
        	printf("Exiting the game. Goodbye!\n")
        	break;
    	}

    	processCommand(command, &current_room, inventory);
	}
	





	// Free allocated memory
	freeDungeon(dungeon);
	freeInventory(inventory);
    return 0; 
	}
