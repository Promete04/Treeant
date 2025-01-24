#ifndef BINARYBALANCEDTREE_HPP
#define BINARYBALANCEDTREE_HPP
#include <iostream>
#include "TreeNode.hpp"
#include "SinglyLinkedList.hpp"

class BinaryBalancedTree
{
    TreeNode* root;        //Pointer to the root of the tree
    
public:
    BinaryBalancedTree();  //Constructor
    ~BinaryBalancedTree(); //Destructor
    
    void makenull(TreeNode* nnode); //Auxiliary method to delete all nodes recursively
    int nodeHeight(TreeNode* nnode);  //Calculates the height of the node and returns it
    void biggestNode(TreeNode* nnode, TreeNode* &largestNode, int &largestSize); //Finds the node with the most pixels in the tree
    void balance(TreeNode* nnode, TreeNode* pparent); //Balances the tree starting from the given node by performing rotations based on balance factors
    int howBalanced(TreeNode* nnode);  
    
    //Calculates how balanced the tree is at the given node by subtracting the depth of the right subtree 
    //from the depth of the left subtree (returns the balance factor of the node)
    void leftRotate(TreeNode* nnode, TreeNode* pparent);   //Performs a left rotation around the given node
    void rightRotate(TreeNode* nnode, TreeNode* pparent);  //Performs a right rotation around the given node
    TreeNode* cloneTree(TreeNode* nnode);   //Returns a copy of the tree starting from the given node
               
    void create_balance(TreeNode* nnode); //Clones the input tree and balances it
    bool isEmpty();        //Checks if the tree is empty
    TreeNode* getRoot();   //Returns the root node of the tree
    
    //Collect all pixels from nodes in the tree and insert them in an auxiliary list of pixels
    void pixelsFoundInNodes(TreeNode* nnode, SinglyLinkedList* llist);   
    //Insert pixels from the second image into the tree. If a pixel with a sumRgb that is not in any node arrives, it is discarded
    void insertImg2Pixels(RGBPixelXY* ppix);
};

#endif // BINARYBALANCEDTREE_HPP
