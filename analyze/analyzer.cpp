
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "analyzer.h"

#include "../tree/tree.h"

#include "../others/functions.h"


int main(int argc, const char * argv[]) {
    
    using Label=label::StringLabel;
    using Node=node::Node<Label>;

    if(argc!=2){
        std::cout<<"Wrong argument!"<<std::endl;
        return 0;
    }
//
    std::string filename(argv[1]);
    
    std::string filepath=functions::getFilePath(filename);
    
    if(filepath=="null")
        return 0;
    
    parser::BracketNotationParser bnp;
    std::vector<Node> trees_collection;
    //std::string filepath="/Users/brandonli/Desktop/Interactive Graph Search/dataset/bolzano.tree";
    bnp.parse_collection(trees_collection,filepath);
    analyzer::analyze_result result;
    result=analyzer::analyze(trees_collection);
    analyzer::print_anylyze_result(result);
    
    return 0;
}
