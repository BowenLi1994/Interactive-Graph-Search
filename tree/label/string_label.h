/// \file tree/label/string_label.h
///
/// \details
/// Contains the declaration of the StringLabel class (represents string data
/// which is associated with a Node). For example, if one wants a tree with
/// strings as labels, one could use this class as a template argument for the
/// Node class to accomplish this.

#pragma once

#include <string>

namespace label {


class StringLabel {
public:
    
    //Default Constructor
    StringLabel();
    StringLabel(const std::string& label);

    /// Operator overloadings.
    /// @{
    bool operator==(const StringLabel& other) const;
    /// @}

    const std::string& to_string() const;

private:
    /// The label to be associated with a node.
    std::string label_{};
};

// Implementation details
#include "string_label_impl.h"

}


