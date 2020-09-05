#pragma once

#include <vector>


#include "../tree/tree.h"
#include "../query/query.h"
#include "../query/parser/query_parser.h"

namespace log{

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Log=query::Query;


void log_analysis(std::vector<Node>& trees_collection,const std::string log_path);



void log_analysis(std::vector<Node>& trees_collection,const std::string log_path){

    //std::cout<<"log path: "<<log_path<<std::endl;

    std::vector<Log> logs_collection;
    query_parser::parse_collection(logs_collection,log_path);

    trees_collection[0].print_all_label();
    logs_collection[0].print();
    

    
}




}