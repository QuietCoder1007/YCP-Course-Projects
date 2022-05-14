//
//  BST.h
//

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <limits>
#include "Node.h"

// Binary search tree class
template <class T>
class BST
{
public:
    /* **************************************************************** */
    // Fields
    /* **************************************************************** */
    Node<T> *root;
    int numNodes;
    
    /* **************************************************************** */
    // EXAM #2 Methods
    /* **************************************************************** */
    Node<T> * findPredecessor(Node<T> * node);
    Node<T> * findNodeIteratively(Node<T> * node,const T & x);
    int height(Node<T> * node);
    
    /* **************************************************************** */
    // Other Methods
    /* **************************************************************** */
    BST();
    ~BST();
    void insert(const T & x);
    Node<T> * insertNode(Node<T> * node,const T & x);
    void removeAllNodes(Node<T> * node);
    /* **************************************************************** */
};

#endif
