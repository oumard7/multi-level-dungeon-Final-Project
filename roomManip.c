#include "roomManip.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a single room with a description
ROOM *createRoom(int id, const char *description) {
    ROOM *room = (ROOM *)malloc(sizeof(ROOM));
    room->id = id;
    room->description = strdup(description);
    room->n = room->e = room->s = room->w = NULL;
    room->is_portal = 0;
    room->visited = 0;
    room->has_loot = 0; // Initialize room with no loot
    return room;
}
//Generate 2D grid of rooms for a level 
LEVEL *createLevel(int level_number, int size) {
	LEVEL *level = (LEVEL *)malloc(sizeof(LEVEL));
	level->level_number = level_number;
	level->next = NULL;

	ROOM **grid = (ROOM **)malloc(size * size * sizeof(ROOM *));
	for (int row = 0; row < size; row++) {
    	for (int col = 0; col < size; col++) {
        	int id = row * size + col;
        	grid[id] = createRoom(id, "An empty room.");`

	if (rand() % 5 == 0) { // Which is about a 20% chance of loot
            	grid[id]->has_loot = 1; // 1 to mark the room as having loot
        	}

        	// Connect rooms in the grid
        	if (col > 0) {
            	grid[id]->w = grid[id - 1];
            	grid[id - 1]->e = grid[id];
        	}
        	if (row > 0) {
            	grid[id]->n = grid[id - size];
            	grid[id - size]->s = grid[id];
        	}
    		}
		 }

	// Add the portal in the last room of the level, until the last level
	if (level_number < 3) {
    	grid[size * size - 1]->description = strdup("This room has a portal to the next level.");
    	grid[size * size - 1]->is_portal = 1;
	}

	// Mark the final room of the last level as the end goal 
	if (level_number == 3) {
    	grid[size * size - 1]->description = strdup("This is the final room!. Hard work always pay off");
	}

	level->start_room = grid[0];
	free(grid);
	return level;
}
// show the available exits for the current room
void displayExits(ROOM *room) {
	printf("Available exits: ");
	if (room->n) printf("North ");
	if (room->e) printf("East ");
	if (room->s) printf("South ");
	if (room->w) printf("West ");
	printf("\n");
}

// Print the dungeon map for the current level
void printMap(LEVEL *level) {
	ROOM *row = level->start_room;

	printf(" Dungeon Map (Level %d) \n  ", level->level_number);

	// Traverse the grid row by row
	while (row) {
    	ROOM *col = row;
    	while (col) {
        printf("[%d] ", col->id);
        col = col->e;
    	}
    	printf("\n");
    	row = row->s;
	}
}



