

#include <iostream>
#include <string>
#include <regex>
#include <vector>


#include "../tree/tree.h"
#include "../others/others.h"
#include "../path-tree/path-tree.h"
#include "../binary-search/binary_supernode.h"
#include "../query/query.h"
#include "../query/parser/query_parser.h"

#include "experiment.h"


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;
using Query=query::Query;


int main(int argc, const char * argv[]) {
    
    std::string method(argv[1]);
    std::string filename(argv[2]);
    std::string query_name(argv[3]);


    
    std::string filepath;
    filepath=functions::getFilePath(filename);
    if(filename=="null")
        return 0;
   
    //std::cout<<filepath<<std::endl;

    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    bnp.parse_collection(trees_collection,filepath);
    
    std::vector<Supernode *> supernodes_collection;
    std::string ptree_path="/home/bowen/igs_dataset/path-tree/";
    std::string ptree_name=filename+".ptree";
    parser::PathTreeParser ptp;
    ptp.parse_collection(supernodes_collection,trees_collection,ptree_path+ptree_name);


    std::string query_path="/home/bowen/igs_dataset/query/";
    std::vector<Query> query_collection;
    query_parser::parse_collection(query_collection,query_path+query_name);
    
    
    int trees_number=(int)trees_collection.size();
    int sum_cost=0;
    int sum_query=0;


    for(int i=0;i<trees_number;i++){

        std::cout<<"calculate tree: "<<i<<std::endl;

        for(auto query_id: query_collection[i].get_nodes()){

            Label target_label("target");
            Node target_node(target_label);
            target_node.set_id(query_id);
            bool found=0;
            int steps=0;
            trees_collection[i].reset_checked();

            if(method=="baseline"){
                steps=1;
                baseline::Topdown(trees_collection[i], target_node, found, steps);
               
            }


            if(method=="ordered"){                
                interleave::ordered(trees_collection[i],supernodes_collection[i],target_node,found,steps);
            }

            if(method=="outdegree"){
                std::string sThre(argv[4]);
                int threshold=std::stoi(sThre);
                adaptive::outdegree(trees_collection[i],target_node,supernodes_collection[i],found,steps,threshold);
            }

            if(method=="comprehensive"){
                std::string sThre(argv[4]);
                int threshold=std::stoi(sThre);
                adaptive::comprehensive(trees_collection[i],target_node,supernodes_collection[i],found,steps,threshold);

            }



            sum_query++;
            sum_cost+=steps;
        }

        

           


    }


    double avg_cost=(double)sum_cost/(double)sum_query;
    std::cout<<"average cost: "<<avg_cost<<std::endl;
      
      

    
    


    
    return 0;
}


