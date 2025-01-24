#include "TreeNode.hpp"

//Constructor which initializes the node with the given list and sumRGB value and sets the node rightchild and leftchild pointers to null
TreeNode::TreeNode(SinglyLinkedList* nlist, int nSumRGB)
{
    list = nlist;
    rightchild = nullptr;
    leftchild = nullptr;
    sumRGB = nSumRGB;
}

//Destructor to free memory
TreeNode::~TreeNode()
{
    delete(list);
}

//Returns the list of pixels associated to the node
SinglyLinkedList* TreeNode::getList()
{
    return list;
}

//Returns the right child node
TreeNode* TreeNode::getRightChild()
{
    return rightchild;
}

//Returns the left child node
TreeNode* TreeNode::getLeftChild()
{
    return leftchild;
}

//Sets the right child node
void TreeNode::setRightChild(TreeNode* nrightchild)
{
    rightchild = nrightchild;
}

//Sets the left child node
void TreeNode::setLeftChild(TreeNode* nleftchild)
{
    leftchild = nleftchild;
}

//Returns the sumRGB value
int TreeNode::getSumRGB()
{
    return sumRGB;
}






