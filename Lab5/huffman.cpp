#include "huffman.h"
#include <string>
#include <queue>
#include <unordered_map>
#include <bitset>



// Function to allocate a new tree node
Node* newNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Function to generate Huffman encoding tree
Node* buildHuffmanTree(string text) {
    // Count the frequency of each character in the text
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
    }

    // Run the following steps until there is only one node left in the queue
    while (pq.size() != 1) {
        // Remove the two nodes of the highest priority from the queue
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children and with a frequency
        // equal to the sum of the frequencies of the two nodes. Add the new node to the queue.
        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    // The remaining node in the queue is the root node of the Huffman tree
    return pq.top();
}

// Function to generate Huffman codes for each character
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& codeTable) {
    if (root == nullptr) {
        return;
    }

    // If the node is a leaf node, then it stores one of the characters of the input text,
    // and its Huffman code can be obtained by traversing the path from the root to the leaf.
    if (root->left == nullptr && root->right == nullptr) {
        codeTable[root->ch] = code;
        return;
    }

    // Traverse the left subtree and append 0 to the code
    generateHuffmanCodes(root->left, code + "0", codeTable);

    // Traverse the right subtree and append 1 to the code
    generateHuffmanCodes(root->right, code + "1", codeTable);
}

// Function to encode the input text using the Huffman codes
string encode(string text, unordered_map<char, string>& codeTable) {
    string encoded = "";
    for (char ch : text) {
        encoded += codeTable[ch];
    }
    return encoded;
}

// Function to decode the input text using the Huffman codes
string decode(string code, Node* root) {
    string answer;
    Node* current = root;
    for (int i=0; i<code.length(); i++)
    {
        if (code[i] == '0') {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current->left==NULL && current->right==NULL) {
            answer += current->ch;
            current = root;
        }
    }
    return answer;
}

// Function to calculate the size of a file in bytes
long long fileSize(string filename) 
{
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}