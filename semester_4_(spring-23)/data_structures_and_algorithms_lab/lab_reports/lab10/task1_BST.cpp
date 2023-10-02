/*
Implement binary search tree with following operations
a) Creation
b) Insertion
c) Find minimum
d) Find Maximum
e) Delete Element
f) Post order traversal
g) Pre order traversal
h) In order traversal
i) Height of tree
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class BinarySearchTree
{
private:
    Node *root;

    // Helper functions:
    bool isValueUnique(int value, Node *currentTree)
    {
        if (currentTree == nullptr)
            return true;

        if (currentTree->data == value)
            return false;
        else if (value < currentTree->data)
            return isValueUnique(value, currentTree->left);
        else
            return isValueUnique(value, currentTree->right);
    }

    Node *insertNode(int value, Node *current)
    {
        if (current == nullptr)
        {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->left = newNode->right = nullptr;
            return newNode;
        }

        if (current->data < value)
            current->right = insertNode(value, current->right);
        else if (current->data > value)
            current->left = insertNode(value, current->left);

        return current;
    }

    void clearTree(Node *currentTree)
    {
        if (currentTree == nullptr)
            return;

        clearTree(currentTree->left);
        clearTree(currentTree->right);

        delete currentTree;
    }

    int calculateHeight(Node *tree)
    {
        if (tree == nullptr)
            return 0;

        int leftHeight = calculateHeight(tree->left);
        int rightHeight = calculateHeight(tree->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int findMinimumValue(Node *currentTree)
    {
        if (currentTree->left == nullptr)
            return currentTree->data;

        return findMinimumValue(currentTree->left);
    }

    int findMaximumValue(Node *currentTree)
    {
        if (currentTree->right == nullptr)
            return currentTree->data;

        return findMaximumValue(currentTree->right);
    }

    int findAndDeleteMinimum(Node *&currentTree)
    {
        if (currentTree->left == nullptr)
        {
            int minValue = currentTree->data;
            Node *temp = currentTree;
            currentTree = currentTree->right;
            delete temp;
            return minValue;
        }
        else
            return findAndDeleteMinimum(currentTree->left);
    }

    Node *deleteNodeWithValue(int value, Node *tree)
    {
        if (tree == nullptr) // If the current tree is empty
            return nullptr;

        if (value < tree->data) // Value is less than the current node's data, recursively call deleteNodeWithValue on the left subtree
            tree->left = deleteNodeWithValue(value, tree->left);
        else if (value > tree->data) // Value is greater than the current node's data, recursively call deleteNodeWithValue on the right subtree
            tree->right = deleteNodeWithValue(value, tree->right);
        else // Value is equal to the current node's data
        {
            if (tree->left == nullptr && tree->right == nullptr) // current node is a leaf node (no children)
            {
                delete tree;
                return nullptr;
            }
            else if (tree->left != nullptr && tree->right == nullptr) // current node has only one left child
            {
                Node *leftChild = tree->left;
                delete tree;
                return leftChild;
            }
            else if (tree->left == nullptr && tree->right != nullptr) // current node has only one right child
            {
                Node *rightChild = tree->right;
                delete tree;
                return rightChild;
            }
            else // current node has two children
            {
                tree->data = findAndDeleteMinimum(tree->right);
                // tree->data = findMinimumValue(tree->right);
                // tree->right = deleteNodeWithValue(tree->data, tree->right);
            }
        }

        return tree;
    }

    void preOrder(Node *tree)
    {
        if (tree == nullptr)
            return;
        cout << tree->data << " ";
        preOrder(tree->left);
        preOrder(tree->right);
        return;
    }

    void inOrder(Node *tree)
    {
        if (tree == nullptr)
            return;
        inOrder(tree->left);
        cout << tree->data << " ";
        inOrder(tree->right);
        return;
    }

    void postOrder(Node *tree)
    {
        if (tree == nullptr)
            return;
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data << " ";
        return;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTree(int value)
    {
        root = new Node;
        root->data = value;
        root->left = root->right = nullptr;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    bool isUnique(int value)
    {
        return isValueUnique(value, root);
    }

    void clear()
    {
        clearTree(root);
        root = nullptr;
    }

    void height()
    {
        cout << "Height: " << calculateHeight(root)<< endl;
    }

    void insert(int value)
    {
        root = insertNode(value, root);
    }

    int findMinimum()
    {
        return findMinimumValue(root);
    }

    int findMaximum()
    {
        return findMaximumValue(root);
    }

    void deleteNode(int value)
    {
        root = deleteNodeWithValue(value, root);
    }

    void preOrderTraverse()
    {
        // Pre-order traversal follows the order of "Root, Left, Right". It visits the root node before its children.
        cout << "Pre Order Traverse.\n\tBST Content: ";
        preOrder(root);
        cout << endl;
    }

    void inOrderTraverse()
    {
        // In-order traversal follows the order of "Left, Root, Right". It visits the nodes in ascending order when applied to a binary search tree (BST).
        cout << "In Order Traverse.\n\tBST Content: ";
        inOrder(root);
        cout << endl;
    }

    void postOrderTraverse()
    {
        // Post-order traversal follows the order of "Left, Right, Root". It visits the children of a node before visiting the node itself.
        cout << "Post Order Traverse.\n\tBST Content: ";
        postOrder(root);
        cout << endl;
    }

    Node *getRoot()
    {
        return root;
    }
    ~BinarySearchTree()
    {
        clear();
    }
};

// Driver program
int main()
{
    BinarySearchTree t(10), w;
    cout << "Is BST - w Empty? " << boolalpha << w.isEmpty() << endl;
    cout << "Is BST - t Empty? " << boolalpha << t.isEmpty() << endl;
    t.insert(12);
    t.insert(34);
    t.insert(60);
    t.insert(18);
    t.insert(33);
    t.insert(34);
    cout << "Is 100 unique in BST - t? " << boolalpha << t.isUnique(10) << endl;
    cout << "Is 12 unique in BST - t? " << boolalpha << t.isUnique(12) << endl;
    cout << "Is 756 unique in BST - t? " << boolalpha << t.isUnique(756) << endl;
    t.preOrderTraverse();
    t.inOrderTraverse();
    t.postOrderTraverse();
    t.height();
    t.deleteNode(60);
    t.height();
    cout << "The minimum value in BST - t is: " << t.findMinimum() << endl;
    cout << "The maximum value in BST - t is: " << t.findMaximum() << endl;

    t.clear();
    cout << "Is BST - t Empty after clearing ? " << boolalpha << t.isEmpty() << endl;
    cout << "Is 100 unique in BST - t after clearing? " << boolalpha << t.isUnique(10) << endl;

    return 0;
}