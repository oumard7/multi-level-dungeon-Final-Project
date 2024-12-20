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

    	
    	// Determine the next room based on the direction
    	switch (direction) {
        	case 'n':
            	next_room = (*current_room)->n;
            	break;
        	case 'e':
            	next_room = (*current_room)->e;
            	break;
        	case 's':
            	next_room = (*current_room)->s;
            	break;
        	case 'w':
            	next_room = (*current_room)->w;
            	break;   
        	default:
            	printf("Invalid. Use move n, move e, move s, or move w.\n");
            	return;
    	}

    	// Check if the movement is valid
    	if (next_room)
 		{
        	*current_room = next_room; // Update the pointer
        	printf("Moving to a new room...\n");

	// Check if the room has loot
        	if ((*current_room)->visited == 0 && (*current_room)->has_loot == 1)
		 { 
            	addItem(inventory, "Key");
            	printf("You found a Key!\n");
            	(*current_room)->has_loot = 0; // Mark loot as collected
        	}

        	// Check if the room is a portal
        	if ((*current_room)->is_portal) {
            	printf("Ohh. You entered the portal to the next level...\n");

		*current_level = (*current_level)->next; // Move to the next level
            	*current_room = (*current_level)->start_room;
        	}

        	// Check if the room is the final room in the last level (level 3) and room 24)
		if ((*current_level)->level_number == 3 && (*current_room)->id == 24) {
            	printf("You found the treasure! Good job! \n"); //display the congrats to the user 
            	exit(0); // End the game
        	}






