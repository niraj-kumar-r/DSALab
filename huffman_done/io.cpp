#include "io.h"

void write(string bstr, ofstream &fptr)
{
    string rounded_bstr = bstr + string(8 - bstr.length() % 8, '0');
    for (int i = 0; i < rounded_bstr.size();)
    {
        // iterate 8 times
        unsigned char mask = 0x80;
        char byte = 0;
        for (; mask > 0; mask = mask >> 1)
        {
            if (rounded_bstr[i] == '1')
            {
                byte = byte | mask;
            }
            i++;
        }
        fptr.write(&byte, 1);
    }
}

void write()
{
    string in;
    getline(cin, in);

    auto coded = (encode(in));

    ofstream file("file.bin", std::ios::binary);
    string first = coded.first, second = coded.second;
    file << first << second.length() << std::endl;

    write(second, file);
    file.close();
}

string read(const string &fname)
{
    ifstream file(fname, std::ios::binary);
    string metadata;
    getline(file, metadata);
    stringstream ss(metadata);
    long n;
    string word;
    data *decode = new data{'\0', 0, nullptr, nullptr};
    while (ss >> word)
    {
        if (isdigit(word.back()))
        {
            n = stol(word);
        }
        else
        {
            if (word.back() == ',' and word[word.length() - 2] != ',')
                word += " ";
            gen_map(word.substr(0, word.length() - 2), &decode, word.back());
        }
    }

    char str[(n + 7) / 8];
    file.read(str, (n + 7) / 8);
    stringstream ss2;
    int i = 0;
    for (char cur : str)
    {
        if (i >= n)
            break;
        unsigned char mask = 0x80;
        for (; mask > 0; mask = mask >> 1)
        {
            i++;
            if (cur & mask)
            {
                ss2 << '1';
            }
            else
            {
                ss2 << '0';
            }
        }
    }

    auto test = ss2.str();
    stringstream out;
    auto traverse = decode;
    for (char cur : test)
    {
        if (traverse->lch == nullptr)
        {
            out << traverse->ch;
            traverse = decode;
        }

        switch (cur)
        {
        case '1':
            traverse = traverse->rch;
            break;
        case '0':
            traverse = traverse->lch;
            break;
        }
    }

    return out.str();
}
