#include <iostream>
using namespace std;

#define MAXIMUM_NUMBER_OF_TREES 100
#define MAX_PATH_LENGTH 20

struct node
{
    char symbol;
    float probability;
    node *pleft;
    node *pright;
};

class path
{
public:
    path();
    ~path();
    void add_to_path(int direction);
    void remove_from_path();
    void print_path();

private:
    int path_components[MAX_PATH_LENGTH];
    int path_length;
};

path::path()
{
    for (int i = 0; i < MAX_PATH_LENGTH; i++)
    {
        path_components[i] = 0;
    }
    path_length = 0;
}

path::~path()
{
}

void path::add_to_path(int direction)
{
    if (path_length < MAX_PATH_LENGTH)
    {
        path_components[path_length] = direction;
        path_length++;
    }
    else
    {
        cout << "Error: Maximum path length reached." << endl;
    }
}

void path::remove_from_path()
{
    if (path_length > 0)
    {
        path_length--;
    }
    else
    {
        cout << "Error: No path exists." << endl;
    }
}

void path::print_path()
{
    for (int i = 0; i < path_length; i++)
    {
        cout << path_components[i];
    }
    cout << endl;
}

class tree
{
public:
    tree();
    ~tree();
    void add(char s, float p);
    void print();
    node *&search(int n);
    int delnode(int x);
    void compute_map();

private:
    node *root;
    void deltree(node *&p);
    void addnode(char s, float p, node *&pnode);
    void pr(const node *p, int n) const;
    void prorder(const node *p) const;
    void traverse_leaf_nodes(const node *p, path &code);
    void leafnode_traversal(const node *p) const;
};

void tree::add(char s, float p)
{
    addnode(s, p, root);
}

void tree::addnode(char s, float p, node *&pnode)
{
    if (pnode == nullptr)
    {
        pnode = new node;
        pnode->symbol = s;
        pnode->probability = p;
        pnode->pleft = nullptr;
        pnode->pright = nullptr;
    }
    else if (p < pnode->probability)
    {
        addnode(s, p, pnode->pleft);
    }
    else
    {
        addnode(s, p, pnode->pright);
    }
}

void tree::print()
{
    pr(root, 0);
}

void tree::pr(const node *p, int n) const
{
    if (p != nullptr)
    {
        pr(p->pleft, n + 1);
        for (int i = 0; i < n; i++)
        {
            cout << " ";
        }
        cout << p->symbol << " " << p->probability << endl;
        pr(p->pright, n + 1);
    }
}

void tree::compute_map()
{
    path code;
    traverse_leaf_nodes(root, code);
}

void tree::traverse_leaf_nodes(const node *p, path &code)
{
    if (p != nullptr)
    {
        if (p->pleft == nullptr && p->pright == nullptr)
        {
            cout << p->symbol << " ";
            code.print_path();
            cout << endl;
        }
        else
        {
            code.add_to_path(0);
            traverse_leaf_nodes(p->pleft, code);
            code.remove_from_path();

            code.add_to_path(1);
            traverse_leaf_nodes(p->pright, code);
            code.remove_from_path();
        }
    }
}

void tree::leafnode_traversal(const node *p) const
{
    if (p != nullptr)
    {
        if (p->pleft == nullptr && p->pright == nullptr)
        {
            cout << p->symbol << " " << p->probability << endl;
        }
        else
        {
            leafnode_traversal(p->pleft);
            leafnode_traversal(p->pright);
        }
    }
}

void tree::prorder(const node *p) const
{
    if (p != nullptr)
    {
        prorder(p->pleft);
        cout << p->symbol << " ";
        prorder(p->pright);
    }
}

void tree::deltree(node *&p)
{
    if (p != nullptr)
    {
        deltree(p->pleft);
        deltree(p->pright);
        delete p;
        p = nullptr;
    }
}

tree::tree()
{
    root = nullptr;
}

tree::~tree()
{
    deltree(root);
}

class forest
{
public:
    forest(int size);
    ~forest();
    void initialize_forest();
    void add_to_tree(int tree_number, char symbol, float probability);
    void print_forest() const;
    void print_tree(int tree_number);
    void join_trees(int tree_1, int tree_2);
    int empty_tree(int tree_number);
    float root_probability(int tree_number);
    void compute_map();

private:
    tree tree_array[MAXIMUM_NUMBER_OF_TREES];
    int forest_size;
};

forest::forest(int size)
{
    forest_size = size;
}

forest::~forest()
{
}

void forest::initialize_forest()
{
    // Code to initialize the forest
}

void forest::add_to_tree(int tree_number, char symbol, float probability)
{
    if (tree_number >= 0 && tree_number < MAXIMUM_NUMBER_OF_TREES)
    {
        tree_array[tree_number].add(symbol, probability);
    }
}

void forest::print_forest() const
{
    // Code to print the entire forest
}

void forest::print_tree(int tree_number)
{
    if (tree_number >= 0 && tree_number < MAXIMUM_NUMBER_OF_TREES)
    {
        tree_array[tree_number].print();
    }
}

void forest::join_trees(int tree_1, int tree_2)
{
    // Code to join two trees in the forest
}

int forest::empty_tree(int tree_number)
{
    if (tree_number >= 0 && tree_number < MAXIMUM_NUMBER_OF_TREES)
    {
        // Code to check if a tree is empty or not
        // Return true or false accordingly
    }
    return false; // Default return false
}

float forest::root_probability(int tree_number)
{
    if (tree_number >= 0 && tree_number < MAXIMUM_NUMBER_OF_TREES)
    {
        // Code to calculate and return the root probability of a tree
    }
    return 0.0; // Default return 0.0
}

void forest::compute_map()
{
    int i;
    for (i = 0; i < MAXIMUM_NUMBER_OF_TREES; i++)
    {
        if (empty_tree(i) == false)
        {
            tree_array[i].compute_map();
        }
    }
}

int main()
{
    forest myForest(MAXIMUM_NUMBER_OF_TREES);

    // Perform operations on the forest and trees
    // Example usage:
    myForest.initialize_forest();
    myForest.add_to_tree(0, 'A', 0.5);
    myForest.add_to_tree(0, 'B', 0.3);
    myForest.add_to_tree(1, 'C', 0.2);
    myForest.print_tree(0);
    myForest.compute_map();
    
    return 0;
}

// Debugged with ❤ by Aimal Khan.