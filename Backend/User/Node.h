#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>

template<typename T>
class Node
{
public:
    Node(const T& i = T(), Node<T>* n = NULL)
        : info(i), next(n)
    {

    }

    T info;
    Node<T>* next;
};

#endif // NODE_H_
