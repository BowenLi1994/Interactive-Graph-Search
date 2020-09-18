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


    bool result=false;

    //std::cout<<"search node: "<<start.id()<<"----->"<<" target: "<<target.id()<<std::endl;
    
    if(!start.is_checked()){
        step++;
        //std::cout<<"search: "<<start.id()<<"-->"<<target.id();
    }
    else
        //std::cout<<"repeat search: "<<start.id()<<"-->"<<target.id();
    
    
    
    start.set_check(true);
    //std::cout<<"node: "<<start.id()<<std::endl;
    
    int start_node_id=start.id();

    // if(start.is_leaf())
    //     return false;
    
    
    //root node:
    if(start.depth()==0){
        //std::cout<<" root!!! "<<std::endl;
        result=true;
    }
    
    else{
        
        if(start.right_sibling()==-1){
            if(target.id()>=start_node_id){
                //std::cout<<" right most "<<std::endl;
                result=true;
            }
            else
                result=false;
            
        }
        else{
            int end_node_id=start.right_sibling();
            if(target.id()>=start_node_id && target.id()<end_node_id){
                //std::cout<<"node: "<<start.id()<<" next right sibling: "<<start.right_sibling()<<std::endl;
                result=true;
            }
            else
                result=false;
            
        }
        
    }


    // if(result==true){
    //     std::cout<<"can reach"<<std::endl;
    // }
    // else
    // {
    //    std::cout<<"can't reach"<<std::endl;
    // }
    


    return result;

}





}


