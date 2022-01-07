#ifndef MERGE_h
#define MERGE_H
#include <vector>
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

#endif