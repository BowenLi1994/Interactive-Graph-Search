#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>




#include "../../tree/tree.h"
#include "../../path-tree/path-tree.h"
#include "../../others/functions.h"



using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


int main(int argc, const char * argv[]) {
    
       std::string filename(argv[1]);

    std::string filepath;
    filepath=functions::getFilePath(filename);
    if(filename=="null")
        return 0;
   
    std::cout<<filepath<<std::endl;
    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    bnp.parse_collection(trees_collection,filepath);

    std::vector<Supernode *> supernodes_collection;
    path_tree_generator::heavy_path_trees_collection_generator(trees_collection, supernodes_collection);

    std::vector<std::string> paths_files;
    path_tree_file::generator(supernodes_collection, paths_files);

    
    std::string outfile_path="/home/bowen/igs_dataset/path-tree/";
    std::string outfile_name=filename+".ptree";
    functions::WriteFile(outfile_path+outfile_name, paths_files);

   

    


    
    return 0;
}


