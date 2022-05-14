//
//  BST.cpp
//

#include "BST.h"
#include "Flags.h"



/* **************************************************************** */

#if ALL || FINDPREDECESSOR
template <class T>
Node<T> * BST<T>::findPredecessor(Node<T> * node) {
    
    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    if (node->left == nullptr){
        return node->left;
    }
    Node<T> * currentNode = node->left;

    while(currentNode->right != nullptr){
        currentNode = currentNode->right;
    }
    return currentNode;

}
#endif

/* **************************************************************** */

#if ALL || FINDNODEITERATIVELY
template <class T>
Node<T> * BST<T>::findNodeIteratively(Node<T> * node, const T & x) {
    Node<T> *currentNode = node;
    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    if(currentNode == nullptr || x == currentNode->data){
        return currentNode;
    } else {
        while (currentNode != nullptr) {
            if (currentNode->data > x){
                currentNode = node->left;
            }

            if (currentNode->data < x){
                currentNode = node->right;
            }
        }
        return currentNode;
    }

}
#endif

/* **************************************************************** */

#if ALL || HEIGHT
template <class T>
int BST<T>::height(Node<T> * node) {
    int height = 0;
    Node<T> * currentNode1 = node;
    Node<T> * currentNode2 = node;
    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    if (node == nullptr){
        return 0;
    } else {
        while (currentNode1 != nullptr && currentNode2 != nullptr){
            if (node->left != nullptr){
                currentNode1 = node->left;
                height++;
            }
            if (node->right != nullptr){
                currentNode2 = node->right;
                height++;
            }
        }
        return height;
    }

}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* **************************************************************** */
/* **************************************************************** */

// DO NOT DELETE THE FOLLOWING LINE!!!
template class BST<int>;
