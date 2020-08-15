//
//  supernode.h
//  tree_interleave
//
//  Created by Bowen Li on 3/3/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once

#include "../../tree/node/node.h"
#include "../../tree/label/string_label.h"
#include <vector>

namespace supernode{

    using Node=node::Node<label::StringLabel>;

class Supernode{
public:
    using SizeType = typename std::vector<Node>::size_type;
public:
    
    Supernode();
    int id();
    void set_id(int id);
    
    std::vector<Node *> getNodes();
    
    std::vector<Supernode *> getChildren();
    
    
    const SizeType children_count() const;
    
    void add_child(Supernode* child);
    
    int get_heavy_tree_size() const;
    
    const SizeType nodes_count() const;
    
    void add_node(Node* node);
    
    void print_all_nodes();
    
    void print_heay_tree();
    
    bool is_contained(int id);
    
    
    private:
    int id_;
    std::vector<Node *> nodes_;
    std::vector<Supernode *> children_;
    
    

};

#include "supernode_impl.h"
}




