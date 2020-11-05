#pragma once

#include "../node/node.h"
#include "../../tree/label/string_label.h"
#include "../../others/others.h"

#include <iostream>
#include <fstream>
#include <string>
#include <set>

namespace parser {

class DAGParser {
// Types and type aliases
public:
  using Label = label::StringLabel;
  using Node = dag::Node<Label>;

// Member functions
public:

  Node* parse_collection(const std::string& file_path);

private:
  std::vector<Node *> node_set;
  std::set<Node*> leaves_set;

};

// Implementation details
#include "parser_impl.h"

}
