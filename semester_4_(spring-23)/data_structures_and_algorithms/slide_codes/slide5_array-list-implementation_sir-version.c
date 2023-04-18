//Debugged by: Aimal Khan

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define FALSE 0
#define TRUE 1

typedef struct {
    int number;
    char *string;
} ELEMENT_TYPE;

typedef struct {
    int last;
    ELEMENT_TYPE a[MAX_LIST_SIZE];
} LIST_TYPE;

typedef int WINDOW_TYPE;

/** position following last element in a list **/
WINDOW_TYPE end(LIST_TYPE *list) {
    return(list->last+1);
}

/*** error handler: print message passed as argument and take appropriate action ***/
int error(char *s){
    printf("Error: %s\n", s);
    exit(0);
}

/*** empty a list ***/
WINDOW_TYPE empty(LIST_TYPE *list) {
    list->last = -1;
    return(end(list));
}

/*** test to see if a list is empty ***/
int is_empty(LIST_TYPE *list) {
    if (list->last == -1)
        return(TRUE);
    else
        return(FALSE);
}

/*** position at first element in a list ***/
WINDOW_TYPE first(LIST_TYPE *list) {
    if (is_empty(list) == FALSE)
        return(0);
    else 
        return(end(list));
}

/*** position at last element in a list ***/
WINDOW_TYPE last(LIST_TYPE *list) {
    return(list->last);
}

/*** position at next element in a list ***/
WINDOW_TYPE next(WINDOW_TYPE w, LIST_TYPE *list) {
    if (w == last(list))
        return(end(list));
    else if (w == end(list))
        error("can’t find next after end of list");
    else
        return(w+1);
}

/*** position at previous element in a list ***/
WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list) {
    if (w != first(list))
        return(w-1);
    else{
        error("can’t find previous before first element of list");
        return(w);
    }
}

/*** insert an element in a list ***/
LIST_TYPE *insert(ELEMENT_TYPE e, WINDOW_TYPE w, LIST_TYPE *list) {
    int i;
    if (list->last >= MAX_LIST_SIZE-1) {
        error("Can’t insert - list is full");
    } 
    else if ((w > list->last + 1) || (w < 0)) {
        error("Position does not exist");
    }
    else {
            /* insert it … shift all after w to the right */
        for (i=list->last; i>= w; i--) {
            list->a[i+1] = list->a[i];
        }
        list->a[w] = e;
        list->last = list->last + 1;
        return(list);
    }
}

/*** delete an element from a list ***/
LIST_TYPE *delete(WINDOW_TYPE w, LIST_TYPE *list) {
    int i;
    if ((w > list->last) || (w < 0)) {
        error("Position does not exist");
    }
    else {
    /* delete it … shift all after w to the left */
        list->last = list->last - 1;
        for (i=w; i <= list->last; i++) {
            list->a[i] = list->a[i+1];
        }
        return(list); 
    }
}

/*** retrieve an element from a list ***/
ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list) {
    if ( (w < 0) || (w > list->last)) {
    /* list is empty */
        error("Position does not exist");
    }
    else {
        return(list->a[w]);
    }
}

/*** print all elements in a list ***/
int print(LIST_TYPE *list) {
    WINDOW_TYPE w; 
    ELEMENT_TYPE e;
    printf("Contents of list: \n");
    w = first(list);
    while (w != end(list)) {
        e = retrieve(w, list);
        printf("%d %s\n", e.number, e.string);
        w = next(w, list);
    }
    printf("---\n");
    return(0);
}

/*** assign values to an element ***/
int assign_element_values(ELEMENT_TYPE *e, int number, char s[]) {
    e->string = (char *) malloc(sizeof(char)* strlen(s+1));
    strcpy(e->string, s);
    e->number = number;
}


int main(){
    /*** main driver routine ***/
    WINDOW_TYPE w;
    ELEMENT_TYPE e;
    LIST_TYPE list; 
    int i;

    empty(&list);
    print(&list);

    assign_element_values(&e, 1, "String A");
    w = first(&list);
    insert(e, w, &list);
    print(&list);

    assign_element_values(&e, 2, "String B");
    insert(e, w, &list);
    print(&list);

    assign_element_values(&e, 3, "String C");
    insert(e, last(&list), &list);
    print(&list);

    assign_element_values(&e, 4, "String D");
    w = next(last(&list), &list);
    insert(e, w, &list);
    print(&list);

    w = previous(w, &list);
    delete(w, &list);
    print(&list);

    return 0;
}