#include "Operations.hpp"

using namespace std::chrono;

//Constructor
Operations::Operations()
{
}

//Destructor
Operations::~Operations()
{
}

//Generate statistical data for t1 with image 1
void Operations::t1Img1StatisticalMeasures(BinarySearchTree* t1)
{
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n                     TREE T1 WITH IMAGE 1 STATISTICAL MEASURES " << std::endl;
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    
    auto start_t1_max_tree_depth = high_resolution_clock::now();
    
    //Print maximum depth of the tree which is equivalent to the height of the root 
    std::cout <<"\n\n Maximum tree depth (T1): "<< t1->nodeHeight(t1->getRoot()) << std::endl;
    
    auto end_t1_max_tree_depth = high_resolution_clock::now();
    duration<double> elapsedTime1 = duration_cast<duration<double>>(end_t1_max_tree_depth - start_t1_max_tree_depth);
    std::cout << "\n Total time for obtaining the maximum tree depth: " << elapsedTime1.count() << " seconds\n" << std::endl;
    
    
    int largestSize = 0;
    TreeNode* largestNode = nullptr;
    
    auto start_t1_biggest_node = high_resolution_clock::now();
    
    //Print the node with the largest number of pixels
    t1->biggestNode(t1->getRoot(),largestNode,largestSize);
    std::cout <<"\n The node with the largest number of pixels is the one associated with the rgb sum: " << largestNode->getSumRGB() << ", with " << largestSize << " pixels. " << std::endl;
    
    auto end_t1_biggest_node = high_resolution_clock::now();
    duration<double> elapsedTime2 = duration_cast<duration<double>>(end_t1_biggest_node - start_t1_biggest_node);
    std::cout << "\n Total time for obtaining the node with the most pixels: " << elapsedTime2.count() << " seconds\n" << std::endl;
}

//Generate two lists of values: One containing rgb values that are present in the nodes of the tree
//and the other containing rgb values that aren't present
void Operations::t1Img1Lists(BinarySearchTree* t1)
{
    auto start_t1_list1 = high_resolution_clock::now();
    
    SumRGBList* slist = new SumRGBList();          //Auxiliar list of sumRgb values 
    t1->obtainSumRGBInNodes(t1->getRoot(), slist); //Insert all sumRgb values found in the tree nodes into the list
    SumRGBListNode* tmp = slist->getHeader();      //Auxiliar pointer to the header of the auxiliar list
    
    std::cout << "\n Values from 0 to 765 that have a node in tree (T1): " << std::endl;
    
    //Iterate through the auxiliar list printing all sumRgb values collected
    while(tmp != nullptr)
    {
        std::cout << " | " << tmp->getValue();
        tmp = tmp->getNext();
    }
    
    auto end_t1_list1 = high_resolution_clock::now();
    duration<double> elapsedTime1 = duration_cast<duration<double>>(end_t1_list1 - start_t1_list1);
    std::cout << "\n\n Total time for obtaining sumRGB values that have a node in the tree: " << elapsedTime1.count() << " seconds\n" << std::endl;
    
    //Update tmp to point to the header of the auxiliar list again
    tmp = slist->getHeader();
    
    std::cout << "\n Values from 0 to 765 that doesn't have a node in tree (T1): " << std::endl;
    std::cout << "| ";
    
    auto start_t1_list2 = high_resolution_clock::now();
    
    //Iterate while the auxiliar pointer is not null and its next pointer isn't null neither (tmp is the last element so we can't compare anymore)
    while (tmp != nullptr && tmp->getNext() != nullptr) 
    {
        int value1 = tmp->getValue();            //Variable to store the tmp's value
        int value2 = tmp->getNext()->getValue(); //Variable to store tmp next's value

        if (value2 > value1) //Find a gap between consecutive sumRgb values in the list
        {
            int difference = value2 - value1;  //Obtain the difference between both values

            for (int i = 1; i < difference; i++)  //Print all the missing values in the gap
            {
                std::cout << value1 + i << " | ";
            }
        }
        tmp = tmp->getNext(); 
    }
    
    //If there are still missing values after the last value in the list
    if (tmp != nullptr) 
    {
        int lastValue = tmp->getValue();
        
        for (int i = lastValue + 1; i <= 765; i++) //Print all the missing values until reach 765
        {
            std::cout << i << " | ";
        }
    }
    
    auto end_t1_list2 = high_resolution_clock::now();
    duration<double> elapsedTime2 = duration_cast<duration<double>>(end_t1_list2 - start_t1_list2);
    std::cout << "\n\n Total time for obtaining sumRGB values that doesn't have a node in the tree: " << elapsedTime2.count() << " seconds\n" << std::endl;
    
    //Clean up dinamically allocated memory
    delete(slist);
}

//Generates statistical data for t2 with image 1
void Operations::t2Img1StatisticalMeasures(BinaryBalancedTree* t2)
{
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n                     TREE T2 WITH IMAGE 1 STATISTICAL MEASURES " << std::endl;
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    
    auto start_t2_img1_max_tree_depth = high_resolution_clock::now();
    
    //Print maximum depth of the tree which is equivalent to the height of the root 
    std::cout <<"\n\n Maximum tree depth (T2): "<< t2->nodeHeight(t2->getRoot()) << std::endl;
    
    auto end_t2_img1_max_tree_depth = high_resolution_clock::now();
    duration<double> elapsedTime1 = duration_cast<duration<double>>(end_t2_img1_max_tree_depth - start_t2_img1_max_tree_depth);
    std::cout << "\n Total time for obtaining the maximum tree depth: " << elapsedTime1.count() << " seconds\n" << std::endl;
    
    int largestSize = 0;
    TreeNode* largestNode = nullptr;
    
    auto start_t2_img1_biggest_node = high_resolution_clock::now();
    
    //Print the node with the largest number of pixels
    t2->biggestNode(t2->getRoot(),largestNode,largestSize);
    std::cout <<"\n The node with the largest number of pixels is the one associated with the rgb sum: " << largestNode->getSumRGB() << ", with " << largestSize << " pixels. " << std::endl;
    
    auto end_t2_img1_biggest_node = high_resolution_clock::now();
    duration<double> elapsedTime2 = duration_cast<duration<double>>(end_t2_img1_biggest_node - start_t2_img1_biggest_node);
    std::cout << "\n Total time for obtaining the node with the most pixels: " << elapsedTime2.count() << " seconds\n" << std::endl;
}

//Generate statistical data for t1 with images 1 and 2
void Operations::t1Img1Img2StatisticalMeasures(BinarySearchTree* t1)
{
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n                     TREE T1 WITH IMAGES 1 AND 2 STATISTICAL MEASURES " << std::endl;
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    
    auto start_t1_img2_max_tree_depth = high_resolution_clock::now();
    
    //Print maximum depth of the tree which is equivalent to the height of the root 
    std::cout <<"\n\n Maximum tree depth (T1): "<< t1->nodeHeight(t1->getRoot()) << std::endl;
    
    auto end_t1_img2_max_tree_depth = high_resolution_clock::now();
    duration<double> elapsedTime1 = duration_cast<duration<double>>(end_t1_img2_max_tree_depth - start_t1_img2_max_tree_depth);
    std::cout << "\n Total time for obtaining the maximum tree depth: " << elapsedTime1.count() << " seconds\n" << std::endl;
    
    
    int largestSize = 0;
    TreeNode* largestNode = nullptr;
    
    auto start_t1_img2_biggest_node = high_resolution_clock::now();
    
    //Print the node with the largest number of pixels
    t1->biggestNode(t1->getRoot(),largestNode,largestSize);
    std::cout <<"\n The node with the largest number of pixels is the one associated with the rgb sum: " << largestNode->getSumRGB() << ", with " << largestSize << " pixels. " << std::endl;
    
    auto end_t1_img2_biggest_node = high_resolution_clock::now();
    duration<double> elapsedTime2 = duration_cast<duration<double>>(end_t1_img2_biggest_node - start_t1_img2_biggest_node);
    std::cout << "\n Total time for obtaining the node with the most pixels: " << elapsedTime2.count() << " seconds\n" << std::endl;
    
}

//Generates statistical data for t2 with images 1 and 2
void Operations::t2Img1Img2StatisticalMeasures(BinaryBalancedTree* t2)
{
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n                     TREE T2 WITH IMAGES 1 AND 2 STATISTICAL MEASURES " << std::endl;
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    
    auto start_t2_img2_max_tree_depth = high_resolution_clock::now();
    
    //Print maximum depth of the tree which is equivalent to the height of the root 
    std::cout <<"\n\n Maximum tree depth (T2): "<< t2->nodeHeight(t2->getRoot()) << std::endl;
    
    auto end_t2_img2_max_tree_depth = high_resolution_clock::now();
    duration<double> elapsedTime1 = duration_cast<duration<double>>(end_t2_img2_max_tree_depth - start_t2_img2_max_tree_depth);
    std::cout << "\n Total time for obtaining the maximum tree depth: " << elapsedTime1.count() << " seconds\n" << std::endl;
    
    int largestSize = 0;
    TreeNode* largestNode = nullptr;
    
    auto start_t2_img2_biggest_node = high_resolution_clock::now();
    
    //Print the node with the largest number of pixels
    t2->biggestNode(t2->getRoot(),largestNode,largestSize);
    std::cout <<"\n The node with the largest number of pixels is the one associated with the rgb sum: " << largestNode->getSumRGB() << ", with " << largestSize << " pixels. " << std::endl;
    
    auto end_t2_img2_biggest_node = high_resolution_clock::now();
    duration<double> elapsedTime2 = duration_cast<duration<double>>(end_t2_img2_biggest_node - start_t2_img2_biggest_node);
    std::cout << "\n Total time for obtaining the node with the most pixels: " << elapsedTime2.count() << " seconds\n" << std::endl;
}

//Generate the first output image based on tree t1, containing all pixels from nodes where there are
//more pixels with originFile 1 than originFile 2, and containing all pixels from other nodes
//that doesn't meet this criteria but set to black color
//The image will have the same dimensions as the first image introduced in the program
void Operations::Output1(BinarySearchTree* t1, TinyImageJM* myImg1)
{
    auto start_img1_output = high_resolution_clock::now();
    
    unsigned char* newImage;  //Allocate memory for the new image which will have the same dimensions as the first image introduced
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg1->getHeight() * myImg1->getWidth() * 3);
    
    SinglyLinkedList* llist1 = new SinglyLinkedList();  //Auxiliar list to store pixels
    
    //Populate the auxiliar list with all the pixels from the nodes where there are more pixels with originFile 1
    //than originFile 2 and the pixels from other nodes as black pixels
    t1->pixelsFromNodesWithMoreOF1(t1->getRoot(), llist1);
    
    ElemPixel* tmp = llist1->getHeader();  //Auxiliar pointer to the header of the auxiliar list
    
    //Iterate through the auxiliar list of pixels placing all the pixels in the output image
    while(tmp != nullptr)
    {
        RGBPixelXY* pp = tmp->getPix();       
        pp->setIntoRaw(newImage,myImg1->getWidth(),myImg1->getHeight(),pp->getX(),pp->getY());  
        tmp = tmp->getNext();  
    }
     
    myImg1->setNewImagePointerWithOldRemoval(newImage, myImg1->getWidth(), myImg1->getHeight());
    myImg1->saveImageToDisk("Output1.bmp");
    
    auto end_img1_output = high_resolution_clock::now();
    duration<double> elapsedTime = duration_cast<duration<double>>(end_img1_output - start_img1_output);
    std::cout << "\n Total time for obtaining first output image: " << elapsedTime.count() << " seconds\n" << std::endl;
    
    delete(llist1); //Clean up memory
}

//Generate the second output image based on tree t1, containing all pixels from its nodes
//If a pixel is missing from both input images at a specific coordinate (no pixel in the tree 
//corresponds to that coordinate), the output image will display a black pixel at that position 
//The image will have the same dimensions as the second image introduced in the program
void Operations::Output2(BinarySearchTree* t1, TinyImageJM* myImg2)
{
    auto start_img2_output1 = high_resolution_clock::now();
    
    unsigned char* newImage;   //Allocate memory for the new image which will have the same dimensions as the second image introduced    
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg2->getHeight() * myImg2->getWidth() * 3);
    
    SinglyLinkedList* llist2 = new SinglyLinkedList();  //Auxiliar list to store pixels 
    
    t1->pixelsFoundInNodes(t1->getRoot(), llist2); //Populate the auxiliar list with all the pixels from the tree nodes
    
    ElemPixel* tmp = llist2->getHeader();  //Auxiliar pointer to the header of the auxiliar list
    
    //Iterate through the auxiliar list of pixels placing all the pixels in the output image
    while(tmp != nullptr)
    {
        RGBPixelXY* pp = tmp->getPix();
        pp->setIntoRaw(newImage,myImg2->getWidth(),myImg2->getHeight(),pp->getX(),pp->getY());
        tmp = tmp->getNext();
    }
     
    myImg2->setNewImagePointerWithOldRemoval(newImage, myImg2->getWidth(), myImg2->getHeight());
    myImg2->saveImageToDisk("Output2.bmp");
    
    auto end_img2_output1 = high_resolution_clock::now();
    duration<double> elapsedTime = duration_cast<duration<double>>(end_img2_output1 - start_img2_output1);
    std::cout << "\n Total time for obtaining second output image: " << elapsedTime.count() << " seconds\n" << std::endl;
    
    delete(llist2);  //Clean up memory
}

//Generate the third output image based on tree t2, containing all pixels from its nodes
//If a pixel is missing from both input images at a specific coordinate (no pixel in the tree 
//corresponds to that coordinate), the output image will display a black pixel at that position
//The image will have the same dimensions as the second image introduced in the program
void Operations::Output3(BinaryBalancedTree* t2, TinyImageJM* myImg2)
{
    auto start_img2_output2 = high_resolution_clock::now();
    
    unsigned char* newImage;    //Allocate memory for the new image which will have the same dimensions as the second image introduced      
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg2->getHeight() * myImg2->getWidth() * 3);
    
    SinglyLinkedList* llist3 = new SinglyLinkedList(); //Auxiliar list to store pixels 
    
    t2->pixelsFoundInNodes(t2->getRoot(), llist3);  //Populate the auxiliar list with all the pixels from the tree nodes
    
    ElemPixel* tmp = llist3->getHeader();  //Auxiliar pointer to the header of the auxiliar list
    
    //Iterate through the auxiliar list of pixels placing all the pixels in the output image
    while(tmp != nullptr)
    {
        RGBPixelXY* pp = tmp->getPix();
        pp->setIntoRaw(newImage,myImg2->getWidth(),myImg2->getHeight(),pp->getX(),pp->getY());
        tmp = tmp->getNext();
    }
     
    myImg2->setNewImagePointerWithOldRemoval(newImage, myImg2->getWidth(), myImg2->getHeight());
    myImg2->saveImageToDisk("Output3.bmp");
    
    auto end_img2_output2 = high_resolution_clock::now();
    duration<double> elapsedTime = duration_cast<duration<double>>(end_img2_output2 - start_img2_output2);
    std::cout << "\n Total time for obtaining third output image: " << elapsedTime.count() << " seconds\n" << std::endl;
    
    delete(llist3);   //Clean up memory
}

