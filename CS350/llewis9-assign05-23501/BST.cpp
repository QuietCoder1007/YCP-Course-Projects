//
//  BST.cpp
//

#include "BST.h"
#include "Flags.h"

/* **************************************************************** */

#if ALL || CONSTRUCTOR
template <class T>
BST<T>::BST()
{
    // TODO: Initialize root
    root = nullptr;
    numNodes = 0;
}
#endif

/* **************************************************************** */

#if ALL || DESTRUCTOR
template <class T>
BST<T>::~BST()
{
    // TODO: Remove any nodes
    removeAllNodes(root);
    root = nullptr;
    numNodes = 0;
    delete root;
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
// TODO: isEmpty() method
template <class T>
bool BST<T>::isEmpty(){
    return root == nullptr && numNodes == 0;
}
#endif

/* **************************************************************** */

#if ALL || FIND
// TODO: find() method
template <class T>
bool BST<T>::find(const T & x){
    return findNode(root, x);
}

#endif

/* **************************************************************** */

#if ALL || FINDMIN
// TODO: findMin() method
template <class T>
const T & BST<T>::findMin(){
    if(isEmpty()){
        throw 1;
    } else {
        return findMinNode(root)->data;
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDMAX
// TODO: findMax() method
template <class T>
const T & BST<T>::findMax(){
    if(isEmpty()){
        throw 1;
    } else {
        return findMaxNode(root)->data;
    }
}
#endif

/* **************************************************************** */

#if ALL || INSERT
// TODO: insert() method
template <class T>
void BST<T>::insert(const T & x){
    if (isEmpty()){
        root = new Node<T>(x);
        numNodes++;
    } else {
        insertNode(root, x);
    }
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
// TODO: remove() method
template <class T>
void BST<T>::remove(const T &x) {
    Node<T> *currentNode = findNode(root, x);

    if (currentNode != nullptr){
        Node<T> *parentNode = findParentOf(x);

        if(currentNode->left == nullptr && currentNode->right == nullptr){
            if (parentNode != nullptr){
                if (parentNode->left == currentNode){
                    parentNode->left = nullptr;
                } else if (parentNode->right == currentNode){
                    parentNode->right = nullptr;
                }
            }

            if (currentNode == root) {
                root = nullptr;
            }
            delete currentNode;
        } else if(currentNode->left != nullptr && currentNode->right == nullptr){
            Node<T> *leftNode = currentNode->left;
            currentNode->data = leftNode->data;
            currentNode->right = leftNode->right;
            currentNode->left = leftNode->left;
            delete leftNode;

        } else if(currentNode->left == nullptr && currentNode->right != nullptr){
            Node<T> *rightNode = currentNode->right;
            currentNode->data = rightNode->data;
            currentNode->left = rightNode->left;
            currentNode->right = rightNode->right;
            delete rightNode;

        } else if (currentNode->left != nullptr && currentNode->right != nullptr){
            Node<T> *successorNode = findSuccessor(currentNode);
            parentNode = findParentOf(successorNode->data);
            currentNode->data = successorNode->data;

            if (parentNode->left == successorNode){
                parentNode->left = nullptr;
            } else {
                parentNode->right = successorNode->right;
            }
            delete successorNode;
        }
        --numNodes;
    }
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
// TODO: makeEmpty() method
template <class T>
void BST<T>::makeEmpty(){
    removeAllNodes(root);
    root = nullptr;
    numNodes = 0;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/*  Private methods                                                 */
/* **************************************************************** */
#if ALL || FINDNODE
// TODO: findNode() private method
template <class T>
Node<T> * BST<T>::findNode(Node<T> * node, const T & x){
    if (node == nullptr || node->data == x){
        return node;
    } else if (x < node->data){
        return findNode(node->left, x);
    } else {
        return findNode(node->right, x);
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDMINNODE
// TODO: findMinNode() private method
template <class T>
Node<T> * BST<T>::findMinNode(Node <T> *node){
    if (!isEmpty()){
        if (node->left == nullptr){
            return node;
        } else{
            return findMinNode(node->left);
        }
    }
    return nullptr;
}
#endif

/* **************************************************************** */

#if ALL || FINDMAXNODE
// TODO: findMaxNode() private method
template <class T>
Node<T> * BST<T>::findMaxNode(Node <T> *node){
    if(!isEmpty()){
        if (node->right == nullptr){
            return node;
        } else {
            return findMaxNode(node->right);
        }
    }
    return nullptr;
}
#endif

/* **************************************************************** */

#if ALL || INSERTNODE
// TODO: insertNode() private method
template <class T>
Node<T> * BST<T>::insertNode(Node<T> * node, const T & x){
    if(node == nullptr){
        node = new Node<T>(x);
        numNodes++;
    } else if (x < node->data){
        node->left = insertNode(node->left, x);
    } else if (x > node->data){
        node->right = insertNode(node->right, x);
    }
    return node;

}
#endif

/* **************************************************************** */

#if ALL || FINDSUCCESSOR
// TODO: findSuccessor() private method
template <class T>
Node<T> * BST<T>::findSuccessor(Node<T> *node) {

    if (node->right == nullptr){
        return node->right;
    }
    Node<T> * currentNode = node->right;

    while(currentNode->left){
        currentNode = currentNode->left;
    }
    return currentNode;
}
#endif

/* **************************************************************** */

#if ALL || FINDPARENTOF
// TODO: findParentOf() private method
template <class T>
Node<T> * BST<T>::findParentOf(const T &x) {
    Node<T> *currentNode = root;
    Node<T> *parentNode = nullptr;

    if (currentNode == nullptr || currentNode->data == x){
        return parentNode;
    } else{
        while (currentNode->data != x) {
            parentNode = currentNode;
            if (currentNode->data > x && currentNode->left != nullptr){
                currentNode = currentNode->left;
            } else if (currentNode->data < x && currentNode->right != nullptr){
                currentNode = currentNode->right;
            }
        }
        return parentNode;
    }
}
#endif

/* **************************************************************** */

#if ALL || REMOVEALLNODES
// TODO: removeAllNodes() private method
template <class T>
void BST<T>::removeAllNodes(Node<T> * node){
    if (node != nullptr){
        if(node->left != nullptr){
            removeAllNodes(node->left);
        }

        if (node->right != nullptr){
            removeAllNodes(node->right);
        }
        delete node;
        --numNodes;
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
// Print tree
template <class T>
void BST<T>::printTree()
{
    if (!isEmpty())
    {
        printNodesInOrder(root);
        std::cout << std::endl;
    } else {
        std::cout << "Empty Tree" << std::endl;
    }
}

// Print tree using level order traversal
template <class T>
void BST<T>::printNodesInOrder(Node<T> * node)
{
    Node<T>*q[100];
    int head = 0;
    int tail = 0;
    q[0] = root;
    tail++;

    while (head != tail) {
        Node<T> *n = q[head];
        head++;
        std::cout << "Node " << n->data << " ";
        if (n->left != nullptr) {
            std::cout << " left child: " << n->left->data;
            q[tail] = n->left;
            tail++;
        }
        if (n->right != nullptr) {
            std::cout << " right child: " << n->right->data;
            q[tail] = n->right;
            tail++;
        }

        if (n->left == nullptr && n->right == nullptr) {
            std::cout << " no children";
        }
        std::cout << std::endl;
    }
}
#endif

template class BST<int>;
