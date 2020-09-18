#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>




#include "../../tree/tree.h"
#include "../../path-tree/path-tree.h"
#include "../../others/functions.h"
#include "../../query/query.h"
#include "../../query/parser/query_parser.h"
#include "../../log/log.h"



using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;
using Log=query::Query;


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

    //trees_collection[0].print_all_label();

    if(argc==2){
        std::vector<Supernode *> supernodes_collection;
        path_tree_generator::heavy_path_trees_collection_generator(trees_collection, supernodes_collection);

        std::vector<std::string> paths_files;
        path_tree_file::generator(supernodes_collection, paths_files);

    
        std::string outfile_path="/home/bowen/igs_dataset/path-tree/";
        std::string outfile_name=filename+".ptree";
        functions::WriteFile(outfile_path+outfile_name, paths_files);
    }

    std::string log_name;
    std::string log_path;
    if(argc==3){
        log_name=std::string(argv[2]);
        log_path="/home/bowen/igs_dataset/log/";
        // std::vector<Log> logs_collection;
        // query_parser::parse_collection(logs_collection,log_path+log_name+".log");

        log_file::log_analysis(trees_collection,log_path+log_name+".log");

        std::vector<Supernode *> ftrees_collection;
        frequency_tree_generator::frequency_trees_collection_generator(trees_collection,ftrees_collection);

        //ftrees_collection[0]->print_heay_tree();

        std::vector<std::string> paths_files;
        path_tree_file::generator(ftrees_collection, paths_files);

        
        std::string outfile_path="/home/bowen/igs_dataset/frequency-tree/";
        std::string outfile_name=log_name+".ftree";
        functions::WriteFile(outfile_path+outfile_name, paths_files);



        

    }

   

    


    
    return 0;
}


