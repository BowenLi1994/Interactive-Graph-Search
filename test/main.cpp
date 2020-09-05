#include <iostream>
#include <string>
#include <regex>
#include <vector>


#include "../log/log.h"
#include "../tree/tree.h"

int main(int argc, const char * argv[]) {

  using Label=label::StringLabel;
  using Node=node::Node<Label>;
  std::vector<Node> trees_collection;

  parser::BracketNotationParser bnp;

  std::string filepath="../dataset/single_case1.tree";
  bnp.parse_collection(trees_collection,filepath);

  std::string log_path="/home/bowen/igs_dataset/log/single_case1_normal_2.0.log";


  log::log_analysis(trees_collection,log_path);






    // std::string query_string="12-8-6-0-7-2-5-1-12-11-1-7-12-11-6-1-11-7-11-11-9-9-7-7-12-2-8-5";

    // std::vector<query::Query> query_collecion;
    
    // // query::Query q=query_parser::parse_singel(query_string);

    // // q.print();

    // std::string file_path="/home/bowen/igs_dataset/query/bolzano_normal_2.0.query";
    // query_parser::parse_collection(query_collecion,file_path);

    // for(auto query: query_collecion)
    //   query.print();




  
    return 0;
}



