/// \file tree/label/string_label_impl.h
///
/// \details
/// Contains the implementation of the StringLabel class.

#pragma once

StringLabel::StringLabel(){}

StringLabel::StringLabel(const std::string& label) : label_(label) {}


bool StringLabel::operator==(const StringLabel& other) const {
  return (label_.compare(other.to_string()) == 0);
}

const std::string& StringLabel::to_string() const {
  return label_;
}
