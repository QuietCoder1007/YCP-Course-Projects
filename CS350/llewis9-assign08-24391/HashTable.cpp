//
//  HashTable.cpp
//

#include "HashTable.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
HashTable::HashTable(int tableSize)
{
    // TODO: Constructor
    table = new Node*[tableSize];
    for ( int i = 0; i < tableSize; i++ )
    {
        table[i] = nullptr;
    }
    size = tableSize;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
HashTable::~HashTable()
{
    // TODO: Destructor
    for ( int i = 0; i < size; i++ )
    {
        Node * node = table[i];
        while (node)
        {
            delete node;
            node = node->next;
        }
    }
    delete[] table;
    table = new Node*[0];
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
void HashTable::insert(std::string x)
{

    if( !find(x) )
    {   Node * node = new Node(x);
        if( !table[hash(x)] )
        {
            table[hash(x)] = node;
        } else {
            Node * nextNode = table[hash(x)];
            table[hash(x)] = node;
            table[hash(x)]->next = nextNode;
        }
    }
}
#endif

/* **************************************************************** */

#if FIND || ALL
// TODO: find() method
bool HashTable::find(std::string x)
{
    Node * node = table[hash(x)];
    while( node && node->data != x )
    {
        node = node->next;
    }
    return node && node->data == x;
}
#endif

/* **************************************************************** */

#if REMOVE || ALL
// TODO: remove() method
void HashTable::remove(std::string x){

    if(find(x))
    {
        Node * node = table[hash(x)];
        Node * prev_node = node;
        while( node->data != x )
        {
            prev_node = node;
            node = node->next;
        }

        if ( prev_node != node )
        {
            prev_node->next = node->next;
        } else {
            table[hash(x)] = node->next;
        }
        delete node;
    }
}
#endif

/* **************************************************************** */

#if LOADFACTOR || ALL
float HashTable::loadFactor()
{
    // TODO: loadFactor() method
    float num_elements = 0;
    for ( int i = 0; i < size; i++ )
    {  Node *node =  table[i];
       while ( node )
        {   num_elements++;
            node = node->next;
        }
    }

    return num_elements/(float)size;

}
#endif

/* **************************************************************** */

#if MAXCHAINLENGTH || ALL
// TODO: maxChainLength() method
void HashTable::maxChainLength(int& maxLength, int& maxSlotIndex){
    maxLength = 0;
    maxSlotIndex = 0;
    for ( int i = 0; i < size; i++ )
    {  Node *node =  table[i];
        int counter = 0;
        while ( node )
        {
            counter++;
            node = node->next;
        }
        if( counter > maxLength ){
            maxLength = counter;
            maxSlotIndex = i;
        }

    }

}
#endif

/* **************************************************************** */

#if NUMEMPTYSLOTS || ALL
// TODO: numEmptySlots() method
int HashTable::numEmptySlots(){
    int counter = 0;
    for( int i = 0; i < size; i++ )
    {
        counter += !table[i] ? 1 : 0;
    }
    return counter;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
unsigned int HashTable::hash(std::string x) {
    unsigned int hashCode = 0;
    std::string::iterator it;
    for (it=x.begin(); it < x.end(); it ++) {
        hashCode = *it + (hashCode << 5) - hashCode;
    }
    return hashCode % size;
}


void HashTable::printHashTable() {
    std::stringstream ss;
    printHashTableToStream(ss);
    std::cout << ss.str();
}


void HashTable::printHashTableToStream(std::stringstream& ss) {
    Node* node;
    // Iterate over table
    for (int i = 0; i < size; i++) {
        ss << "[" << i << "]: ";
        // Iterate over list
        node = table[i];
        while (node != nullptr) {
            ss << node->data << " -> ";
            node = node->next;
        }
        ss << "nullptr" << std::endl;
    }
}
#endif
