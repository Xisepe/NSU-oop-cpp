//
// Created by Maxim on 05.09.2022.
//
#include <BigInt.h>
#include <ParseUtil.h>
#include <iomanip>  // std::setw
#include <iostream> // std::cout, std::left
#include <climits>

bool BigInt::IsDigitCorrect(const int digit) {
  if (digit >= kBase || digit < 0) {
    return false;
  }
  return true;
}

bool BigInt::IsSignNegative() const { return is_negative; }
void BigInt::SetSign(const bool is_negative) {
  this->is_negative = is_negative;
}

void BigInt::PushDigit(const int digit) {
  if (BigInt::IsDigitCorrect(digit)) {
    this->digits.push_back(digit);
  } else {
    throw std::invalid_argument("Invalid digit");
  }
}
void BigInt::ChangeDigitAtPosition(const int digit, const int pos) {
  if (pos >= digits.size() || pos < 0) {
    throw std::out_of_range("Position is out the bound");
  }
  if (IsDigitCorrect(digit)) {
    this->digits[pos] = digit;
  } else {
    throw std::invalid_argument("Invalid digit");
  }
}

void BigInt::RemoveLeadingZeros() {
  while (digits.size() > 1 && digits.back() == 0) {
    digits.pop_back();
  }
}

bool BigInt::IsZero() const {
  return this->digits.size() == 1 && this->digits.front() == 0;
}

BigInt BigInt::DivMod(const BigInt &o, int mode = 0) const {
  int norm = kBase / (o.digits.back() + 1);
  BigInt a = *this * norm;
  BigInt b = o * norm;
  BigInt q;
  BigInt r;
  std::vector<int> empty(a.digits.size());
  q.digits = empty;

  for (int i = a.digits.size() - 1; i >= 0; i--) {
    r *= kBase;
    r += a.digits[i];
    int s1 = r.digits.size() <= b.digits.size()
                 ? 0
                 : r.digits[b.digits.size()];
    int s2 = r.digits.size() <= b.digits.size() - 1
                 ? 0
                 : r.digits[b.digits.size() - 1];
    int d = ((int64_t)kBase * s1 + s2) / b.digits.back();
    r -= b * d;
    while (r < 0) {
      r += b;
      --d;
    }
    q.ChangeDigitAtPosition(d, i);
  }

  q.is_negative = this->is_negative != o.IsSignNegative();
  r.is_negative = this->is_negative;
  q.RemoveLeadingZeros();
  r.RemoveLeadingZeros();
  switch (mode) {
  case 0:
    return q;
  case 1:
    return r / norm;
  }
}
BigInt BigInt::Divide(const BigInt &o) const { return this->DivMod(o); }
BigInt BigInt::Mod(const BigInt &o) const { return this->DivMod(o, 1); }

BigInt::BigInt() {
  is_negative = false;
  digits.push_back(0);
}

BigInt::BigInt(int digit) {
  if (digit < 0) {
    is_negative = true;
    digit = -digit;
  } else {
    is_negative = false;
  }
  if (digit < kBase) {
    digits.push_back(digit);
  } else {
    digits.push_back(digit % kBase);
    digits.push_back(digit / kBase);
  }
}

BigInt::BigInt(std::string str) {
  if (!ParseUtil::IsInputCorrect(str)) {
    throw std::invalid_argument("String contains non digit symbols!");
  }
  int left_bound = 0;
  if (ParseUtil::IsFirstCharSign(str)) {
    is_negative = ParseUtil::IsNegative(str.at(0));
    left_bound++;
  } else {
    is_negative = false;
  }
  left_bound = ParseUtil::MoveLeftBoundIfHasLeadingZeros(left_bound, str);
  if (left_bound == str.length()) {
    digits.push_back(0);
  }
  for (int i = str.length() - 1; i >= left_bound; i -= kMaxDigitLen) {
    std::string tmp;
    if (i - left_bound < kMaxDigitLen) {
      tmp = str.substr(left_bound, i - left_bound + 1);
    } else {
      tmp = str.substr(i - kMaxDigitLen + 1, kMaxDigitLen);
    }
    int to_push = std::stoi(tmp);
    digits.push_back(to_push);
  }
}

BigInt::~BigInt() {}

BigInt::BigInt(const BigInt &i) {
  this->is_negative = i.IsSignNegative();
  this->digits = i.digits;
}

BigInt &BigInt::operator=(const BigInt &i) {
  if (this == &i) {
    return *this;
  }
  this->is_negative = i.IsSignNegative();
  this->digits = i.digits;
  return *this;
}

BigInt BigInt::operator+() const { return *this; }
BigInt BigInt::operator-() const {
  BigInt ret(*this);
  ret.SetSign(!this->is_negative);
  return ret;
}

BigInt BigInt::operator~() const {
  BigInt res;
  res.SetSign(this->IsSignNegative());
  for (int64_t i = 0; i < digits.size(); ++i) {
    res.PushDigit(((unsigned int)digits[i]) % kBase);
  }
  return res;
}

bool BigInt::operator==(const BigInt &other) const {
  return this->is_negative == other.IsSignNegative() &&
         this->digits == other.digits;
}
bool BigInt::operator!=(const BigInt &other) const { return !(*this == other); }
bool BigInt::operator<(const BigInt &other) const {
  if (this->is_negative != other.is_negative) {
    return this->is_negative && !other.is_negative;
  }
  if (this->digits.size() != other.digits.size()) {
    bool state = this->digits.size() < other.digits.size();
    if (this->is_negative) {
      return !state;
    } else
      return state;
  }
  for (int i = digits.size() - 1; i >= 0; --i) {
    if (digits[i] != other.digits[i]) {
      bool state = digits[i] < other.digits[i];
      if (is_negative) {
        return !state;
      } else
        return state;
    }
  }
  return false;
}
bool BigInt::operator>(const BigInt &other) const { return other < *this; }
bool BigInt::operator<=(const BigInt &other) const { return !(other < *this); }
bool BigInt::operator>=(const BigInt &other) const { return !(*this < other); }

BigInt operator+(const BigInt &o1, const BigInt &o2) {
  if (o1.IsSignNegative() == o2.IsSignNegative()) {
    BigInt res = o1;
    const int kMax = std::max(o1.digits.size(), o2.digits.size());
    int carry = 0;
    for (int i = 0; i < kMax || carry; ++i) {
      if (i == res.digits.size()) {
        res.PushDigit(0);
      }
      int digit = res.digits[i] + carry +
                  (i < o2.digits.size() ? o2.digits[i] : 0);
      carry = digit >= kBase;
      digit -= carry ? kBase : 0;
      res.ChangeDigitAtPosition(digit, (int)i);
    }
    return res;
  }
  return o1 - (-o2);
}
BigInt operator-(const BigInt &o1, const BigInt &o2) {
  if (o1.IsSignNegative() == o2.IsSignNegative()) {
    if ((o1.IsSignNegative() && o1 <= o2) ||
        (!o1.IsSignNegative() && o1 >= o2)) {
      BigInt res = o1;
      const int kMax = o2.digits.size();
      int carry = 0;
      for (int i = 0; i < kMax || carry; i++) {
        int digit = res.digits[i] - carry -
                    (i < o2.digits.size() ? o2.digits[i] : 0);
        carry = digit < 0;
        digit += carry ? kBase : 0;
        res.ChangeDigitAtPosition(digit, i);
      }
      res.RemoveLeadingZeros();
      return res;
    }
    return -(o2 - o1);
  }
  return o1 + (-o2);
}
BigInt operator*(const BigInt &o1, const BigInt &o2) {
  BigInt res;
  if (o1.IsZero() || o2.IsZero()) {
    return res;
  }
  for (int i = 0; i < o1.digits.size(); ++i) {
    BigInt tmp;
    std::vector<int> digits(i, 0);
    int carry = 0;
    for (int j = 0; j < o2.digits.size() || carry; ++j) {
      int to_push = carry;
      carry /= kBase;
      if (j < o2.digits.size()) {
        int64_t mul = ((int64_t)o1.digits[i]) * o2.digits[j];
        to_push += mul % kBase;
        carry += mul / kBase + to_push / kBase;
      }
      digits.push_back(to_push % kBase);
    }
    tmp.digits = digits;
    tmp.RemoveLeadingZeros();
    res += tmp;
  }
  if (o1.IsSignNegative() != o2.IsSignNegative()) {
    res.SetSign(true);
  }
  return res;
}
BigInt operator/(const BigInt &o1, const BigInt &o2) { return o1.Divide(o2); }
BigInt operator%(const BigInt&o1, const BigInt&o2) {
    return o1.Mod(o2);
}

BigInt operator&(const BigInt&o1, const BigInt&o2) {
  BigInt res;
  int64_t max_len = std::max(o1.digits.size(),o2.digits.size());
  for (int64_t i = 0; i < max_len; ++i) {
    int s1 = i < o1.digits.size() ? o1.digits[i] : 0;
    int s2 = i < o2.digits.size() ? o2.digits[i] : 0;
    res.ChangeDigitAtPosition(s1 & s2, i);
    res.PushDigit(0);
  }
  res.RemoveLeadingZeros();
  return res;
}
BigInt operator|(const BigInt&o1, const BigInt&o2) {
  BigInt res;
  int64_t max_len = std::max(o1.digits.size(),o2.digits.size());
  for (int64_t i = 0; i < max_len; ++i) {
    int s1 = i < o1.digits.size() ? o1.digits[i] : 0;
    int s2 = i < o2.digits.size() ? o2.digits[i] : 0;
    res.ChangeDigitAtPosition((s1 | s2) % kBase, i);
    res.PushDigit(0);
  }
  res.RemoveLeadingZeros();
  return res;
}

BigInt operator^(const BigInt&o1, const BigInt&o2) {
  BigInt res;
  int64_t max_len = std::max(o1.digits.size(),o2.digits.size());
  for (int64_t i = 0; i < max_len; ++i) {
    int s1 = i < o1.digits.size() ? o1.digits[i] : 0;
    int s2 = i < o2.digits.size() ? o2.digits[i] : 0;
    res.ChangeDigitAtPosition((s1 ^ s2) % kBase, i);
    res.PushDigit(0);
  }
  res.RemoveLeadingZeros();
  return res;
}





BigInt &BigInt::operator++() {
  *this = *this + 1;
  return *this;
}
BigInt BigInt::operator++(int) {
  BigInt tmp(*this);
  ++*this;
  return tmp;
}
BigInt &BigInt::operator--() {
  *this = *this - 1;
  return *this;
}
BigInt BigInt::operator--(int) {
  BigInt tmp(*this);
  --*this;
  return tmp;
}

BigInt &BigInt::operator*=(const BigInt &o) {
  *this = *this * o;
  return *this;
}
BigInt &BigInt::operator/=(const BigInt &o) {
  *this = *this / o;
  return *this;
}
BigInt &BigInt::operator+=(const BigInt &o) {
  *this = *this + o;
  return *this;
}
BigInt &BigInt::operator%=(const BigInt &o) {
    *this = *this % o;
    return *this;
}

BigInt &BigInt::operator-=(const BigInt &o) {
  *this = *this - o;
  return *this;
}

BigInt &BigInt::operator&=(const BigInt &o) {
  *this = *this & o;
  return *this;
}

BigInt::operator std::string() const {
  std::stringstream ss;
  std::string res;
  ss << *this;
  ss >> res;
  return res;
}

BigInt &BigInt::operator|=(const BigInt &o) {
  *this = *this | o;
  return *this;
}

BigInt &BigInt::operator^=(const BigInt &o) {
  *this = *this ^ o;
  return *this;
}
size_t BigInt::size() const {
    return sizeof(std::vector<int>) + (sizeof(int) * digits.size()) + sizeof(is_negative);
}
BigInt::operator int() const {
  if (*this >= BigInt(INT_MAX)) {
    return INT_MAX;
  }
  if (*this <= BigInt(INT_MIN)) {
    return INT_MIN;
  }
  int res = digits[0];
  if (digits.size() == 2) {
    res += digits[1]*kBase;
  }
  return res;
}

std::ostream &operator<<(std::ostream &o, const BigInt &i) {
  if (i.IsSignNegative()) {
    o << '-';
  }
  long size = i.digits.size();
  o << i.digits[size - 1];
  for (int j = size - 2; j >= 0; j--) {
    o << std::right << std::setw(kMaxDigitLen) << std::setfill('0')
      << i.digits[j];
  }
  return o;
}
