#include "SinglyLinkedList.hpp"

//Constructor which initializes the list with its header and last pointers set to null
SinglyLinkedList::SinglyLinkedList()
{
    header = nullptr;
    last = nullptr;
}

//Destructor to free memory by deleting all elements in the list
SinglyLinkedList::~SinglyLinkedList()
{
    while(!isEmpty())
    {
        delete(retrieve());
    }
}

//Adds a new element at the end of the list
void SinglyLinkedList::insert(RGBPixelXY* ppix)
{
    ElemPixel* elem = new ElemPixel(ppix);   //Create new element containing the pixel
    
    if(isEmpty())  //Check if the list is empty, if it is, new element is set to be the header and last elements of the list
    {
        header = elem;
        last = elem;
        elem->setNext(nullptr);
    }
    else   //If the list wasn't empty
    {
        last->setNext(elem);    //Insert new element at the end by linking it to the end of the last element
        elem->setNext(nullptr);
        last = elem;            //Update last element pointer
    }
    
}

//Retrieves the first element of the list
ElemPixel* SinglyLinkedList::retrieve()
{
    ElemPixel* tmp = nullptr;   //Temporary pointer
    if(!isEmpty())     //Check if list is empty
    {
        tmp = header;                 //Store header element in tmp
        header = header->getNext();   //Update header to point to the next element
        tmp->setNext(nullptr);        //We make sure that the retrieved element is disconnected from the others
        
        if(header == nullptr)    //If header is null (list is now empty)
        {
            last = nullptr;      //Then also last pointer is set to null
        }
    }
    
    return tmp;   //Return tmp (retrieved element)
}

//Checks if the list is empty
bool SinglyLinkedList::isEmpty()
{
    return header == nullptr;       //If the header is null, then return true (is empty)
}

//Returns the pointer to the header element
ElemPixel* SinglyLinkedList::getHeader()
{
    return header;
}

SinglyLinkedList* SinglyLinkedList::copyList()
{
    SinglyLinkedList* newList = new SinglyLinkedList();  //Creates new list
    
    ElemPixel* tmp = header;  //Temporary pointer to front
    
    while(tmp != nullptr)  //Iterate through the original list starting from its front
    {
        RGBPixelXY* original = tmp->getPix();  //Get pixel from tmp
        RGBPixelXY* copy = new RGBPixelXY(original->getX(), original->getY(), original->getR(), original->getG(), original->getB());  //Creates new pixel (a copy)
        newList->insert(copy);  //Insert the copied pixel into the new list 
        tmp = tmp->getNext();  //Update tmp to point to its next element
    }
    
    return newList;  //Returns copied list
}
