#include "PerfectHash.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

InnerTable::InnerTable()
{
    elems_.resize(1);
}

int InnerTable::hash(int n)
{
    return ((a_ * n + b_) % PRIME) % elems_.size();
}

void InnerTable::setNewHash()
{
    a_ = rand();
    b_ = rand();
}

void InnerTable::rehashInner(int elem, bool toInsert)
{
    vector<int> old_elems;
    for (int i = 0; i < elems_.size(); i++)
    {
        if (elems_[i].second)
        {
            old_elems.push_back(elems_[i].first);
        }
    }
    if (toInsert)
    {
        old_elems.push_back(elem);
    }
    elems_.clear();
    elems_.resize(sj);
    bj = old_elems.size();
    bool rehash = true;
    while (rehash)
    {
        fill(elems_.begin(), elems_.end(), make_pair(0, false));
        setNewHash();
        rehash = false;
        for (int i = 0; i < old_elems.size(); i++)
        {
            int index = hash(old_elems[i]);
            if (elems_[index].second)
            {
                rehash = true;
                break;
            }
            else
            {
                elems_[index].first = old_elems[i];
                elems_[index].second = true;
            }
        }
    }
}

// void InnerTable::insertElement(int n)
// {
//     if (num_elems_ >= elems_.size())
//     {
//         elems_.resize(elems_.size() * elems_.size());
//         rehashAll();
//     }
//     int index = hash(n);
//     while (elems_[index].second)
//     {
//         rehashAll();
//         index = hash(n);
//     }
//     elems_[index].first = n;
//     elems_[index].second = true;
//     num_elems_++;
// }

// void InnerTable::deleteElement(int n)
// {
//     int index = hash(n);
//     elems_[index].second = false;
//     num_elems_--;
//     if (num_elems_ < pow(elems_.size(), 0.25))
//     {
//         if (pow(elems_.size(), 0.25) < MIN_THRESHOLD)
//         {
//             return;
//         }
//         elems_.resize(sqrt(elems_.size()));
//         rehashAll();
//     }
// }

// void InnerTable::clearTable()
// {
//     num_elems_ = 0;
//     elems_.clear();
//     fill(elems_.begin(), elems_.end(), make_pair(0, false));
// }

HashTable::HashTable()
{
    buckets_.resize(1);
    rehashAll(-1);
}

int HashTable::hash_main(int n)
{
    return ((a_main_ * n + b_main_) % PRIME) % buckets_.size();
}

void HashTable::setNewHash()
{
    a_main_ = rand();
    b_main_ = rand();
}

void HashTable::insertElement(int x)
{
    count++;
    if (count >= M)
    {
        rehashAll(x, true);
    }
    else
    {
        int index = hash_main(x);
        if (buckets_[index].elems_[buckets_[index].hash(x)].first == x)
        {
            if (!buckets_[index].elems_[buckets_[index].hash(x)].second)
            {
                buckets_[index].elems_[buckets_[index].hash(x)].second = true;
                num_elems_++;
                cout << "Element " << x << " inserted in " << index << " bucket " << buckets_[index].hash(x) << " index" << endl;
            }
            else
            {
                cout << "Element " << x << " already exists" << endl;
            }
        }
        else
        {
            buckets_[index].bj++;
            num_elems_++;
            if (buckets_[index].bj <= buckets_[index].mj)
            {
                if (!buckets_[index].elems_[buckets_[index].hash(x)].second)
                {
                    buckets_[index].elems_[buckets_[index].hash(x)].first = x;
                    buckets_[index].elems_[buckets_[index].hash(x)].second = true;
                }
                else
                {
                    buckets_[index].rehashInner(x, true);
                }
            }
            else
            {
                buckets_[index].mj = 2 * max(1, buckets_[index].mj);
                buckets_[index].sj = 2 * buckets_[index].mj * (buckets_[index].mj - 1);
                if (starStarSatisfied())
                {
                    buckets_[index].rehashInner(x, true);
                }
                else
                {
                    rehashAll(x, true);
                }
            }
        }
    }
}

void HashTable::deleteElement(int x)
{
    count++;
    if (buckets_[hash_main(x)].elems_[buckets_[hash_main(x)].hash(x)].second && buckets_[hash_main(x)].elems_[buckets_[hash_main(x)].hash(x)].first == x)
    {
        buckets_[hash_main(x)].elems_[buckets_[hash_main(x)].hash(x)].second = false;
        cout << "Element " << x << " deleted from " << hash_main(x) << " bucket " << buckets_[hash_main(x)].hash(x) << " index" << endl;
    }
    else
    {
        cout << "Element " << x << " not found" << endl;
    }
    if (count >= M)
    {
        rehashAll(-1, false);
    }
}

bool HashTable::findElement(int x)
{
    if (buckets_[hash_main(x)].elems_[buckets_[hash_main(x)].hash(x)].second && buckets_[hash_main(x)].elems_[buckets_[hash_main(x)].hash(x)].first == x)
    {
        cout << "Element " << x << " found in " << hash_main(x) << " bucket " << buckets_[hash_main(x)].hash(x) << " index" << endl;
        return true;
    }
    else
    {
        cout << "Element " << x << " not found" << endl;
        return false;
    }
}

void HashTable::rehashAll(int elem, bool toInsert)
{
    // reHashAll is either called by insertElement or deleteElement
    // for toInsert, x is the new element to be inserted
    // for deleteElement(x), x is -1 and toInsert is false

    // append all elements to a vector

    vector<int> old_elems;
    for (int i = 0; i < buckets_.size(); i++)
    {
        for (int j = 0; j < buckets_[i].elems_.size(); j++)
        {
            if (buckets_[i].elems_[j].second)
            {
                old_elems.push_back(buckets_[i].elems_[j].first);
                buckets_[i].elems_[j].second = false;
            }
        }
    }
    if (toInsert)
    {
        old_elems.push_back(elem);
    }

    count = old_elems.size();
    num_elems_ = old_elems.size();
    M = (1 + c_global) * max(MIN_THRESHOLD, count);
    sM = max(1, 2 * (num_elems_ - 1));
    buckets_.resize(sM);

    vector<vector<int>> new_distribution(buckets_.size());
    do
    {
        setNewHash();
        for (auto &v : new_distribution)
        {
            v.clear();
        }
        for (int i = 0; i < old_elems.size(); i++)
        {
            int index = hash_main(old_elems[i]);
            new_distribution[index].push_back(old_elems[i]);
        }
        for (int j = 0; j < buckets_.size(); j++)
        {
            buckets_[j].bj = new_distribution[j].size();
            buckets_[j].mj = 2 * buckets_[j].bj;
            buckets_[j].sj = max(1, 2 * buckets_[j].mj * (buckets_[j].mj - 1));
        }

    } while (!starStarSatisfied());

    for (int i = 0; i < buckets_.size(); i++)
    {
        buckets_[i].elems_.resize(buckets_[i].sj);
        fill(buckets_[i].elems_.begin(), buckets_[i].elems_.end(), make_pair(0, false));
        bool rehash = true;
        while (rehash)
        {
            rehash = false;
            buckets_[i].setNewHash();
            for (int j = 0; j < new_distribution[i].size(); j++)
            {
                int index = buckets_[i].hash(new_distribution[i][j]);
                if (buckets_[i].elems_[index].second)
                {
                    rehash = true;
                    break;
                }
                else
                {
                    buckets_[i].elems_[index].first = new_distribution[i][j];
                    buckets_[i].elems_[index].second = true;
                }
            }
        }
    }
}

bool HashTable::starStarSatisfied()
{
    double sj_sum = 0;
    for (int i = 0; i < buckets_.size(); i++)
    {
        sj_sum += buckets_[i].sj;
    }
    return (sj_sum <= (32 * pow(M, 2) / buckets_.size()) + 4 * M);
}

void HashTable::print()
{
    for (int i = 0; i < buckets_.size(); i++)
    {
        cout << "\nBucket " << i << ": ";
        for (int j = 0; j < buckets_[i].elems_.size(); j++)
        {
            cout << "\nSlot " << j << " : ";
            if (buckets_[i].elems_[j].second)
            {
                cout << buckets_[i].elems_[j].first << "";
            }
        }
        cout << "\n\n";
    }
    cout << endl;
}
