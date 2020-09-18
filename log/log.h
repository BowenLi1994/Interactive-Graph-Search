#pragma once

#include <vector>


#include "../tree/tree.h"
#include "../query/query.h"
#include "../query/parser/query_parser.h"

namespace log_file{

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Log=query::Query;


void log_analysis(std::vector<Node>& trees_collection,const std::string log_path);



void log_analysis(std::vector<Node>& trees_collection,const std::string log_path){

    //std::cout<<"log path: "<<log_path<<std::endl;

    std::vector<Log> logs_collection;
    query_parser::parse_collection(logs_collection,log_path);

    // logs_collection[0].print();
    // for(auto& node: trees_collection[0].get_all_nodes()){
    //     std::cout<<"node: "<<node->id()<<" depth: "<<node->depth()<<std::endl;
    // }

    int log_counter=0;

    for(auto &tree:trees_collection){

        std::vector<Node*> nodes_set;
        tree.traverse_tree(nodes_set);
        std::cout<<"generate log: "<<log_counter<<std::endl;
        for(auto log: logs_collection[log_counter].get_nodes()){
            nodes_set[log]->add_frequency();
        }
      
        log_counter++;

    }

    //trees_collection[0].print_all_label();

    // for(auto& tree:trees_collection)
    //     tree.pre_prosseing(tree.get_all_nodes());


    // 
    


    

    
}




}