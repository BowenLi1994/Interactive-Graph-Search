#include <iostream>
#include <string>
#include <vector>

#include "../tree/tree.h"
#include "../path-tree/path-tree.h"
#include "../log/log.h"
// #include "../interleave/interleave_frequency.h"
#include "../adaptive/compared.h"
#include "../query/parser/query_parser.h"
#include "../experiment/experiment.h"

int main(int argc, const char * argv[]){

    using Label=label::StringLabel;
    using Node=node::Node<Label>;
    using Supernode=supernode::Supernode;
    using Query=query::Query;
    using Log=query::Query;

  std::string tree_path="/home/bowen/igs_dataset/amazon/manual/concatnate_10000.tree";
  std::vector<Node> trees_collection;
  parser::BracketNotationParser bnp;
  bnp.parse_collection(trees_collection,tree_path);

  std::string query_path="/home/bowen/igs_dataset/query/concatnate10000_zipf_2.0.query";
  std::vector<Query> query_collection;
  query_parser::parse_collection(query_collection,query_path);


  std::string log_path="/home/bowen/igs_dataset/log/concatnate10000_zipf_2.0.log";
  std::vector<Log> log_collection;
  log_file::log_analysis(trees_collection,log_path);

  
  std::string ftrees_path="/home/bowen/igs_dataset/frequency-tree/concatnate10000_zipf_2.0.ftree";
  std::vector<Supernode *> ftree_collection;
  parser::PathTreeParser ptp;
  ptp.parse_collection(ftree_collection,trees_collection,ftrees_path);

    std::cout<<"calculate tree: "<<1000<<std::endl;
    for(auto query_id: query_collection[1000].get_nodes()){

      Label target_label("target");
      Node target_node(target_label);
      target_node.set_id(query_id);
      bool found=0;
      int steps=0;
      trees_collection[1000].reset_checked();
      baseline::Topdown(trees_collection[1000], target_node, found, steps);

      std::cout<<"steps: "<<steps<<std::endl;

    }




 


  //trees_collection[150].print_all_label();

  // int trees_number=(int)trees_collection.size();

  // for(int i=0;i<trees_number;i++){

  //   std::cout<<"calculate tree: "<<i<<std::endl;
  //   for(auto query_id: query_collection[i].get_nodes()){

  //     Label target_label("target");
  //     Node target_node(target_label);
  //     target_node.set_id(query_id);
  //     bool found=0;
  //     int steps=0;
  //     trees_collection[i].reset_checked();
  //     baseline::Topdown(trees_collection[i], target_node, found, steps);

  //     std::cout<<"steps: "<<steps<<std::endl;

  //   }

  // }





  return 0;

}







