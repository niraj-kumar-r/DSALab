#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H
#include <queue>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using std::unordered_map, std::vector, std::pair, std::priority_queue, std::string;

typedef struct pl
{
    char ch;
    int val;
    pl *lch, *rch;
} data;

class Compare
{
public:
    bool operator()(data *lhs, data *rhs)
    {
        return (lhs->val > rhs->val);
    }
};
void codify(data *root, const string &prefix, unordered_map<char, string> &neep);
pair<string, string> encode(const string &input);
void gen_map(const string &str, data **root, char code);
#endif // HUFFMAN_HUFFMAN_H
