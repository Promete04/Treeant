#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "SinglyLinkedList.hpp"

class TreeNode
{
    SinglyLinkedList* list;  //List of pixels that share sumRGB values
    int sumRGB;              //The sumRGB value for identifying the node
    TreeNode* leftchild;     //Pointer to left child child
    TreeNode* rightchild;    //Pointer to right child node
 
public:
    TreeNode(SinglyLinkedList* nlist, int nSumRGB);  //Constructor with the initialized list and the sumRGB value of the node as parameters
    ~TreeNode();                                     //Destructor
    
    SinglyLinkedList* getList();   //Returns the list of pixels associated to the node
    
    TreeNode* getRightChild();                    //Returns the right child node
    TreeNode* getLeftChild();                     //Returns the left child node
    int getSumRGB();                              //Returns the sumRGB value
    void setRightChild(TreeNode* nrightchild);    //Sets the right child node
    void setLeftChild(TreeNode* nleftchild);      //Sets the left child node
    

};

#endif // TREENODE_HPP
