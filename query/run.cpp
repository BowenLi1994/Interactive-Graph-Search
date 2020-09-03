#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>




#include "../tree/tree.h"
#include "../path-tree/path-tree.h"
#include "../others/others.h"
#include "./generator.h"



using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


int main(int argc, const char * argv[]) {
    
    // std::string filename(argv[1]);
    // std::string method(argv[2]);
    // int query_number=atoi(argv[3]);





    // std::string filepath;
    // filepath=functions::getFilePath(filename);
    // if(filename=="null")
    //     return 0;
   
    //std::cout<<filepath<<std::endl;
    std::string filepath="../dataset/singel_case1.tree";

    //parse tree
    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    bnp.parse_collection(trees_collection,filepath);

    //query
    //query::generator(trees_collection,"dis",10,"test");
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    // std::normal_distribution<tin> distribution (0,14);
    
    std::normal_distribution<double> distribution (7.0,1.0);
    std::cout<<distribution(generator)<<std::endl;

    
    

   

    


    
    return 0;
}