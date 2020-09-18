#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <iomanip>




#include "../../tree/tree.h"
#include "../../path-tree/path-tree.h"
#include "../../others/others.h"
#include "./generator.h"







int main(int argc, const char * argv[]) {

    using Label=label::StringLabel;
    using Node=node::Node<Label>;
    using Supernode=supernode::Supernode;
    
    std::string type(argv[1]);
    std::string filename(argv[2]);
    std::string method(argv[3]);
    std::string num_type(argv[4]);

    int num_val=0;
    double theta=0;

    if(num_type=="fixed"){
        num_val=atoi(argv[5]);
    }

    if(num_type=="theta"){
        theta=(double)atof(argv[5]);
    }





    std::string filepath;
    filepath=functions::getFilePath(filename);
    if(filename=="NULL")
        return 0;
   
    // //std::cout<<filepath<<std::endl;
    // std::string filepath="../dataset/singel_case1.tree";

    //parse tree
    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    bnp.parse_collection(trees_collection,filepath);

    std::vector<std::string> result;


    if(num_type=="fixed"){

        query::fixed_generator(trees_collection,result,method,num_val);
    
    }

    if(num_type=="theta"){
        query::theta_generator(trees_collection,result,method,theta);
    }

    std::string out_filepath;
    std::string out_filename;

    if(type=="query"){
        out_filepath="/home/bowen/igs_dataset/query/";
        if(num_type=="fixed"){
            
            out_filename=filename+"_"+method+"_"+std::to_string(num_val)+".query";

        }
        if(num_type=="theta"){
            std::stringstream stream;
            stream << std::fixed << std::setprecision(1)<< theta;
            out_filename=filename+"_"+method+"_"+stream.str()+".query";
        }
      
    }

    if(type=="log"){
        out_filepath="/home/bowen/igs_dataset/log/";
        if(num_type=="fixed"){
            
            out_filename=filename+"_"+method+"_"+std::to_string(num_val)+".log";

        }
        if(num_type=="theta"){

            std::stringstream stream;
            stream << std::fixed << std::setprecision(1)<< theta;
            out_filename=filename+"_"+method+"_"+stream.str()+".log";
        }
    }

    functions::WriteFile(out_filepath+out_filename,result);



    
    return 0;
}