#include "SumRGBListNode.hpp"

//Constructor which initializes a node with the given value and sets its next pointer to null
SumRGBListNode::SumRGBListNode(int nvalue)
{
    value = nvalue;
    next = nullptr;
}

//Destructor
SumRGBListNode::~SumRGBListNode()
{
}

//Returns the sumRGB value of the node
int SumRGBListNode::getValue()
{
    return value;
}

//Returns a pointer to the next node 
SumRGBListNode* SumRGBListNode::getNext()
{
    return next;
}

//Sets the pointer to the next node
void SumRGBListNode::setNext(SumRGBListNode* nnode)
{
    next = nnode;
}

