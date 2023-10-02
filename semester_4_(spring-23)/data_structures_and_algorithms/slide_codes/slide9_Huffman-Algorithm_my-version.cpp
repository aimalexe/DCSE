#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

// Node structure for the Huffman tree
struct Node
{
    char data;
    int frequency;
    Node *left;
    Node *right;

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue used in Huffman's algorithm
struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

// Huffman class
class Huffman
{
private:
    Node *root;
    unordered_map<char, string> codes;

    // Recursive function to build the Huffman tree
    Node *buildTree(const unordered_map<char, int> &frequencyTable)
    {
        priority_queue<Node *, vector<Node *>, CompareNodes> pq;

        // Create a leaf node for each character and add it to the priority queue
        for (auto &entry : frequencyTable)
        {
            char c = entry.first;
            int freq = entry.second;
            pq.push(new Node(c, freq));
        }

        // Combine the two least frequent nodes until only one node remains
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            // Create a new internal node with combined frequency
            // and push it back into the priority queue
            int combinedFreq = left->frequency + right->frequency;
            Node *internalNode = new Node('$', combinedFreq);
            internalNode->left = left;
            internalNode->right = right;
            pq.push(internalNode);
        }

        // The remaining node in the priority queue is the root of the Huffman tree
        return pq.top();
    }

    // Recursive function to generate Huffman codes for each character
    void generateCodes(Node *node, const string &code)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->data != '$')
        {
            codes[node->data] = code;
        }

        generateCodes(node->left, code + "0");
        generateCodes(node->right, code + "1");
    }

public:
    // Constructor
    Huffman(const unordered_map<char, int> &frequencyTable)
    {
        root = buildTree(frequencyTable);
        generateCodes(root, "");
    }

    // Encode a given string using Huffman codes
    string encode(const string &text)
    {
        string encodedText = "";
        for (char c : text)
        {
            encodedText += codes[c];
        }
        return encodedText;
    }

    // Decode a given Huffman encoded string
    string decode(const string &encodedText)
    {
        string decodedText = "";
        Node *current = root;
        for (char bit : encodedText)
        {
            if (bit == '0')
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }

            if (current->left == nullptr && current->right == nullptr)
            {
                decodedText += current->data;
                current = root;
            }
        }
        return decodedText;
    }
};

int main()
{
    string text = "I am Aimal Khan.";

    // Create a frequency table for the characters in the text
    unordered_map<char, int> frequencyTable;
    for (char c : text)
    {
        frequencyTable[c]++;
    }

    // Create a Huffman object with the frequency table
    Huffman huffman(frequencyTable);

    // Encode the text using Huffman codes
    string encodedText = huffman.encode(text);
    cout << "Encoded text: " << encodedText << endl;

    // Decode the encoded text
    string decodedText = huffman.decode(encodedText);
    cout << "Decoded text: " << decodedText << endl;

    return 0;
}

// Coded with ❤ by Aimal Khan.