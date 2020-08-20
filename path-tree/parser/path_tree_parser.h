#pragma once

#include "../../tree/tree.h"
#include "../../path-tree/super_node/supernode.h"
#include "../../others/functions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

namespace parser {

class PathTreeParser {
// Types and type aliases
public:
  using Label = label::StringLabel;
  using Node= node::Node<Label>;
  using Supernode=supernode::Supernode;
    

// Member functions
public:
    
    
  Supernode parse_single(const std::string& tree_string);

    
  void parse_collection(std::vector<Supernode*>& trees_collection,
      const std::string& file_path);

    
  std::vector<std::string> get_tokens(const std::string& tree_string);

  bool validate_input(const std::string& tree_string) const;
  std::vector<std::pair<int, int>> get_ids(const std::string& node_string);
    
// Member variables
private:
    
    
  /// A stack to store nodes on a path to the root from the current node in the
  /// parsing process. Needed for maintaining correct parent-child relationships
  /// while parsing.
  std::vector<Supernode*> node_stack;

  /// Structure brackets for representing nodes relationships. Could be
  /// modified to other types of paretheses if necessary.
  const std::string kLeftBracket = "{";
  const std::string kRightBracket = "}";

  /// Structure elements of the bracket notation.
  const std::string kStructureElements = "{}";

  /// Escape character.
  const char kEscapeChar = '\\';

  /// A regex string to match left and right brackets.
  const std::string kMatchLeftBracket = "\\" + kLeftBracket;
  const std::string kMatchRightBracket = "\\" + kRightBracket;
};

// Implementation details
#include "path_tree_parser_impl.h"

}
