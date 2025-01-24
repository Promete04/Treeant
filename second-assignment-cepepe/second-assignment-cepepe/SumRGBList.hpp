#ifndef SUMRGBLIST_HPP
#define SUMRGBLIST_HPP

#include "SumRGBListNode.hpp"

class SumRGBList
{
    SumRGBListNode* header;   //Pointer to the first node in the list
    SumRGBListNode* last;     //Pointer to the last node in the list
public:
    SumRGBList();             //Constructor
    ~SumRGBList();            //Destructor
    
    void insert(int nvalue);      //Adds a new node to the list
    SumRGBListNode* retrieve();   //Retrieves the first node of the list
    bool isEmpty();               //Checks if the list is empty
    SumRGBListNode* getHeader();  //Returns a pointer to the header node

};

#endif // SUMRGBLIST_HPP
