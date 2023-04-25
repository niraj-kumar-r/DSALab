#include "huffman.h"
#include <string>
#include <queue>
#include <unordered_map>
#include <bitset>

Node *newNode(char ch, int freq, Node *left, Node *right)
{
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

Node *buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }

    priority_queue<Node *, vector<Node *>, comp> pq;

    for (auto pair : freq)
    {
        pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    return pq.top();
}

void generateHuffmanCodes(Node *root, string code, unordered_map<char, string> &codeTable)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        codeTable[root->ch] = code;
        return;
    }

    generateHuffmanCodes(root->left, code + "0", codeTable);
    generateHuffmanCodes(root->right, code + "1", codeTable);
}

string encode(string text, unordered_map<char, string> &codeTable)
{
    string encoded = "";
    for (char ch : text)
    {
        encoded += codeTable[ch];
    }
    return encoded;
}

string decode(string code, Node *root)
{
    string answer;
    Node *current = root;
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL)
        {
            answer += current->ch;
            current = root;
        }
    }
    return answer;
}

long long fileSize(string filename)
{
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}