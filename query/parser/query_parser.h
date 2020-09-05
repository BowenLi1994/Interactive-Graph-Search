#pragma once

#include "../query.h"
#include "../../others/others.h"
#include <vector>
#include <string>
#include <fstream>

namespace query_parser{

    using Query=query::Query;

    Query parse_single(const std::string query_string);
    void parse_collection(std::vector<Query>& query_collection,const std::string file_path);


    Query parse_single(const std::string query_string){

        Query q;
        std::vector<std::string> tokens;
        functions::SplitString(query_string,tokens,"-");

        for(auto t:tokens)
            q.add_node(std::stoi(t));

        return q;
    }

    void parse_collection(std::vector<Query>& query_collection,const std::string file_path){
        
        std::ifstream query_file(file_path);
        if (!query_file) {
            throw std::runtime_error("ERROR: Problem with opening the file '" + file_path + "' in query_parser::parse_collection.");
        }
        // Read the trees line by line, parse, and move into the container.
        int query_counter=0;
        std::string query_string;
        while(std::getline(query_file, query_string)){
   
            std::cout<<"parse query:"<<query_counter<<std::endl;
            query_collection.push_back(parse_single(query_string)); // -> This invokes a move constructor (due to push_back(<rvalue>)).
            query_counter++;
        }
        query_file.close();
    }


}
