#include "BinaryBalancedTree.hpp"

//Constructor initializes de binary balanced tree with its root pointer set to null
BinaryBalancedTree::BinaryBalancedTree()
{
    root = nullptr;
}

//Destructor for deleting the tree by calling makenull which recursively deletes every node
BinaryBalancedTree::~BinaryBalancedTree()
{
    makenull(root);
}

//Recursively deletes all nodes in the tree
void BinaryBalancedTree::makenull(TreeNode* nnode)
{
    if (nnode != nullptr)
    {
        //Postorder traversal
        makenull(nnode->getLeftChild());  
        makenull(nnode->getRightChild()); 
        delete(nnode);  //Delete current node     
    }
}

//Calculates how balanced the tree is at the given node by subtracting the height of the right subtree 
//from the height of the left subtree (returns the balance factor of the node)
int BinaryBalancedTree::howBalanced(TreeNode* node)
{
        int rightWeight;
        int leftWeight;
        
        leftWeight = nodeHeight(node->getLeftChild());   //Calculate the height of the left subtree
        rightWeight = nodeHeight(node->getRightChild()); //Calculate the height of the right subtree
        
        
        return (leftWeight-rightWeight); //Returns balance factor of the node
}

//Balances the tree starting from the given node by performing rotations based on balance factors
void BinaryBalancedTree::balance(TreeNode* node, TreeNode* parent)
{
    if (node != nullptr)
    {
        //Postorder traversal
        balance(node->getLeftChild(), node);
        balance(node->getRightChild(), node);

        //Get the balance factor of the current node
        int balanceFactor = howBalanced(node);

        if (balanceFactor <= -2) //Right-heavy tree
        {
            //If the right child is also right-heavy, perform a right-right case rotation 
            if (howBalanced(node->getRightChild()) <= 0)  
            {
                leftRotate(node, parent);    //Left rotation to balance the tree
            }
            else //If the right child is left-heavy, perform right-left case rotations
            {
                rightRotate(node->getRightChild(), node); //First perform a right rotation on the right child
                leftRotate(node, parent);                 //Then a left rotation on the current node
            }
        }
        else if (balanceFactor >= 2) //Left-heavy tree
        {
            //If the left child is also left-heavy, perform a left-left case rotation 
            if (howBalanced(node->getLeftChild()) >= 0) 
            {
                rightRotate(node, parent);    //Right rotation to balance the tree
            }
            else //If the left child is right-heavy, perform left-right case rotations
            {
                leftRotate(node->getLeftChild(), node); //First perform a left rotation on the left child
                rightRotate(node, parent);              //Then a right rotation on the current node
            } 
        }
    }
    return;
}


//Performs a right rotation around the given node
void BinaryBalancedTree::rightRotate(TreeNode* node, TreeNode* parent)
{
    TreeNode* newRoot = node->getLeftChild();       //The left child of the current node becomes the new root of this subtree
    node->setLeftChild(newRoot->getRightChild());   //Update left child of the current node to the right child of the new root
    newRoot->setRightChild(node);                   //Make current node the right child of the new root

    // Update parent pointer
    if (node == root)     //If the current node is the root of the tree
    { 
        root = newRoot;   //Update the tree's root to the new one
    }
    else  //If not
    {
        if (parent->getLeftChild() == node)  //If the current node is the left child of its parent, update the parent's left pointer
        {
            parent->setLeftChild(newRoot);
        }
        else                                 //Otherwise, update the parent's right pointer
        {
            parent->setRightChild(newRoot);
        }
    }
}

//Performs a left rotation around the given node
void BinaryBalancedTree::leftRotate(TreeNode* node, TreeNode* parent)
{
    TreeNode* newRoot = node->getRightChild();      //The right child of the current node becomes the new root of this subtree
    node->setRightChild(newRoot->getLeftChild());   //Update right child of the current node to the left child of the new root
    newRoot->setLeftChild(node);                    //Make current node the left child of the new root


    //Update parent pointer 
    if (node == root)    //If the current node is the root of the tree
    {
        root = newRoot;  //Update the tree's root to the new one
    }
    else   //If not
    {
        
        if (parent->getLeftChild() == node) //If the current node is the left child of its parent, update the parent's left pointer
        {
            parent->setLeftChild(newRoot);
        }
        else                                //Otherwise, update the parent's right pointer
        {
            parent->setRightChild(newRoot);
        }
    }
}

//Returns a copy of the tree starting from the given node
TreeNode* BinaryBalancedTree::cloneTree(TreeNode* node)
{
    TreeNode* newRoot = nullptr;   //Initialize the new root as null
    
    if (node != nullptr)
    {
        //Create a copy of the list in the current node
        SinglyLinkedList* copyList = node->getList()->copyList();
        
        //Create a new node with the copied list and sumRGB
        newRoot = new TreeNode(copyList, node->getSumRGB());

        //Preorder traversal
        newRoot->setLeftChild(cloneTree(node->getLeftChild()));
        newRoot->setRightChild(cloneTree(node->getRightChild()));
    }
    
    return newRoot; //Return the new root of the cloned tree or null if the original tree is empty
}

//Clones the input tree and balances it
void BinaryBalancedTree::create_balance(TreeNode* rroot)
{
    root = cloneTree(rroot);    //Clone the input tree to avoid modifying the original
    balance(root, nullptr);     //Balance the tree
}


//Calculates the height of the node and returns it
int BinaryBalancedTree::nodeHeight(TreeNode* node)
{
    int height = 0;  
    if (node != nullptr) 
    {
        //Postorder traversal
        int leftHeight = nodeHeight(node->getLeftChild());     //Get the height of the left subtree
        int rightHeight = nodeHeight(node->getRightChild());   //Get the height of the right subtree
        
        //Calculate the height of the current node by adding 1 to the maximum of the left and right subtree height
        if (leftHeight > rightHeight) 
        {
            height = 1 + leftHeight;  
        } 
        else 
        {
            height = 1 + rightHeight;  
        }
    }

    return height;  //Return the node height
}



//Checks if the tree is empty
bool BinaryBalancedTree::isEmpty()
{
    return root == nullptr;   //Returns true if the root is null (is empty)
}

//Find the node that has the most pixels by using postorder traversal
//The parameters passed to the method are the current node (for the recursive call) and two references: 
//one that stores the largestNode and another that stores the number of pixels in the node
//Using references allows the method to directly modify these values, and any changes made to the 
//references are reflected outside the method (in the original variables)
void BinaryBalancedTree::biggestNode(TreeNode* nnode, TreeNode* &largestNode, int &largestSize)
{
    if(nnode != nullptr)
    {
        //Postorder traversal
        biggestNode(nnode->getLeftChild(), largestNode, largestSize);   
    
        biggestNode(nnode->getRightChild(), largestNode, largestSize);  
    
        //Count the number of elements in the current node's list
        int currentSize = 0;
        ElemPixel* tmp = nnode->getList()->getHeader();  //Temporary pointer to the header of the list contained in the node
    
        while(tmp != nullptr)
        {
            currentSize++;           //Increment the size for each pixel in the list
            tmp = tmp->getNext();    //Update tmp to the next element
        }
        
        if(currentSize > largestSize)  //If the current node has more elements that the previous largest, update the references
        {
            largestSize = currentSize;
            largestNode = nnode;
        }
    }
    
    return;
}

//Returns the root of the tree
TreeNode* BinaryBalancedTree::getRoot()
{
    return root;
}

//Insert pixels from the second image into the tree, we decided to make the insertion iteratively rather than 
//recursively because it was easier to see what was going on. If a pixel with a sumRGB that is not in any node arrives, it is discarded
void BinaryBalancedTree::insertImg2Pixels(RGBPixelXY* ppix)
{
    int sumRgb = ppix->getSumRGB();    //Get the sumRGB of the pixel
    
    TreeNode* tmp = root;
    bool discarded  = false;    //Bolean to check if the pixel was discarded
    bool inserted = false;      //Bolean to check if the pixel was inserted
    
    while(tmp != nullptr && !discarded && !inserted ) //Traverse the tree until the pixel is inserted or the pixel was discarded
    {
        if(sumRgb == tmp->getSumRGB())  //If a node with the same sumRGB already exists
        {
            tmp->getList()->insert(ppix);    //Add the pixel to the node's list
            inserted  = true;                //Update inserted boolean
        }
        else if (sumRgb < tmp->getSumRGB())  //If the pixel sumRGB is smaller, then go to the left child
        {
            if(tmp->getLeftChild() == nullptr)   //If there is no node for the pixel sumRGB the discard it
            {
                discarded  = true;   //Update discarded boolean
            }
            tmp = tmp->getLeftChild();   //Update tmp pointer to the left child
        }
        else  //If the pixel sumRGB is larger, go to the right child
        {
            if(tmp->getRightChild() == nullptr)    //If there is no node for the pixel sumRGB then discard it
            {
                discarded  = true;    //Update discarded boolean
            }
            tmp = tmp->getRightChild();    //Update tmp pointer to the right child
        }
    }
}

//Collect all pixels from nodes in the tree and insert them in an auxiliary list of pixels by using inorder traversal
void BinaryBalancedTree::pixelsFoundInNodes(TreeNode* nnode, SinglyLinkedList* llist)
{
    if (nnode != nullptr)
    {
        pixelsFoundInNodes(nnode->getLeftChild(), llist);
        
        ElemPixel* tmp = nnode->getList()->getHeader();  //Temporary pointer to the header of the list contained in the node

        while(tmp != nullptr)   //Insert all pixels from the current node into the list
        {
            RGBPixelXY* pp = tmp->getPix();
            llist->insert(pp);     //Insert the pixel into the list
            tmp = tmp->getNext();  //Update tmp to point to the next element of the list
        }
            
        pixelsFoundInNodes(nnode->getRightChild(), llist);
    }
    
    return;    
}