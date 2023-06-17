#include <iostream>
#include <string>

using namespace std;

struct BSTNode
{
    int data;
    string str;
    BSTNode *leftNode;
    BSTNode *rightNode;

    // Constructor
    BSTNode(int val, const string &s) : data(val), str(s), leftNode(nullptr), rightNode(nullptr) {}
};

class BST
{
private:
    BSTNode *root;

    // Helper function for inorder traversal
    void inorderTraversal(BSTNode *node, int n)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->leftNode, n + 1);
            for (int i = 0; i < n; i++)
                cout << " ";
            cout << node->data << " " << node->str << endl;
            inorderTraversal(node->rightNode, n + 1);
        }
    }

    // Helper function for inserting a node into the BST
    BSTNode *insertNode(BSTNode *node, int val, const string &s)
    {
        if (node == nullptr)
            return new BSTNode(val, s);
        else if (val < node->data)
            node->leftNode = insertNode(node->leftNode, val, s);
        else if (val > node->data)
            node->rightNode = insertNode(node->rightNode, val, s);
        return node;
    }

    // Helper function to find the minimum node in a subtree
    BSTNode *findMinNode(BSTNode *node)
    {
        if (node->leftNode == nullptr)
            return node;
        return findMinNode(node->leftNode);
    }

    // Helper function for deleting a node from the BST
    BSTNode *deleteNode(BSTNode *node, int val)
    {
        if (node == nullptr)
            return nullptr;
        else if (val < node->data)
            node->leftNode = deleteNode(node->leftNode, val);
        else if (val > node->data)
            node->rightNode = deleteNode(node->rightNode, val);
        else
        {
            if (node->leftNode == nullptr && node->rightNode == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->leftNode == nullptr)
            {
                BSTNode *temp = node->rightNode;
                delete node;
                return temp;
            }
            else if (node->rightNode == nullptr)
            {
                BSTNode *temp = node->leftNode;
                delete node;
                return temp;
            }
            else
            {
                BSTNode *minNode = findMinNode(node->rightNode);
                node->data = minNode->data;
                node->str = minNode->str;
                node->rightNode = deleteNode(node->rightNode, minNode->data);
            }
        }
        return node;
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int val, const string &s)
    {
        root = insertNode(root, val, s);
    }

    // Function to remove a value from the BST
    void remove(int val)
    {
        root = deleteNode(root, val);
    }

    // Function to print the contents of the BST
    void print()
    {
        cout << "Contents of tree by inorder traversal: " << endl;
        inorderTraversal(root, 0);
        cout << "-----------" << endl;
    }
};

int main()
{
    BST tree;

    // Initially empty tree
    tree.print();

    // Inserting nodes
    tree.insert(3, "...");
    tree.print();

    tree.insert(1, "++ +");
    tree.print();

    tree.insert(5, "-- -");
    tree.print();

    tree.insert(2, ", , , ");
    tree.print();

    tree.insert(4, "* **");
    tree.print();

    tree.insert(6, "000");
    tree.print();

    // Inserting a duplicate value
    tree.insert(3, "...");
    tree.print();

    // Removing a node
    tree.remove(5);
    tree.print();

    return 0;
}


// Coded with ❤ by Aimal Khan.