#pragma once

using namespace query;

Query::Query(){


}

void Query::add_node(int id){
    
    nodes_.push_back(id);

}

std::vector<int>& Query::get_nodes(){

    return nodes_;

}

void Query::print(){
    std::cout<<"Query includes nodes: ";
    for(auto id:nodes_)
        std::cout<<id<<" ";

    std::cout<<std::endl;
}