#ifndef SUMRGBLISTNODE_HPP
#define SUMRGBLISTNODE_HPP

class SumRGBListNode
{ 
    int value;             //Stores sumRGB value of the node
    SumRGBListNode* next;  //Pointer to the next node in the list
public:
    SumRGBListNode(int nvalue);  //Constructor with the sumRGB value as parameter 
    ~SumRGBListNode();           //Destructor
    
    int getValue();                        //Returns the sumRGB value of the node
    SumRGBListNode* getNext();             //Returns a pointer to the next node 
    void setNext(SumRGBListNode* nnext);   //Sets the pointer to the next node
};

#endif // SUMRGBLISTNODE_HPP
