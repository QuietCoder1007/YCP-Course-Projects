//
//  IntArrayStack.cpp
//

#include "IntArrayStack.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
// TODO: Constructor
IntArrayStack::IntArrayStack(){
    capacity = 1;
    top = -1;
    stack = new int[capacity];
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
// TODO: Destructor
IntArrayStack::~IntArrayStack() {
    delete[] stack;
}
#endif

/* **************************************************************** */

#if PUSH || ALL
// TODO: push()
void IntArrayStack::push(int value){
    top++;
    if(top == capacity){
        resize(capacity*2);
    }
    stack[top] = value;
}
#endif

/* **************************************************************** */

#if POP || ALL
// TODO: pop()
int IntArrayStack::pop(){
    if(top != -1){
        int value = stack[top];
        top--;
        if(top < capacity/3 && capacity != 1){
            resize(capacity/2);
        }
        return value;
    }
    return -1;
}
#endif

/* **************************************************************** */

#if PEEK || ALL
// TODO: peek()
int IntArrayStack::peek(){
    if( top == -1 ){
        return top;
    }
    else{
        return stack[top];
    }
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty()
bool IntArrayStack::isEmpty() {
    return top == -1;
}
#endif

/* **************************************************************** */

#if EMPTYSTACK || ALL
// TODO: emptyStack
void IntArrayStack::emptyStack(){
    capacity = 1;
    top = -1;

}
#endif

/* **************************************************************** */

#if RESIZE || ALL
// TODO: resize()
void IntArrayStack::resize(int newCapacity){

    int *new_stack = new int[newCapacity];

    for( int i = 0; i <= top; i++ ){
        new_stack[i] = stack[i];
    }
    
    capacity = newCapacity;

    delete[] stack;

    stack = new_stack;
}
#endif

/* **************************************************************** */
// Do NOT modify anything below this line
// Do NOT use these methods in your implementation of your data
// structure.  They are included here to support the unit tests.
/* **************************************************************** */

#ifndef BUILD_LIB
void IntArrayStack::printStack()
{
    std::cout << std::endl;
    std::cout << "Current array size: " << capacity << std::endl;
    std::cout << "Number of ints in stack: " << top+1 << std::endl;
    for (int i=top; i >= 0; i--)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}


// Do NOT use this method in your implementation
int IntArrayStack::getCapacity()
{
    return capacity;
}


// Do NOT use this method in your implementation
int IntArrayStack::getSize()
{
    return top+1;
}


// Do NOT use this method in your implementation
int IntArrayStack::getTop()
{
    return top;
}


// Do NOT use this method in your implementation
void IntArrayStack::toArray(int* arr)
{
    for (int i=0; i < capacity; i++)
    {
        arr[i] = stack[i];
    }
}
#endif

/* **************************************************************** */


