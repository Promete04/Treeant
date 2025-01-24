#include "Core.hpp"

using namespace std::chrono;

Core::Core()
{
        //Initializes Core object.
}

Core::~Core()
{
}

void Core::boot()
{
    //Create instance of the Operation class
    Operations op;
    
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n                                  -- WELCOME TO TREEANT -- " << std::endl;
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n Introduce the name of the first image (.bmp format): "  << std::endl;
    std::string imageName1;
    
    //We have decided that the user must input the image file name with the .bmp extension
    std::cout<<" ";
    std::cin >> imageName1;
    
    TinyImageJM* myImg1= new TinyImageJM(imageName1);
    myImg1->loadImageFromDisk();
    
    // Queue to store image pixels
    QueuePixel* queuePix1 = new QueuePixel();  
    
    if (myImg1->isValid())  //If the image is valid (is .bmp)
    {
        std::cout << " Inserted image is valid. \n"<<std::endl;
    
        auto start_1st_image_queue = high_resolution_clock::now();
        
        // Load image pixels into the queue created
        for (int y=0; y<myImg1->getHeight(); y++)
        {
            for (int x=0; x<myImg1->getWidth(); x++)
            {
                
                RGBPixelXY* pp = new RGBPixelXY(x,y,1);  //Set the originFile value to 1
            
                // Pick the pixel from the image and store it in the queue
                pp->getFromRaw(myImg1->getImagePointertoInternal(),myImg1->getWidth(),myImg1->getHeight(),x,y);
                queuePix1->enqueue(pp);         
            }
        }
        
        auto end_1st_image_queue = high_resolution_clock::now();
        duration<double> elapsedTime = duration_cast<duration<double>>(end_1st_image_queue - start_1st_image_queue);
        std::cout << " Total loading time of the first image in it's queue: " << elapsedTime.count() << " seconds\n" << std::endl;
    }
    else  //If the image is not valid exit the program
        
    {
        std::cout << " Introduced image is not valid ---- "<< myImg1->getInternalError() <<std::endl;
        std::cout << " Program exiting... " << std::endl;
        std::cin.ignore();
        std::cin.get();
        return;
        
    }
    
    std::cout << "\n Introduce the name of the second image (.bmp format): "  << std::endl;
    std::string imageName2;
        
    //We have decided that the user must input the image file name with the .bmp extension
    std::cout<<" ";
    std::cin >> imageName2;
        
    TinyImageJM* myImg2= new TinyImageJM(imageName2);
    myImg2->loadImageFromDisk();
        
    //Queue to store image pixels
    QueuePixel* queuePix2 = new QueuePixel();  
        
    if (myImg2->isValid())  //If the image is valid (is .bmp)
    {
        std::cout << " Inserted image is valid. \n"<<std::endl;
            
        auto start_2nd_image_queue = high_resolution_clock::now();
        //Load image pixels into the queue created
        for (int y=0; y<myImg2->getHeight(); y++)
        {
            for (int x=0; x<myImg2->getWidth(); x++)
            {
                RGBPixelXY* pp = new RGBPixelXY(x,y,2);   //Set the originFile value to 2
                
                //Pick the pixel from the image and store it in the queue
                pp->getFromRaw(myImg2->getImagePointertoInternal(),myImg2->getWidth(),myImg2->getHeight(),x,y);
                queuePix2->enqueue(pp);         
            }
        }
            
        auto end_2nd_image_queue = high_resolution_clock::now();
        duration<double> elapsedTime = duration_cast<duration<double>>(end_2nd_image_queue - start_2nd_image_queue);
        std::cout << " Total loading time of the second image in it's queue: " << elapsedTime.count() << " seconds\n" << std::endl;
    }
         
    else  //If the image is not valid exit the program
            
    {
        std::cout << " Introduced image is not valid ---- "<< myImg2->getInternalError() <<std::endl;
        std::cout << " Program exiting... " << std::endl;
        std::cin.ignore();
        std::cin.get();
        return;
    }   
        
    std::cout << "\n ------------------------------------------------------------------------------------------ \n" << std::endl;

    auto start_phase2 = high_resolution_clock::now();
    
    auto start_1st_group = high_resolution_clock::now();
     
    auto start_1st_image_t1 = high_resolution_clock::now();
    
    BinarySearchTree* t1 = new BinarySearchTree();
    
    //Insert all pixels from queuePix1 (first image) in the binary search tree t1
    while(!queuePix1->isEmpty())
    { 
        ElemPixel* elem = queuePix1->dequeue();
        RGBPixelXY* pp = elem->getPix();
        t1->insertImg1Pixels(pp);                 //Insert image 1 pixel into t1
        delete(elem);                             //Free memory
    }
    
    auto end_1st_image_t1 = high_resolution_clock::now();
    duration<double> elapsedTime1 = duration_cast<duration<double>>(end_1st_image_t1 - start_1st_image_t1);
    std::cout << "\n Total loading time of the first image in the Binary Search Tree (T1): " << elapsedTime1.count() << " seconds\n" << std::endl;
    
    //Generate statistical data for t1 with image 1
    op.t1Img1StatisticalMeasures(t1);
    
    //Generate two lists of values: One containing rgb values that are present in the nodes of the tree
    //and the other containing rgb values that aren't present
    op.t1Img1Lists(t1);
    
    std::cout << "\n ------------------------------------------------------------------------------------------ \n" << std::endl;
    
    auto start_1st_image_t2 = high_resolution_clock::now();
    
    BinaryBalancedTree* t2 = new BinaryBalancedTree();
   
    //Transform the binary search tree into a binary balanced ordered tree containing the first image pixels
    t2->create_balance(t1->getRoot());
    
    auto end_1st_image_t2 = high_resolution_clock::now();
    duration<double> elapsedTime1_2 = duration_cast<duration<double>>(end_1st_image_t2 - start_1st_image_t2);
    std::cout << "\n Total loading time of transforming T1 with the first image into a Binary Balanced Tree (T2): " << elapsedTime1_2.count() << " seconds\n" << std::endl;
    
    //Generates statistical data for t2 with image 1
    op.t2Img1StatisticalMeasures(t2);

    auto end_1st_group = high_resolution_clock::now();
    duration<double> elapsedTime2 = duration_cast<duration<double>>(end_1st_group - start_1st_group);
    std::cout << "\n Total time for performing group 1 operations: " << elapsedTime2.count() << " seconds" << std::endl;
    
    std::cout << "\n\n ------------------------------------------------------------------------------------------ " << std::endl;
    
    auto start_2nd_group = high_resolution_clock::now();
    
    //Make a copy of the queue containing the second image to not modify the original pixels
    QueuePixel* copiedQueue2 = queuePix2->copyQueue();
    
    auto start_2nd_image_t1 = high_resolution_clock::now();
    
    //Insert all the pixels from the second image that have a sumRgb value that already exists in some node into t1
    while(!queuePix2->isEmpty())
    {
        ElemPixel* elem = queuePix2->dequeue();
        RGBPixelXY* pp = elem->getPix();
        t1->insertImg2Pixels(pp);         //Insert image 2 pixel into t1
        delete(elem);                     //Free memory
    }
    
    auto end_2nd_image_t1 = high_resolution_clock::now();
    duration<double> elapsedTime3 = duration_cast<duration<double>>(end_2nd_image_t1 - start_2nd_image_t1);
    std::cout << "\n\n Total loading time of the second image in the Binary Search Tree (T1): " << elapsedTime3.count() << " seconds\n" << std::endl;

    //Generate statistical data for t1 with images 1 and 2
    op.t1Img1Img2StatisticalMeasures(t1);

    std::cout << "\n ------------------------------------------------------------------------------------------ \n" << std::endl;
    
    auto start_2nd_image_t2 = high_resolution_clock::now();
    
      
    //Insert all the pixels from the second image that have a sumRgb value that already exists in some node into t2
    //A copy of the original queuePix2 is used since queuePix2 is empty after inserting the pixels in t1
    while(!copiedQueue2->isEmpty())
    {
        ElemPixel* elem = copiedQueue2->dequeue();
        RGBPixelXY* pp = elem->getPix();
        t2->insertImg2Pixels(pp);              //Insert image 2 pixel into t2
        delete(elem);                          //Free memory
    }
    
    auto end_2nd_image_t2 = high_resolution_clock::now();
    duration<double> elapsedTime3_2 = duration_cast<duration<double>>(end_2nd_image_t2 - start_2nd_image_t2);
    std::cout << "\n Total loading time of the second image in the Binary Balanced Tree (T2): " << elapsedTime3_2.count() << " seconds\n" << std::endl;

    //Generate statistical data for t2 with images 1 and 2
    op.t2Img1Img2StatisticalMeasures(t2);


    auto end_2nd_group = high_resolution_clock::now();
    duration<double> elapsedTime4 = duration_cast<duration<double>>(end_2nd_group - start_2nd_group);
    std::cout << "\n Total time for performing group 2 operations: " << elapsedTime4.count() << " seconds\n" << std::endl;
    
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// \n" << std::endl;
    std::cout << "                               GENERATING OUTPUT IMAGES" << std::endl;
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// \n" << std::endl;
    
    auto start_3rd_group = high_resolution_clock::now();
    
    //Generate outputs images
    op.Output1(t1, myImg1);
    op.Output2(t1, myImg2);
    op.Output3(t2, myImg2);
    
    auto end_3rd_group = high_resolution_clock::now();
    duration<double> elapsedTime5 = duration_cast<duration<double>>(end_3rd_group - start_3rd_group);
    std::cout << "\n Total time for performing group 3 operations: " << elapsedTime5.count() << " seconds\n" << std::endl;
    
    std::cout << "\n\n Deallocating memory..." <<std::endl;
    
    //Clean up dynamically allocated memory
    delete(queuePix1);
    delete(queuePix2);
    delete(copiedQueue2);
    delete(myImg1);
    delete(myImg2);
    delete(t1);
    delete(t2);
    
    auto end_phase2 = high_resolution_clock::now();
    duration<double> elapsedTimePhase2 = duration_cast<duration<double>>(end_phase2 - start_phase2);
    std::cout << "\n\n Total phase 2 time: " << elapsedTimePhase2.count() << " seconds\n" << std::endl;
    
    std::cout << "\n ////////////////////////////////////////////////////////////////////////////////////////// " << std::endl;
    std::cout << "\n Finished processing, check output folder. You may close the program now." <<std::endl;
    std::cin.ignore();     //Ignores pressing "enter" for closing the program until the end.
    std::cin.get();        //Closes program if press "enter".
}
