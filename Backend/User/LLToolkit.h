#ifndef LLTOOLKIT_H_
#define LLTOOLKIT_H_
#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class LLToolkit
{
public:
    // Precondition: headPtr points to the head of a list
    // Postcondition: Info has been inserted at the head of the list, and headPtr is updated
    void headInsert(Node<T>*& headPtr, T data)
    {
        headPtr = new Node<T>(data, headPtr);
    }

    // Precondition: headPtr points to the head of a list with at least 1 element
    // Postcondition: The head element has been removed and headPtr is updated to point to the new 
    // head element
    void headRemove(Node<T>*& headPtr)
    {
        if (headPtr != NULL)
        {
            Node<T>* condemned = headPtr;
            headPtr = headPtr->next;
            delete condemned;
        }
    }


    // Precondition: prevPtr points to Node just before insertion point
    // Postcondition: A new Node with data=info has been inserted into the list after prevPtr
    void insert(Node<T>*& prevPtr, T data)
    {
        if (prevPtr == NULL) return;
        Node<T>* next = prevPtr->next;
        prevPtr->next = new Node<T>(data, next);
    }


    // Precondition: prevPtr points to Node just before Node to remove
    // Postcondition: The Node after prevPtr has been removed from the list 
    void remove(Node<T>*& prevPtr)
    {
        if (prevPtr == NULL) return;
        if (prevPtr->next == NULL) return;
        Node<T>* condemned = prevPtr->next;
        prevPtr->next = condemned->next;
        delete prevPtr->next;
    }


    // Precondition: sourcePtr is the head pointer of a linked list.
    // Postcondition: A pointer to a copy of the linked list is returned. The original list is 
    // unaltered.
    Node<T>* copy(Node<T>* sourcePtr)
    {
        Node<T>* headPtr = NULL;	// Head pointer for new list
        Node<T>* tailPtr = NULL;

        // Handle the case of the empty list.
        if (sourcePtr == NULL) return headPtr;

        // Make the head LLNode for the newly created list, and put data in it.
        headInsert(headPtr, sourcePtr->info);
        tailPtr = headPtr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        sourcePtr = sourcePtr->next;
        while (sourcePtr != NULL)
        {
            insert(tailPtr, sourcePtr->info);
            tailPtr = tailPtr->next;
            sourcePtr = sourcePtr->next;
        }
        return headPtr;
    }

    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: All nodes of the list have been deleted, and the headPtr is NULL.
    void clear(Node<T>* headPtr)
    {

        while (headPtr != NULL)
        {
            Node<T>* prevPtr = headPtr;
            headPtr = headPtr->next;
            delete prevPtr;
        }
        return headPtr;

    }

    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: The data item of each Node in the list has been printed to the screen in an
    // easily readable way, e.g. “3 - 4 - 7 -/”
    void print(Node<T>* headPtr)
    {
        while (headPtr != NULL)
        {
            cout << headPtr->info << endl;
            headPtr = headPtr->next;
        }
    }

    // Precondition: headPtr is the head pointer of a linked list.
    // Postcondition: headPtr points to the start of a list that is reversed with respect to the
    // original list
    void reverse(Node<T>*& headPtr)
    {
        Node<T>* tempPtr = NULL;	// Head pointer for new list

        // Handle the case of the empty list.
        if (headPtr == NULL)
        {
            cout << "Can't reverse an empty list" << endl;
            return;
        }

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        while (headPtr != NULL)
        {
            headInsert(tempPtr, headPtr->info);
            headPtr = headPtr->next;
        }
        headPtr = tempPtr;
    }

    // Precondition: splitPtr points to the node before the split point
    // Postcondition: A pointer is returned that points to the first node after splitPtr. The
    // original list ends at the node pointed to by splitPtr
    Node<T>* split(Node<T>* splitPtr)
    {
        Node<T>* newHeadPtr = splitPtr->next;
        splitPtr->next = NULL;

        return newHeadPtr;
    }

    // Precondition: values points to an array of at least size n
    // Postcondition: A pointer is returned that points to the head of a list in which the nodes
    // contains values from the array values
    Node<T>* build(int* values, size_t n)
    {
        Node<T>* headPtr = NULL;	// Head pointer for new list
        Node<T>* tailPtr = NULL;

        // Make the head LLNode for the newly created list, and put data in it.
        headInsert(headPtr, values[0]);
        tailPtr = headPtr;

        for (int i = 1; i < n; i++)
        {
            insert(tailPtr, values[i]);
            tailPtr = tailPtr->next;
        }
        return headPtr;
    }

    // Precondition: head1 and head2 each point to the head of linked lists
    // Postcondition: head1 points to a list containing head1-lists' elements followed by head2-lists
    // element.
    void join(Node<T>* head1, Node<T>* head2)
    {
        Node<T> *tailPtr;

        //kører en løkke for at finde sidste plads
        //i head1 så listerne kan sættes sammen.
        while (head1 != NULL)
        {
            tailPtr = head1;
            head1 = head1->next;
        }

        //TailPtr bliver nu brugt til at sætte de lister sammen
        tailPtr->next = head2;
    }

    // Precondition: head points to the head of a linked list
    // Postcondition: The list is rotated left by once - if it was 1-2-3-4, it is now 2-3-4-1
    void rotateLeft(Node<T>*& headPtr)
    {
        Node<T> *tailPtr;
        Node<T> *tempPtr = headPtr;

        //kører en løkke for at finde sidste værdi i listen
        while (tempPtr != NULL)
        {
            tailPtr = tempPtr;
            tempPtr = tempPtr->next;
        }

        insert(tailPtr, headPtr->info);
        headPtr = headPtr->next;


    }

    // Precondition: head points to the head of a linked list
    // Postcondition: The list is rotated right once - if it was 1-2-3-4, it is now 4-1-2-3
    void rotateRight(Node<T>*& head)
    {
        Node<T> *tailPtr;
        Node<T> *tempPtr = head;


        //en while løkke til at finde den sidste værdi i den linkede liste
        while (tempPtr->next != NULL)
        {
            tailPtr = tempPtr;
            tempPtr = tempPtr->next;
        }

        headInsert(head, tempPtr->info);
        tailPtr->next = NULL;
        delete tempPtr;
    }
};

#endif // LLTOOLKIT_H_
