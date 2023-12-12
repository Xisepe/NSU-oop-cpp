//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_CONFIGPARSER_HPP
#define TASK3_CONFIGPARSER_HPP
#include "ConfigParserException/ConfigParserException.hpp"
#include "IncludeLibs.hpp"
#include "ConverterConfig.hpp"
#include <regex>
class ConfigParser {
private:
  std::ifstream in;
  ConverterConfig config;
  std::string line;
  void skipCommentsAndEmptyLines();
  void fillConfig();
  void readName(std::stringstream& ss,std::string& buffer);
  void next();
public:
  class input_iterator {
  private:
    ConfigParser *iter_ptr;
  public:
    using iterator_category = std::input_iterator_tag;
    using value_type = ConverterConfig;
    using pointer = value_type *;
    using reference = value_type &;
    input_iterator(input_iterator &iterator) : iter_ptr(iterator.iter_ptr) {}
    explicit input_iterator(ConfigParser *ptr = nullptr) : iter_ptr(ptr) {}

    friend bool operator==(const input_iterator &iterator1,
                           const input_iterator &iterator2) {
      return iterator1.iter_ptr == iterator2.iter_ptr;
    }
    friend bool operator!=(const input_iterator &iterator1,
                           const input_iterator &iterator2) {
      return !(iterator1 == iterator2);
    }
    reference operator*() const { return iter_ptr->config; }
    pointer operator->() { return &(iter_ptr->config); }
    input_iterator &operator++() {
      if (iter_ptr->in.eof()) {
        iter_ptr = nullptr;
        return *this;
      }
      iter_ptr->next();
      return *this;
    }
    input_iterator operator++(int) {
      if (iter_ptr->in.eof()) {
        iter_ptr = nullptr;
        return *this;
      }
      iter_ptr->next();
      return *this;
    }
  };
  ConfigParser() = delete;
  ConfigParser(const std::string& name, const std::string& path);
  input_iterator begin();
  input_iterator end();
};

#endif // TASK3_CONFIGPARSER_HPP
