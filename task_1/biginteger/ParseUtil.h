//
// Created by Maxim on 12.09.2022.
//

#ifndef TASK_1_PARSEUTIL_H
#define TASK_1_PARSEUTIL_H

#include <algorithm>
#include <string>

class ParseUtil {
public:
  static inline bool IsFirstCharSign(const std::string &str) {
    const char &i = str.at(0);
    if (i == '-' || i == '+') {
      return true;
    }
    return false;
  }

  static inline bool IsNegative(char c) {
    if (c == '-') {
      return true;
    }
    return false;
  }

  static inline int MoveLeftBoundIfHasLeadingZeros(int left_bound,
                                                   const std::string &str) {
    while (left_bound < str.length() && str.at(left_bound) == '0') {
      left_bound++;
    }
    return left_bound;
  }

  static inline bool IsInputCorrect(const std::string &str) {
    if (!std::isdigit(str.at(0)) && str.at(0) != '+' && str.at(0) != '-') {
      return false;
    }
    if (std::all_of(str.begin() + 1, str.end(),
                    [](const char &c) { return isdigit(c); })) {
      return true;
    }
    return false;
  }

private:
  ParseUtil();
};
#endif // TASK_1_PARSEUTIL_H
