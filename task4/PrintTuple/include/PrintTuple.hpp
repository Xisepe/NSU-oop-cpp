//
// Created by Maxim on 24.12.2022.
//

#ifndef CSVPARSER_PRINTTUPLE_HPP
#define CSVPARSER_PRINTTUPLE_HPP

#include "IncludeLibs.hpp"

template<size_t index = 0, typename ...Args>
std::ostream& printTuple(std::ostream& out, const std::tuple<Args...>& tuple){
  if constexpr (index == sizeof...(Args)) {
    return out;
  } else {
    out << std::get<index>(tuple) << " ";
    return printTuple<index + 1>(out,tuple);
  }
}
template<class ...Args>
auto& operator<<(std::ostream& out, const std::tuple<Args...>& tuple) {
  return printTuple(out,tuple);
}
#endif // CSVPARSER_PRINTTUPLE_HPP
