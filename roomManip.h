#ifndef ROOM_MANIP_H
#define ROOM_MANIP_H

// Define the ROOM structure
typedef struct ROOM {
    int id;
    struct ROOM *n, *e, *s, *w;
    char *description; // Room description 
    int has_loot;      // 1 if the room contains loot, 0 otherwise
    int visited;       // 1 if the room has been visited, 0 otherwise
    int is_portal;     // 1 if the room is a portal, 0 otherwise
} ROOM;


// Define the LEVEL structure
typedef struct LEVEL {
    int level_number;              
    ROOM *start_room;           
    struct LEVEL *next;         
} LEVEL;

// Function declarations
ROOM *createRoom(int id, const char *description);
LEVEL *createLevel(int level_number, int size);
void displayExits(ROOM *room);
void printMap(LEVEL *level);
void freeDungeon(LEVEL *head);

#endif

