#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include "TreeNode.hpp"
#include "SumRGBList.hpp"
#include "SinglyLinkedList.hpp"

class BinarySearchTree
{
    TreeNode* root;   //Pointer to the root of the tree
public:
    BinarySearchTree();  //Constructor
    ~BinarySearchTree(); //Destructor
    
    int nodeHeight(TreeNode* nnode);  //Calculates the height of the node and returns it
    void biggestNode(TreeNode* node, TreeNode* &largestNode, int &largestSize); //Finds the node with the most pixels in the tree
    void insertImg1Pixels(RGBPixelXY* ppix); //Inserts all pixels from the first image into the tree
    
    //Insert pixels from the second image into the tree. If a pixel with a sumRgb that is not in any node arrives, it is discarded
    void insertImg2Pixels(RGBPixelXY* ppix); 
    bool isEmpty();  //Checks if the tree is empty
    void makenull(TreeNode* nnode);     //Auxiliary method to delete all nodes recursively
    void obtainSumRGBInNodes(TreeNode* nnode, SumRGBList* slist);  //Collect sumRgb values from the tree nodes and insert them in an auxiliary list 
    TreeNode* getRoot();  //Returns the root node of the tree
    
    //Collect all pixels from nodes where there are more pixels with originFile 1 than originFile 2 and insert
    //them in an auxiliary list of pixels
    //Pixels from other nodes are inserted in the list as black pixels
    void pixelsFromNodesWithMoreOF1(TreeNode* nnode, SinglyLinkedList* llist);
    //Collect all pixels from nodes in the tree and insert them in an auxiliary list of pixels 
    void pixelsFoundInNodes(TreeNode* nnode, SinglyLinkedList* llist); 
};

#endif // BINARYSEARCHTREE_HPP