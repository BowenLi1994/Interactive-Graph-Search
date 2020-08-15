#pragma once

#include <string>
#include <iostream>
#include <map>
#include "../others/functions.h"

int  subset(std::string filename, int trees_number) {
    
    //std::cout<<"Hello"<<std::endl;
    
    std::string filepath=functions::getFilePath(filename);
    if(filepath=="NULL")
        return 0;

    

    std::ifstream infile;
    std::ofstream outfile;
    
    //open file
    int trees_counter=0;
    
    infile.open(filepath);
    if(!infile.is_open()){
        std::cout<<"cannot open the file: "<<filename<<std::endl;
        return 0;
    }
   
    std::string outfile_filepath="/home/bowen/igs_dataset/amazon/manual/";
    std::string outfile_filename=filename+std::to_string(trees_number)+".tree";
    std::cout<<outfile_filename<<std::endl;
    outfile.open(outfile_filepath+outfile_filename);
    if(!outfile.is_open()){
        std::cout<<"cannot open the file: "<<outfile_filename<<std::endl;
    }
    
    std::string trees_string;
    while (std::getline(infile,trees_string) && trees_counter<trees_number) {
        
        outfile<<trees_string;
        outfile<<"\n";
        trees_counter++;
        
    }
    
    infile.close();
    outfile.close();



    return 0;
    
}
