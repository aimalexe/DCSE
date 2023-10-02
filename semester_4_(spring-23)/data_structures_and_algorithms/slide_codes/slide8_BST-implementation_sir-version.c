#include <stdio.h>
#include <stdlib.h> //For malloc function
#include <math.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct
{
    int number;
    char *string;
} ELEMENT_TYPE;

typedef struct node *NODE_TYPE;

typedef struct node
{
    ELEMENT_TYPE element;
    NODE_TYPE left, right;
} NODE;

typedef NODE_TYPE BST_TYPE;
typedef NODE_TYPE WINDOW_TYPE;

/*** error handler: print message passed as argument and
take appropriate action ***/
int error(char *s)
{
    printf("Error: %s\n", s);
    exit(0);
}

/*** insert an element in a BST ***/
BST_TYPE *insert(ELEMENT_TYPE e, BST_TYPE *tree)
{
    WINDOW_TYPE temp;
    if (*tree == NULL)
    {
        /* we are at an external node: create a new node */
        /* and insert it */
        if ((temp = (NODE_TYPE)malloc(sizeof(NODE))) == NULL)
            error("insert: unable to allocate memory");
        else
        {
            temp->element = e;
            temp->left = NULL;
            temp->right = NULL;
            *tree = temp;
        }
    }
    else if (e.number < (*tree)->element.number)
    {
        /* assume number field is the key */
        insert(e, &((*tree)->left));
    }
    else if (e.number > (*tree)->element.number)
    {
        insert(e, &((*tree)->right));
    }

    /* if e.number == (*tree)->element.number, e is */
    /* already in the tree so do nothing */

    return (tree);
}

/*** return and delete the smallest node in a tree ***/
/*** i.e. return and delete the left-most node ***/
ELEMENT_TYPE delete_min(BST_TYPE *tree)
{
    ELEMENT_TYPE e;
    BST_TYPE p;
    if ((*tree)->left == NULL)
    {
        /* (*tree) points to the smallest element */
        e = (*tree)->element;
        /* replace the node pointed to by tree */
        /* by its right child */
        p = *tree;
        *tree = (*tree)->right;
        free(p);
        return (e);
    }
    else
    {
        /* the node pointed to by *tree has a left child */
        return (delete_min(&((*tree)->left)));
    }
}

/*** delete an element from a BST ***/
BST_TYPE *delete(ELEMENT_TYPE e, BST_TYPE *tree)
{
    BST_TYPE p;
    if (*tree != NULL)
    {
        if (e.number < (*tree)->element.number)
            delete (e, &((*tree)->left));
        else if (e.number > (*tree)->element.number)
            delete (e, &((*tree)->right));
        else if (((*tree)->left == NULL) && ((*tree)->right == NULL))
        {
            /* leaf node containing e: delete it */
            p = *tree;
            free(p);
            *tree = NULL;
        }
        else if ((*tree)->left == NULL)
        {
            /* internal node containing e and it has only */
            /* a right child; delete it and make tree */
            /* point to the right child */
            p = *tree;
            *tree = (*tree)->right;
            free(p);
        }
        else if ((*tree)->right == NULL)
        {
            /* internal node containing e and it has only */
            /* a left child; delete it and make tree */
            /* point to the left child */
            p = *tree;
            *tree = (*tree)->left;
            free(p);
        }
        else
        {
            /* internal node containing e and it has both */
            /* left and right children; replace it with */
            /* the leftmost node of the right child */
            (*tree)->element = delete_min(&((*tree)->right));
        }
    }
    return tree;
}

/*** inorder traversal of a tree, ***/
/*** printing node elements ***/
/*** parameter n is the current level in the tree ***/
int inorder(BST_TYPE *tree, int n)
{
    int i;
    if (*tree != NULL)
    {
        inorder(&((*tree)->left), n + 2);
        for (i = 0; i < n; i++)
            printf(" ");
        printf("%d %s\n", (*tree)->element.number, (*tree)->element.string);
        inorder(&((*tree)->right), n + 2);
    }
    return TRUE;
}

/*** print all elements in a tree by traversing ***/
/*** inorder ***/
int print(BST_TYPE *tree)
{
    printf("Contents of tree by inorder traversal: \n");
    inorder(tree, 0);
    printf("-----------");
    return 0;
}

/*** assign values to an element ***/
int assign_element_values(ELEMENT_TYPE *e, int number, char s[])
{
    e->string = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(e->string, s);
    e->number = number;
    return 0;
}

int main()
{
    /*** main driver routine ***/
    ELEMENT_TYPE e;
    BST_TYPE tree = NULL;

    print(&tree);

    assign_element_values(&e, 3, "...");
    insert(e, &tree);
    print(&tree);

    assign_element_values(&e, 1, "++ +");
    insert(e, &tree);
    print(&tree);

    assign_element_values(&e, 5, "-- -");
    insert(e, &tree);
    print(&tree);

    assign_element_values(&e, 2, ", , , ");
    insert(e, &tree);
    print(&tree);

    assign_element_values(&e, 4, "* **");
    insert(e, &tree);
    print(&tree);

    assign_element_values(&e, 6, "000");
    insert(e, &tree);
    print(&tree);

    assign_element_values(&e, 3, "...");
    insert(e, &tree);
    print(&tree);

    return 0;
}

// Debugged with ❤ by Aimal Khan.