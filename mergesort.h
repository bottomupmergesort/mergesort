#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include "listnode.h"
using namespace std;

template <typename T>
void mergesortBU(vector<T>& a)
{
    vector<T> tmp(a.size());
    for (int i = 1; i < a.size(); i *= 2)
    {
        for (int j = 0; j < a.size(); j += 2*i)
        {
            merge(a, tmp, j, std::min<T>(a.size(), j + i), std::min<T>(a.size(), j + 2*i));
        }
    }
}

template <typename T>
void mergesortR(vector<T>& a, vector<T>& tmp, int l, int r)
{
    if (r-l <= 1) return;
    int m = (r+l) / 2;
    mergesortR(a, tmp, l, m);
    mergesortR(a, tmp, m, r);
    merge(a, tmp, l, m, r);
}

template <typename T>
void mergsort(vector<T>& a)
{
    vector<T> tmp(a.size());
    mergesortR(a, tmp, 0, a.size());
}

template <typename T>
listnode<T>* mergesort(listnode<T>* a)
{
    if (a == nullptr || a->next == nullptr)
        return a;

    listnode<T>* slow = a;
    listnode<T>* fast = a->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    listnode<T>* back = slow->next;
    slow->next = nullptr;
    return merge(mergesort(a), mergesort(back));
}

#endif