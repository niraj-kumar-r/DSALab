#include "PerfectHash.h"
#include <algorithm>

using namespace std;

InnerTable::InnerTable()
{
    num_elems_ = 0;
    elems_.resize(MIN_THRESHOLD);
    for (int i = 0; i < MIN_THRESHOLD; i++)
    {
        elems_[i].first = 0;
        elems_[i].second = false;
    }
    a_ = rand();
    b_ = rand();
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

void InnerTable::rehashAll()
{
    vector<pair<int, bool>> old_elems = elems_;
    elems_.clear();
    elems_.resize(old_elems.size());
    bool rehash = true;
    while (rehash)
    {
        fill(elems_.begin(), elems_.end(), make_pair(0, false));
        setNewHash();
        rehash = false;
        for (int i = 0; i < old_elems.size(); i++)
        {
            if (old_elems[i].second)
            {
                int index = hash(old_elems[i].first);
                if (elems_[index].second)
                {
                    rehash = true;
                    break;
                }
                else
                {
                    elems_[index].first = old_elems[i].first;
                    elems_[index].second = true;
                }
            }
        }
    }
}
