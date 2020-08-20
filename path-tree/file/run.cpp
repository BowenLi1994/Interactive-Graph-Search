#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>




#include "../../tree/tree.h"
#include "../../path-tree/super_node/supernode.h"
#include "../../path-tree/generator/path_tree_generator.h"
#include "../../others/functions.h"
#include "./generator.h"
#include "../../others/functions.h"
#include "../../path-tree/parser/path_tree_parser.h"


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


int main(int argc, const char * argv[]) {
    
    //std::string method(argv[1]);
    //std::string filename(argv[1]);

    //std::string filename="a";
//    std::string method="1";
    
    std::string filepath;
//    filepath=functions::getFilePath(filename);
//    if(filename=="null")
//        return 0;
//
    filepath="/Users/brandonli/Desktop/Interactive Graph Search/dataset/bolzano.tree";
   
    std::cout<<filepath<<std::endl;
    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    bnp.parse_collection(trees_collection,filepath);
//
    std::vector<Supernode *> supernodes_collection;
    path_tree_generator::heavy_path_trees_collection_generator(trees_collection, supernodes_collection);

//    std::vector<std::string> paths_files;
//    path_tree_file::generator(supernodes_collection, paths_files);
//
    std::string outfile_path="/Users/brandonli/Desktop/result.txt";
//    //functions::WriteFile(outfile_path, paths_files);
//
    std::vector<Supernode *> supernodes_collection_temp;
//
    parser::PathTreeParser ptp;
    ptp.parse_collection(supernodes_collection_temp, outfile_path);
    

    
    
    
    for(int i=0;i<299;i++){
        //supernodes_collection[i]->print_heay_tree();
        supernodes_collection_temp[i]->print_heay_tree();
        //std::cout<<"*********************************"<<std::endl;
    }

    
    
    //functions::WriteFile(outfile_path, paths_files);
    
    
//    for(auto string: paths_files)
//        std::cout<<string<<std::endl;
    
    //std::ofstream outfile;
    
    

    
    
    
    

    
    
//
//    int trees_number=(int)trees_collection.size();
//    std::map<int, std::pair<int, int>> total_depth_step;
//
//    for(int i=0;i<trees_number;i++){
//        int tree_size=trees_collection[i].get_tree_size();
//        int total_steps=0;
//        std::map<int, std::pair<int, int>> tree_depth_step;
//        for(int j=0;j<tree_size;j++){
//            Label target_label("target");
//            Node target_node(target_label);
//            target_node.set_id(j);
//            bool found=0;
//            int steps=0;
//            if(method=="baseline"){
//                steps=1;
//                baseline::Topdown(trees_collection[i], target_node, found, steps);
//
//            }
//            if(method=="ordered"){
//                interleave::ordered(trees_collection[i],supernodes_collection[i],target_node,found,steps);
//            }
//
//            if(method=="outdegree"){
//                std::string sThre(argv[3]);
//                int threshold=std::stoi(sThre);
//                trees_collection[i].reset_checked();
//                adaptive::outdegree(trees_collection[i],target_node,supernodes_collection[i],found,steps,threshold);
//            }
//
//
//            if(method=="sibling"){
//                std::string sThre(argv[3]);
//                int threshold=std::stoi(sThre);
//                trees_collection[i].reset_checked();
//                adaptive::sibling(trees_collection[i],target_node,supernodes_collection[i],found,steps,threshold);
//            }
//
//            if(method=="comprehensive"){
//                std::string sThre(argv[3]);
//                int threshold=std::stoi(sThre);
//                trees_collection[i].reset_checked();
//                adaptive::comprehensive(trees_collection[i],target_node,supernodes_collection[i],found,steps,threshold);
//            }
//
//            total_steps+=steps;
//            std::map<int, std::pair<int, int>>::iterator it;
//            it=tree_depth_step.find(target_node.depth());
//            if(it!=tree_depth_step.end()){
//                it->second.first+=steps;
//                it->second.second++;
//            }
//            else
//                tree_depth_step.emplace(target_node.depth(),std::make_pair(steps, 1));
//
//            it=total_depth_step.find(target_node.depth());
//            if(it!=total_depth_step.end()){
//                it->second.first+=steps;
//                it->second.second++;
//            }
//            else
//                total_depth_step.emplace(target_node.depth(),std::make_pair(steps, 1));
//            }
//
////            for(auto map:tree_depth_step){
////                int average=map.second.first/map.second.second;
////                std::cout<<"depth: "<<map.first<<" number of nodes: "<<map.second.second<<" average steps: "<<average<<std::endl;
////            }
//        }
//        std::cout<<"Final analysis"<<std::endl;
//        for(auto map:total_depth_step){
//            int average=map.second.first/map.second.second;
//            std::cout<<"depth: "<<map.first<<" number of nodes: "<<map.second.second<<" average steps: "<<average<<std::endl;
//        }
//
//
//


    
    return 0;
}


