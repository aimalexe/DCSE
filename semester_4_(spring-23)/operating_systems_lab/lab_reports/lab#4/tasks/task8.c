/*
Task 8: Write a complete menu driven program to do the following:

	Build a linked list to save a list of names. Name will not exceed 50 characters.
	Write a function add to append a new name to the list.  The function prototype is given as
 	void add (list *head, char *newname);
	Write a function search to look for a given name in the list.  If that name is found in list then the function
    should return true, otherwise, return false.
Write a main method to test your two functions

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50

typedef struct node {
    char name[MAX_NAME_LENGTH];
    struct node *next;
} node;

typedef struct list {
    node *head;
    int size;
} list;

void init_list(list *l) {
    l->head = NULL;
    l->size = 0;
}

void add(list *l, char *newname) {
    node *temp = (node*) malloc(sizeof(node));
    strncpy(temp->name, newname, MAX_NAME_LENGTH);
    temp->next = l->head;
    l->head = temp;
    l->size++;
}

bool search(list *l, char *searchname) {
    node *temp = l->head;
    while (temp != NULL) {
        if (strncmp(temp->name, searchname, MAX_NAME_LENGTH) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    list l;
    init_list(&l);
    int choice;
    char name[MAX_NAME_LENGTH];

    while (true) {
        printf("1. Add name to list\n");
        printf("2. Search name in list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name to add: ");
                scanf("%s", name);
                add(&l, name);
                printf("Name added to the list!\n");
                break;
            case 2:
                printf("Enter the name to search: ");
                scanf("%s", name);
                if (search(&l, name))
                    printf("Name found in the list!\n");
                else
                    printf("Name not found in the list!\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
