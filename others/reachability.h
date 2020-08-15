//
//  baseline.h
//  igs
//
//  Created by Bowen Li on 2/16/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once

#include "../tree/label/string_label.h"
#include "../tree/node/node.h"

using Label=label::StringLabel;
using Node=node::Node<Label>;

namespace Reachability{



bool Reachability(Node& start,Node& target,int & step);





bool Reachability(Node& start,Node& target,int & step){
    
    if(!start.is_checked()){
        step++;
        std::cout<<"search: "<<start.id()<<"-->"<<target.id()<<std::endl;
    }
    else
        std::cout<<"repeat search: "<<start.id()<<"-->"<<target.id()<<std::endl;
    
    
    
    start.set_check(true);
    //std::cout<<"node: "<<start.id()<<std::endl;
    
    int start_node_id=start.id();
    
    
    //root node:
    if(start.depth()==0){
        return true;
    }
    
    else{
        
        if(start.right_sibling()==-1){
            if(target.id()>=start_node_id)
                return true;
            else
                return false;
            
        }
        else{
            int end_node_id=start.right_sibling();
            if(target.id()>=start_node_id && target.id()<end_node_id){
                return true;
            }
            else
                return false;
            
        }
        
    }
    return false;

}





}


