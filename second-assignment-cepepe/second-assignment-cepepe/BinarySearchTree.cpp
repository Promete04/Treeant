#include "BinarySearchTree.hpp"

//Constructor initializes de binary search tree with its root pointer set to null
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

//Destructor for deleting the tree by calling makenull which recursively deletes every node
BinarySearchTree::~BinarySearchTree()
{
    makenull(root);
}

//Recursively deletes all nodes in the tree
void BinarySearchTree::makenull(TreeNode* nnode)
{
    if (nnode != nullptr)
    {
        //Postorder traversal
        makenull(nnode->getLeftChild());  
        makenull(nnode->getRightChild()); 
        delete(nnode);                     //Delete current node     
    }
}

//Calculates the height of the node and returns it
int BinarySearchTree::nodeHeight(TreeNode* node)
{
    int height = 0;  
    if (node != nullptr) 
    {
        //Postorder traversal
        int leftHeight = nodeHeight(node->getLeftChild());    //Get the height of the left subtree
        int rightHeight = nodeHeight(node->getRightChild());  //Get the height of the right subtree
        
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

    return height;   //Return the node height
}

//Insert pixels from the first image into the tree, we decided to make the insertion iteratively rather than 
//recursively because it was easier to see what was going on
//If a node with the same sumRGB exists, the pixel is added to its list. Otherwise, a new node is created
void BinarySearchTree::insertImg1Pixels(RGBPixelXY* ppix)
{
    int sumRgb = ppix->getSumRGB();   //Get the sumRGB of the pixel
    
    if(isEmpty())  //If the tree is empty, the root node is created
    {
        SinglyLinkedList* list = new SinglyLinkedList();  //Create a new list to store pixels with the same sumRGB
        list->insert(ppix);                               //Insert the pixel into the list
        TreeNode* node = new TreeNode(list, sumRgb);      //Create the new TreeNode with the list and the sumRGB of th pixels of the list
        root = node;                                      //Set the root to the created node
    }
    else  //If the tree is not empty
    {
        TreeNode* tmp = root;  //Temporary pointer to iterate through the tree
        bool inserted = false; //Bolean to check if the pixel was inserted
        while(tmp != nullptr && !inserted)   //Traverse the tree until the pixel is inserted  
        {
            if(sumRgb == tmp->getSumRGB())  //If a node with the same sumRGB already exists
            {
                tmp->getList()->insert(ppix);    //Add the pixel to the node's list
                inserted = true;                 //Update inserted boolean
            }
            else if (sumRgb < tmp->getSumRGB())  //If the pixel sumRgb is smaller, then go to the left child
            {
                if(tmp->getLeftChild() == nullptr)  //If there is no node then create a new one 
                {
                    SinglyLinkedList* list = new SinglyLinkedList();   //Create a new list
                    list->insert(ppix);                                //Insert the pixel in the new list
                    TreeNode* newNode = new TreeNode(list, sumRgb);    //Create the new node with the list and the sumRgb of the pixels of the list
                    tmp->setLeftChild(newNode);                        //Set the current node left child to the created node
                    inserted = true;                                   //Update inserted boolean
                }
                tmp = tmp->getLeftChild();  //Update tmp pointer to the left child
            }
            else   //If the pixel sumRgb is larger, go to the right child
            {
                if(tmp->getRightChild() == nullptr) //If there is no node then create a new one 
                {
                    SinglyLinkedList* list = new SinglyLinkedList();     //Create a new list
                    list->insert(ppix);                                  //Insert the pixel in the new list
                    TreeNode* newNode = new TreeNode(list, sumRgb);      //Create the new node with the list and the sumRgb of the pixels of the list
                    tmp->setRightChild(newNode);                         //Set the current node's right child to the created node
                    inserted = true;                                     //Update inserted boolean
                }
                tmp = tmp->getRightChild(); //Update tmp pointer to the right child
            }
                
        }
    }
}

//Insert pixels from the second image into the tree, we decided to make the insertion iteratively rather than 
//recursively because it was easier to see what was going on. If a pixel with a sumRGB that is not in any node arrives, it is discarded
void BinarySearchTree::insertImg2Pixels(RGBPixelXY* ppix)
{
    int sumRgb = ppix->getSumRGB();  //Get the sumRGB of the pixel
    
    TreeNode* tmp = root;
    
    bool discarded  = false;  //Bolean to check if the pixel was discarded
    bool inserted = false;    //Bolean to check if the pixel was inserted
    
    while(tmp != nullptr && !discarded && !inserted ) //Traverse the tree until the pixel is inserted or the pixel was discarded
    {
        if(sumRgb == tmp->getSumRGB()) //If a node with the same sumRGB already exists
        {
            tmp->getList()->insert(ppix);  //Add the pixel to the node's list
            inserted  = true;              //Update inserted boolean
        }
        else if (sumRgb < tmp->getSumRGB())  //If the pixel sumRGB is smaller, then go to the left child
        {
            if(tmp->getLeftChild() == nullptr)  //If there is no node for the pixel sumRGB the discard it
            { 
                discarded  = true;    //Update discarded boolean
            }
            tmp = tmp->getLeftChild();   //Update tmp pointer to the left child
        }
        else  //If the pixel sumRGB is larger, go to the right child
        {
            if(tmp->getRightChild() == nullptr)  //If there is no node for the pixel sumRGB then discard it
            {
                discarded  = true;     //Update discarded boolean
            }
            tmp = tmp->getRightChild();  //Update tmp pointer to the right child
        }
    }
}

//Checks if the tree is empty
bool BinarySearchTree::isEmpty()
{
    return root == nullptr;   //Returns true if the root is null (is empty)
}

//Collect sumRgb values from the tree nodes and insert them in an auxiliary list of sumRgb values by using 
//inorder traversal (so the values are in order because of the binary search properties)
void BinarySearchTree::obtainSumRGBInNodes(TreeNode* nnode, SumRGBList* slist)
{
    if (nnode != nullptr)
    {
        obtainSumRGBInNodes(nnode->getLeftChild(), slist);   //Traverse left subtree
    
        slist->insert(nnode->getSumRGB());  //Insert the sumRgb attribute of the current node in the list
    
        obtainSumRGBInNodes(nnode->getRightChild(), slist);  //Traverse right subtree
    }
    
    return;    
}

//Find the node that has the most pixels by using postorder traversal
//The parameters passed to the method are the current node (for the recursive call) and two references: 
//one that stores the largestNode and another that stores the number of pixels in the node
//Using references allows the method to directly modify these values, and any changes made to the 
//references are reflected outside the method  (in the original variables)
void BinarySearchTree::biggestNode(TreeNode* nnode, TreeNode* &largestNode, int &largestSize)
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
TreeNode* BinarySearchTree::getRoot()
{
    return root;
}

//Collect all pixels from nodes where there are more pixels with originFile 1 than originFile 2 and insert
//them in an auxiliary list of pixels by using inorder traversal
//Pixels from other nodes are inserted in the list as black pixels
void BinarySearchTree::pixelsFromNodesWithMoreOF1(TreeNode* nnode, SinglyLinkedList* llist)
{
    if (nnode != nullptr)
    {
        
        pixelsFromNodesWithMoreOF1(nnode->getLeftChild(), llist);
        
        ElemPixel* tmp = nnode->getList()->getHeader();  //Temporary pointer to the header of the list contained in the node
        int of1, of2 = 0;                                //Counters for the number of pixels with originFile 1 and originFile 2
        
        //Count the pixels with originFile 1 and originFile 2 in the current node
        while(tmp != nullptr)
        {
            RGBPixelXY* pp = tmp->getPix();
            if(pp->getOriginFile() == 1)
            {
                of1++;
            }
            else
            {
                of2++;
            }
            tmp = tmp->getNext();
        }
        
        //If there are more pixels with originFile 1, then insert all the pixels in the list
        if(of1 > of2)
        {
            tmp = nnode->getList()->getHeader();  //Make tmp point to the header of the node's list again
            
            while(tmp != nullptr)  //Insert all pixels of the node
            {
                RGBPixelXY* pp = tmp->getPix();
                llist->insert(pp);     
                tmp = tmp->getNext();
            }
        }
        else //Nodes that doesn't meet the criteria, insert copies of the pixels with black color
        {
            tmp = nnode->getList()->getHeader();   //Make tmp point to the header of the node's list again
            
            while(tmp != nullptr)  //Insert all the pixels of the node with black color
            {
                RGBPixelXY* original = tmp->getPix();
                //Create a copy of the pixels (so original pixels are not modified) with r g b components set to 0 (black)
                RGBPixelXY* ppCopy = new RGBPixelXY(original->getX(), original->getY(), 0, 0, 0);  
                llist->insert(ppCopy);  //Insert copied pixel
                tmp = tmp->getNext();
            }
        }
        pixelsFromNodesWithMoreOF1(nnode->getRightChild(), llist);
    }
    
    return;    
}

//Collect all pixels from nodes in the tree and insert them in an auxiliary list of pixels by using inorder traversal
void BinarySearchTree::pixelsFoundInNodes(TreeNode* nnode, SinglyLinkedList* llist)
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