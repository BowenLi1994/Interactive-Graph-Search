#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "subset.h"
#include "combine.h"
#include "concatnate.h"
#include "../others/functions.h"
#include "../tree/tree.h"
#include "fake_node.h"

int main(int argc, const char * argv[]) {
    
    
    //using Label=label::StringLabel;
    //using Node=node::Node<Label>;

    // if(argc!=4 && argc!=3){
    //     std::cout<<"Wrong argument!"<<std::endl;
    //     return 0;
    // }

    std::string method(argv[1]);
    std::string filename(argv[2]);
    std::string tree_value;
    int trees_number=0;

    if(argc==4){
        tree_value=std::string(argv[3]);
        trees_number=std::stoi(tree_value);
    }
  

    //std::string filepath=functions::getFilePath(filename);



    if(method=="combine"){
        combine(filename, trees_number);
    }

    else if(method=="concatnate"){
        concatnate(filename, trees_number);
    }

    else if (method=="subset"){

        subset(filename,trees_number);
        
    }
    else if (method=="fake_node"){
        
        fake_node(filename);
    }
    else
    {
        std::cout<<"wrong methods"<<std::endl;
    }
    
    

    
    
    
    
    
    


    return 0;
}
