#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "subset.h"
#include "combine.h"
#include "../others/functions.h"


int main(int argc, const char * argv[]) {
    
    
    //std::string file_path=functions::getFilePath("All");
    //std::cout<<"filepath: "<<file_path<<std::endl;
    
    combine("hello", 100);

    //std::string method_name(argv[1]);


//   if(method_name=="subset"){
//
//        std::string filename(argv[2]);
//        int trees_number=atoi(argv[3]);
//        subset(filename,trees_number);
//
//
//
//    }
//
//   else if(method_name=="combine"){
//
//       std::string filename(argv[2]);
//       int trees_number=atoi(argv[3]);
//
//       combine(filename,trees_number);
//   }



    return 0;
}
