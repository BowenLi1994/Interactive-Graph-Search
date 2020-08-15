#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "subset.h"
#include "combine.h"
#include "../others/functions.h"
#include "../tree/tree.h"

int main(int argc, const char * argv[]) {
    
    
    using Label=label::StringLabel;
    using Node=node::Node<Label>;

    if(argc!=4){
        std::cout<<"Wrong argument!"<<std::endl;
        return 0;
    }
    
    std::string method(argv[1]);
    std::string filename(argv[2]);
    std::string tree_value(argv[3]);
    int trees_number=std::stoi(tree_value);
    
    //std::string filepath=functions::getFilePath(filename);
    
 
    
    if(method=="combine"){
        combine(filename, trees_number);
    }
    
    
    
    


    return 0;
}
