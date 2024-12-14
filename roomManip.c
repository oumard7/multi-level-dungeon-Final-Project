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

