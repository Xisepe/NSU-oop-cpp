//
// Created by Maxim on 24.12.2022.
//

#ifndef LAB4_CSVPARSER_HPP
#define LAB4_CSVPARSER_HPP

#include "CSVExceptions.hpp"
#include "IncludeLibs.hpp"
#include "PrintTuple.hpp"

template <class... Args> class CSVParser {
private:
  using Tuple = std::tuple<Args...>;
  using Parser = CSVParser<Args...>;
  std::ifstream *in;
  char rowDelimiter;
  char columnDelimiter;
  char shield;
  Tuple tuple;
  std::string line;
  int currentRow;
  int currentColumn;

  std::istream &shieldingGetline(std::istream &in, std::string &str,
                                 char delimiter = ',', char shield = '"') {
    char ch;
    bool ignoreDelimiter = false;
    str.clear();
    while (in.get(ch) && (ch != delimiter || ignoreDelimiter)) {
      if (ch == shield) {
        ignoreDelimiter = !ignoreDelimiter;
      }
      str.push_back(ch);
    }
    return in;
  }

  void skipLines(int lines) {
    for (int i = 0; i < lines; ++i) {
      shieldingGetline(*in, line, rowDelimiter, shield);
      currentRow++;
      if (in->eof()) {
        throw ReadException(currentRow, currentColumn);
      }
    }
  }
  void removeShield(std::string &element) {
    if (element[0] == shield) {
      element.erase(element.begin());
    }
    if (element[element.size() - 1] == shield) {
      element.erase(element.end() - 1);
    }
    if (element.empty()) {
      throw WrongDataException(currentRow, currentColumn);
    }
  }

  template <class T> T parse(const std::string &_line) {
    if constexpr (std::is_same_v<T, std::string>) {
      return _line;
    }
    std::istringstream is(_line);
    T t;
    is >> t;
    if (!is) {
      throw WrongDataException(currentRow, currentColumn);
    }
    return t;
  }

  template <size_t index = 0>
  void fillTuple(std::stringstream &ss, Tuple &_tuple) {
    if constexpr (index == sizeof...(Args)) {
      return;
    } else {
      using ElemetType = std::tuple_element_t<index, Tuple>;
      std::string _line;
      shieldingGetline(ss, _line, columnDelimiter, shield);
      currentColumn++;
      if (_line.empty()) {
        throw ReadException(currentRow, currentColumn);
      }
      removeShield(_line);
      std::get<index>(_tuple) = parse<ElemetType>(_line);
      fillTuple<index + 1>(ss, _tuple);
    }
  }
  void increment() {
    line.clear();
    shieldingGetline(*in, line, rowDelimiter, shield);
    currentRow++;
    currentColumn = 0;
    std::stringstream ss;
    ss << line;
    if (ss.eof())
      throw WrongDataException(currentRow, currentColumn);
    fillTuple(ss, tuple);
  }

public:
  class InputIterator {
    friend class CSVParser;

  private:
    Parser *iter_ptr;

  public:
    using iterator_category = std::input_iterator_tag;
    using value_type = Tuple;
    using pointer = value_type *;
    using reference = value_type &;
    InputIterator(InputIterator &iterator) : iter_ptr(iterator.iter_ptr) {}
    explicit InputIterator(Parser *ptr = nullptr) : iter_ptr(ptr) {}

    friend bool operator==(const InputIterator &iterator1,
                           const InputIterator &iterator2) {
      return iterator1.iter_ptr == iterator2.iter_ptr;
    }
    friend bool operator!=(const InputIterator &iterator1,
                           const InputIterator &iterator2) {
      return !(iterator1 == iterator2);
    }

    InputIterator &operator=(const InputIterator &other) {
      if (this != other) {
        iter_ptr = other.iter_ptr;
      }
      return *this;
    }
    reference operator*() const { return iter_ptr->tuple; }
    pointer operator->() { return &(iter_ptr->tuple); }
    InputIterator &operator++() {
      if (iter_ptr->in->eof()) {
        iter_ptr = nullptr;
        return *this;
      }
      iter_ptr->increment();
      return *this;
    }
    InputIterator operator++(int) {
      if (iter_ptr->in->eof()) {
        iter_ptr = nullptr;
        return *this;
      }
      iter_ptr->increment();
      return *this;
    }
  };

  CSVParser() = delete;
  CSVParser(std::ifstream *in, int _skipLines, char rowDelimiter = '\n',
            char columnDelimiter = ',', char shield = '"')
      : in(in), rowDelimiter(rowDelimiter), columnDelimiter(columnDelimiter),
        shield(shield), currentRow(0), currentColumn(0) {
    if (!*in) {
      throw std::invalid_argument("Cannot open the file. Possible "
                                  "problems:\n-Wrong path\n-Wrong filename");
    }
    skipLines(_skipLines);
    increment();
  }

  InputIterator begin() { return InputIterator(this); }
  InputIterator end() { return InputIterator(); }
};

#endif // LAB4_CSVPARSER_HPP
