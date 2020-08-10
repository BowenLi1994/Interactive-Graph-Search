//
//  baseline.h
//  igs
//
//  Created by Bowen Li on 2/16/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once

#include<vector>
#include<string>
#include <typeinfo>


//#include""
#include "../tree/label/string_label.h"
#include "../tree/node/node.h"
#include "../others/reachability.h"

using Label=label::StringLabel;
using Node=node::Node<Label>;

namespace baseline{



void Topdown(Node &root, Node& target,bool & found,int &step);



void Topdown(Node &root, Node& target,bool &found,int& step){
     
    
    //std::cout<<"node: "<<root.id()<<std::endl;
    bool child_reach_target=false;

    //step++;

    for(auto& child:root.get_children()){
        if(!found){
            if(Reachability::Reachability(child, target,step)){
                     child_reach_target=true;
                     Topdown(child, target,found, step);
            }
        }
                   
    }
    
    if(!child_reach_target){
        target.set_depth(root.depth());
        found=true;
                   
    }
        
}




}


