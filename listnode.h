#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class listnode {
    public:
    T info;
    listnode* next;
    listnode(T i, listnode* n) : info(i), next(n) { }
    listnode(T i) : info(i) { next = nullptr; }
    listnode() { next = nullptr; }
};

#endif