#include "SumRGBList.hpp"

//Constructor initializes the list with header and last pointers set to null
SumRGBList::SumRGBList()
{
    header = nullptr;
    last = nullptr;
}

//Destructor to free memory by deleting all nodes in the list
SumRGBList::~SumRGBList()
{
    while(!isEmpty())
    {
        delete(retrieve());
    }
}

//Adds a new node at the end of the list
void SumRGBList::insert(int nvalue)
{
    SumRGBListNode* node = new SumRGBListNode(nvalue);  //Create new node with the value given as parameter
    
    if(isEmpty())   //Check if the list is empty, if it is, new node is set to be the header and last nodes of the list
    {
        header = node;
        last = node;
        node->setNext(nullptr);
    }
    else    //If the list wasn't empty
    {
        last->setNext(node);      //Insert the new node at the end by linking it to the end of the last node
        node->setNext(nullptr);
        last = node;              //Update last node pointer
    }
    
}

//Retrieves the first node of the list
SumRGBListNode* SumRGBList::retrieve()
{
    SumRGBListNode* node = nullptr;  //Temporary pointer
    
    if(!isEmpty())    //Check if the list is empty
    {
        node = header;               //Store header node in tmp
        header = header->getNext();  //Update header to point to the next node
        node->setNext(nullptr);      //We make sure that the retrieved node is disconnected from the others
        
        if(header == nullptr)    //If header is null (list is now empty)
        {
            last = nullptr;      //Then also last pointer is set to null
        }
    }
    
    return node;    //Return tmp (retrieved node)
}

//Checks if the list is empty
bool SumRGBList::isEmpty()
{
    return header == nullptr;   //If the header is null, then return true (is empty)
}

//Returns the pointer to the header node
SumRGBListNode* SumRGBList::getHeader()
{
    return header;
}