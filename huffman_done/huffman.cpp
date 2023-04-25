
#include "huffman.h"

void codify(data *root, const string &prefix, unordered_map<char, string> &neep)
{
    if (root->rch == nullptr || root->lch == nullptr)
        neep[root->ch] = prefix;
    else
    {
        codify(root->lch, prefix + "0", neep);
        codify(root->rch, prefix + "1", neep);
    }
}

pair<string, string> encode(const string &input)
{
    priority_queue<data *, vector<data *>, Compare> freqs;

    unordered_map<char, int> test;
    for (char ch : input)
    {
        if (test.find(ch) == test.end())
        {
            test[ch] = 1;
        }
        else
            test[ch]++;
    }

    for (auto kv : test)
    {
        data *x = new data{kv.first, kv.second, nullptr, nullptr};
        freqs.push(x);
    }

    // One character
    if (freqs.size() == 1)
    {
        return pair<string, string>{string(1, '0') + "," + freqs.top()->ch + " ", string(freqs.top()->val, '0')};
    }
    while (freqs.size() > 1)
    {
        auto a = freqs.top();
        freqs.pop();
        auto b = freqs.top();
        freqs.pop();
        data *c = new data{a->ch, a->val + b->val, a, b};
        freqs.push(c);
    }

    auto root = freqs.top();

    unordered_map<char, string> codes;
    codify(root, "", codes);

    string s1, s2;
    for (const auto &kv : codes)
    {
        s1 += kv.second + "," + kv.first + " ";
    }
    for (char ch : input)
    {
        s2 += codes[ch];
    }
    return pair<string, string>{s1, s2};
}

void gen_map(const string &str, data **root, char code)
{
    if (str.empty())
    {
        *root = new data{code};
    }
    else
    {
        if ((*root)->rch == nullptr)
            (*root)->rch = new data{'\0'};
        if ((*root)->lch == nullptr)
            (*root)->lch = new data{'\0'};
        if (str[0] == '0')
        {
            gen_map(str.substr(1), &(*root)->lch, code);
        }
        if (str[0] == '1')
        {
            gen_map(str.substr(1), &(*root)->rch, code);
        }
    }
}
