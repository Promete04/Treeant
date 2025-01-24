#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include "BinarySearchTree.hpp"

#include "BinaryBalancedTree.hpp"

#include "SumRGBList.hpp"

#include "peque-image-manager/TinyImageJM.hpp"

#include <chrono>

#include <string>

class Operations
{
public:
   Operations();   //Constructor
    ~Operations(); //Destructor
    
    void t1Img1StatisticalMeasures(BinarySearchTree* tree);   //Generate statistical data for t1 with image 1
    
    //Generate two lists of values: One containing rgb values that are present in the nodes of the tree
    //and the other containing rgb values that aren't present
    void t1Img1Lists(BinarySearchTree* tree); 
    void t1Img1Img2StatisticalMeasures(BinarySearchTree* tree);   //Generate statistical data for t1 with images 1 and 2

    void t2Img1StatisticalMeasures(BinaryBalancedTree* tree);     //Generates statistical data for t2 with image 1
    void t2Img1Img2StatisticalMeasures(BinaryBalancedTree* tree); //Generates statistical data for t2 with images 1 and 2
    
    void Output1(BinarySearchTree* tree, TinyImageJM* myImg);    //Generate output image 1
    void Output2(BinarySearchTree* tree, TinyImageJM* myImg);    //Generate output image 2
    void Output3(BinaryBalancedTree* tree, TinyImageJM* myImg);  //Generate output image 3
};

#endif // OPERATIONS_HPP
