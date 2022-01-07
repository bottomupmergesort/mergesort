#ifndef MERGE_h
#define MERGE_H
#include <vector>
#include "listnode.h"
using namespace std;

template <typename T>
void merge(vector<T>& a, vector<T>& tmp, int l, int m, int r)
{
    int i = l, j = m, k = l;
    while (i < m && j < r)
        tmp[k++] = (a[i] < a[j]) ? a[i++]:a[j++];
    while (i < m) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    for (k = l; k < r; k++)
      a[k] = tmp[k];
}

template <typename T>
listnode<T>* merge(listnode<T>* a, listnode<T>* b)
{
    listnode<T> tempnode(0);
    listnode<T> *head = &tempnode, *c = head;
    while ((a!=nullptr) && (b!=nullptr))
    {
        if (a->info < b->info)
        {
            c->next = a; c = a; a = a->next;
        } else {
            c->next = b; c = b; b = b->next;
        }
    }
    c->next = (a == nullptr) ? b:a;
    return head->next;
}

#endif