#include <stdio.h>
#include <st
int main() {
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
    return 0; 
	}
