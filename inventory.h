#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct {
    char **items;
    int item_count   //stuff in the inventory 
    int capacity; //The capacity of my inventory
} INVENTORy

INVENTORY *createInventory(int capacity)  // Create a new inventory
void addItem(INVENTORY *inventory, const char *item)  // Add an item to the inventory
void displayInventory(INVNTORY *inventory);  // Print the items in the inventory
void freeInventory(INVENTORY *inventory); // Then free the memory allocation





#endif
