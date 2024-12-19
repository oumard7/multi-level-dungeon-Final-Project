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
        	grid[id] = createRoom(id, "An empty room.");


