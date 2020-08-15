

#include <iostream>
#include <string>
#include <regex>
#include <vector>


#include "../../Interactive Graph Search/tree/tree.h"
#include "../../Interactive Graph Search/baseline/baseline.h"
#include "../../Interactive Graph Search/others/reachability.h"
#include "../../Interactive Graph Search/path-tree/super_node/supernode.h"
#include "../../Interactive Graph Search/path-tree/generator/path_tree_generator.h"
#include "../../Interactive Graph Search/binary-search/binary_supernode.h"
#include "../../Interactive Graph Search/interleave/interleave_ordered.h"
#include "../../Interactive Graph Search/adaptive/adaptive.h"
#include "../../Interactive Graph Search/others/functions.h"


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


int main(int argc, const char * argv[]) {
    
    std::string method(argv[1]);
    std::string filename(argv[2]);

//    std::string filename="a";
//    std::string method="1";
    
    std::string filepath;
    filepath=functions::getFilePath(filename);
    if(filename=="null")
        return 0;
    
    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    //bnp.parse_collection(trees_collection,filepath);
    
    std::vector<Supernode *> supernodes_collection;
    path_tree_generator::heavy_path_trees_collection_generator(trees_collection, supernodes_collection);
    
    int trees_number=(int)trees_collection.size();
    std::map<int, std::pair<int, int>> total_depth_step;
    
    for(int i=0;i<trees_number;i++){
        int tree_size=trees_collection[i].get_tree_size();
        int total_steps=0;
        std::map<int, std::pair<int, int>> tree_depth_step;
        for(int j=0;j<tree_size;j++){
            Label target_label("target");
            Node target_node(target_label);
            target_node.set_id(j);
            bool found=0;
            int steps=0;
            if(method=="baseline"){
                steps=1;
                baseline::Topdown(trees_collection[i], target_node, found, steps);
               
            }
            
            total_steps+=steps;
            std::map<int, std::pair<int, int>>::iterator it;
            it=tree_depth_step.find(target_node.depth());
            if(it!=tree_depth_step.end()){
                it->second.first+=steps;
                it->second.second++;
            }
            else
                tree_depth_step.emplace(target_node.depth(),std::make_pair(steps, 1));

            it=total_depth_step.find(target_node.depth());
            if(it!=total_depth_step.end()){
                it->second.first+=steps;
                it->second.second++;
            }
            else
                total_depth_step.emplace(target_node.depth(),std::make_pair(steps, 1));
            }

//            for(auto map:tree_depth_step){
//                int average=map.second.first/map.second.second;
//                std::cout<<"depth: "<<map.first<<" number of nodes: "<<map.second.second<<" average steps: "<<average<<std::endl;
//            }
        }
        std::cout<<"Final analysis"<<std::endl;
        for(auto map:total_depth_step){
            int average=map.second.first/map.second.second;
            std::cout<<"depth: "<<map.first<<" number of nodes: "<<map.second.second<<" average steps: "<<average<<std::endl;
        }

    
    


    
    return 0;
}


