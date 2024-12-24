#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create inventory 
INVENTORY *createInventory(int capacity) {
    INVENTORY *inventory = (INVENTORY *)malloc(sizeof(INVENTORY));
    inventory->items = (char **)malloc(capacity * sizeof(char *));
    inventory->item_count = 0;
    inventory->capacity = capacity;
    return inventory;
}

// Add an item to the inventory
void addItem(INVENTORY *inventory, const char *item) {
    if (inventory->item_count == inventory->capacity) {
        inventory->capacity *= 2;
        inventory->items = (char **)realloc(inventory->items, inventory->capacity * sizeof(char *));
    }
    inventory->items[inventory->item_count++] = strdup(item);
}

// Display the inventory items
void displayInventory(INVENTORY *inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->item_count; i++) {
        printf("- %s\n", inventory->items[i]);
    }
}

// Free inventory memory
void freeInventory(INVENTORY *inventory) {
    for (int i = 0; i < inventory->item_count; i++) {
        free(inventory->items[i]);
    }
    free(inventory->items);
    free(inventory);
}
