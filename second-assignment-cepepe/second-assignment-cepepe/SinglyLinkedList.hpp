#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include "ElemPixel.hpp"

class SinglyLinkedList
{
    ElemPixel* header; //Pointer to the first element in the list
    ElemPixel* last;   //Pointer to the last element in the list
public:
    SinglyLinkedList();   //Constructor
    ~SinglyLinkedList();  //Destructor
    
    void insert(RGBPixelXY* ppix);    //Adds a new element to the list
    ElemPixel* retrieve();            //Retrieves the first element of the list
    bool isEmpty();                   //Checks if the list is empty
    ElemPixel* getHeader();           //Returns the pointer to the header element
    SinglyLinkedList* copyList();      //Returns a copy of the list

};

#endif // SINGLYLINKEDLIST_HPP
