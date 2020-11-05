#pragma once
using namespace parser;


dag::Node<label::StringLabel>* DAGParser::parse_collection(const std::string& file_path){

    std::vector<std::string> lines;
    functions::ReadFile(file_path,lines);

    int node_num=lines.size();
    //std::cout<<node_num<<std::endl;

    for(int i=0;i<node_num;i++){
        
        Label l(std::to_string(i));
        Node* n=new Node(l);
        n->set_id(i);
        node_set.push_back(n);
        
    }

    for(int i=0;i<node_num;i++){

        if(lines[i]!=""){

            std::vector<std::string> tokens;
            tokens.clear();
            functions::SplitString(lines[i],tokens," ");
            for(auto token:tokens){
                node_set[i]->add_child(node_set[std::stoi(token)]);
                node_set[std::stoi(token)]->add_parent(node_set[i]);
            }
            
        }
    } 

    //node_set[0]->print();
    Node* root;
    //std::set<Node*> leaves_set;

    for(auto node:node_set){
        if(node->is_root())
            root=node;
        if(node->is_leaf()){
            leaves_set.insert(node);
            //std::cout<<node->id()<<std::endl;
        }
    }

    for(auto leaf: leaves_set){
        root->add_leaf(leaf);
        //std::cout<<leaf->id()<<std::endl;
    }


 

    return root;

}

// Node*  DAGParser::parse_collection(const std::string& file_path){

//     std::vector<std::string> lines;

//     functions::ReadFile(file_path,lines);

//     int node_num=lines.size();
//     std::cout<<node_num<<std::endl;

//     // for(int i=0;i<node_num;i++){
        
//     //     Label l(std::to_string(i));
//     //     Node* n=new Node(l);
//     //     n->set_id(i);
        
//     // }

// }


