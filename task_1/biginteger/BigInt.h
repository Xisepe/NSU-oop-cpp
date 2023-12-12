//
// Created by Maxim on 05.09.2022.
//

#ifndef LAB1_BIGINT_H
#define LAB1_BIGINT_H
#include <string>
#include <vector>

/**
 * Base of all digits can be held at each position in vector<int>
 */
static const int kBase = 1000000000;
/**
 * Maximal length of each digit in vector<int>
 */
static const int kMaxDigitLen = 9;

class BigInt {

private:
  /**
   * Sign of BigInt
   *
   * true if BigInt is negative
   * false otherwise
   */
  bool is_negative;
  /**
   * BigInt storage
   *
   * Store absolute values of digits in big-endian order
   */
  std::vector<int> digits;
  /**
   * Division algorithm.
   *
   * @param o BigInt reference to divisor
   * @param mode take mode of algorithm. If @param mode is 0, performs regular
   * division. If @param mode is 1, performs division with reminder and return
   * reminder. @param mode has default value: 0.
   * @return BigInt result of division or reminder depending on the input
   */
  BigInt DivMod(const BigInt &o, int mode) const;
  /**
   * Check if digit can be stored in @code{digits}
   *
   * @param digit value to check
   * @return true if can be stored, otherwise false
   */
  static bool IsDigitCorrect(const int digit);

public:
  /**
   * Create default BigInt
   */
  BigInt();
  /**
   * Translate int into BigInt
   *
   * @param val is int representation of BigInt
   */
  BigInt(int val);
  /**
   * Translate string representation of BigInt into BigInt. The input string
   * can contain leading zeros if it needed.
   *
   * @param val string representation of BigInt
   * @throw std::invalid_argument if output is incorrect
   */
  BigInt(std::string val);
  /**
   * Copy constructor.
   * Copies each field of input reference into {@code *this}
   *
   * @param val BigInt reference needed to be copied
   */
  BigInt(const BigInt &val);
  /// Destructor
  ~BigInt();
  /**
   * Copy assignment.
   * Copies each field of input reference into {@code *this}
   * Can hold self-assignment
   *
   * @param val BigInt reference needed to be copied
   * @return {@code *this}
   */
  BigInt &operator=(const BigInt &val);
  /// Unary plus
  BigInt operator+() const;
  /**
   * Unary minus.
   * Change sign of BigInt to the opposite.
   * If sign was positive, sign becomes negative and otherwise
   *
   * @return BigInt with opposite sign
   */
  BigInt operator-() const;
  /**
   * Prefix increment.
   * Arithmetic value of BigInt {@code *this} is incremented by 1.
   *
   * @return {@code *this}
   */
  BigInt &operator++();
  /**
   * Postfix increment.
   * Copies {@code *this} into temporary BigInt value and then
   * arithmetic value of BigInt {@code *this} is incremented by 1.
   *
   * @return copy of {@code *this} before incrementing.
   */
  BigInt operator++(int);
  /**
   * Prefix decrement.
   * Arithmetic value of BigInt {@code *this} is decremented by 1.
   *
   * @return {@code *this}
   */
  BigInt &operator--();
  /**
   * Postfix decrement.
   * Copies {@code *this} into temporary BigInt value and then
   * arithmetic value of BigInt {@code *this} is decremented by 1.
   *
   * @return copy of {@code *this} before decrementing.
   */
  BigInt operator--(int);

  /**
   * Equality operator.
   * Checks if {@code *this} arithmetically equals to {@code val}
   *
   * @param val BigInt reference needed to be compared to {@code *this}
   * @return true if {@code *this} equals to (@param val), false otherwise
   */
  bool operator==(const BigInt &val) const;
  /**
   * Not-equal-to operator.
   * Checks if {@code *this} arithmetically does not equals to {@param val}
   *
   * @param val BigInt reference needed to be compared to {@code *this}
   * @return true if {@code *this} does not equals to {@param val}, false
   * otherwise
   */
  bool operator!=(const BigInt &val) const;
  /**
   * Less-than operator.
   * Checks if {@code *this} arithmetically less than {@param val}
   *
   * @param val BigInt reference needed to be compared to {@code *this}
   * @return true if {@code *this} less than {@param val}, false otherwise
   */
  bool operator<(const BigInt &val) const;
  /**
   * Greater-than operator.
   * Checks if {@code *this} arithmetically greater than {@param val}
   *
   * @param val BigInt reference needed to be compared to {@code *this}
   * @return true if {@code *this} greater than {@param val}, false otherwise
   */
  bool operator>(const BigInt &val) const;
  /**
   * Less-or-equals-to operator.
   * Checks if {@code *this} arithmetically less or equals to {@param val}
   *
   * @param val BigInt reference needed to be compared to {@code *this}
   * @return true if {@code *this} less or equals to {@param val}, false
   * otherwise
   */
  bool operator<=(const BigInt &val) const;
  /**
   * Greater-or-equals-to operator.
   * Checks if {@code *this} arithmetically greater or equals to {@param val}
   *
   * @param val BigInt reference needed to be compared to {@code *this}
   * @return true if {@code *this} greater or equals to {@param val}, false
   * otherwise
   */
  bool operator>=(const BigInt &val) const;

  /**
   * Addition
   * Compute result of arithmetical addition {@code *this + val}
   *
   * @param val BigInt reference to second component
   * @return {@code *this} after adding @param val
   * @see BigInt operator+(const BigInt &, const BigInt &)
   */
  BigInt &operator+=(const BigInt &val);
  /**
   * Multiplication
   * Compute result of arithmetical multiplication {@code *this * val}
   *
   * @param val BigInt reference to second component
   * @return {@code *this} after multiplying on @param val
   * @see BigInt operator*(const BigInt &, const BigInt &)
   */
  BigInt &operator*=(const BigInt &val);
  /**
   * Subtraction
   * Compute result of arithmetical subtraction {@code *this - val}
   *
   * @param val BigInt reference to second component
   * @return {@code *this} after subtracting @param val
   * @see BigInt operator-(const BigInt &, const BigInt &)
   */
  BigInt &operator-=(const BigInt &val);
  /**
   * Division
   * Compute result of arithmetical division {@code *this / val}. If @param o2
   * is zero return zero
   *
   * @param val BigInt reference to divisor
   * @return {@code *this} after division on @param val
   * @see BigInt operator/(const BigInt &, const BigInt &)
   */
  BigInt &operator/=(const BigInt &val);
  /**
   * Division with reminder
   * Compute result of arithmetical division with reminder {@code *this % val}.
   *
   * @param val BigInt reference to divisor
   * @return {@code *this} after division with reminder on @param val
   * @see BigInt operator%(const BigInt &, const BigInt &)
   */
  BigInt &operator%=(const BigInt &val);

  /**
   * Bitwise xor
   * Compute result of bitwise 'xor' of {@code *this ^ val}
   *
   * @param val BigInt reference to second component
   * @return {@code *this} after performing 'xor' with @param val
   * @see BigInt operator^(const BigInt &, const BigInt &)
   */
  BigInt &operator^=(const BigInt &val);
  /**
   * Bitwise and
   * Compute result of bitwise 'and' of {@code *this & val}
   *
   * @param val BigInt reference to second component
   * @return {@code *this} after performing 'and' with @param val
   * @see BigInt operator&(const BigInt &, const BigInt &)
   */
  BigInt &operator&=(const BigInt &val);
  /**
   * Bitwise or
   * Compute result of bitwise 'or' of {@code *this | val}
   *
   * @param val BigInt reference to second component
   * @return {@code *this} after performing 'or' with @param val
   * @see BigInt operator|(const BigInt &, const BigInt &)
   */
  BigInt &operator|=(const BigInt &val);
  /**
   * Bitwise not
   * Compute result of bitwise 'not'
   *
   * @return {@code *this} after performing 'not'
   */
  BigInt operator~() const;

  /**
   * Converts BigInt into string representation
   *
   * @return std::string representation of {@code *this}
   */
  operator std::string() const;

  /**
   * Division
   * Compute result of arithmetical division {@code *this / o2}. If @param val
   * is equals to zero result of division will be zero.
   *
   * @param val BigInt reference to divisor
   * @return BigInt result of arithmetical division of {@code *this} and {@param
   * val}
   */
  BigInt Divide(const BigInt &val) const;
  /**
   * Division
   * Compute result of arithmetical division with reminder {@code *this % o2}.
   *
   * @param val BigInt reference to divisor
   * @return BigInt result of arithmetical division wit reminder of {@code
   * *this} and {@param val}
   */
  BigInt Mod(const BigInt &val) const;
  /**
   * Check if {@code *this} is arithmetical zero.
   *
   * @return true if {@code *this} is zero, false otherwise
   */
  bool IsZero() const;
  /**
   * Removes leading zeros from {@code *this}
   */
  void RemoveLeadingZeros();
  ///{@code this->is_negative} getter
  bool IsSignNegative() const;
  ///{@code this->is_negative} setter
  void SetSign(bool);
  /**
   * Push digit to @code{digits}
   *
   * @param int must be in range 0..kBase-1 inclusive
   * @throws std::invalid_argument if @param not obey condition
   */
  void PushDigit(int);
  /**
   * Changes digit in {@code this->digits} at @param pos to @param digit
   *
   * @throws std::out_of_range if @param pos is greater than {@code
   * this->digits.size()}
   * @throws std::invalid_argument if @param digit is negative or greater than
   * @const kBase
   * @param digit new int value
   * @param pos position in {@code this->digits}
   */
  void ChangeDigitAtPosition(int digit, int pos);
  /**
   * Calculate size of object in bytes
   *
   * @return size of object in bytes
   */
  size_t size() const;

  explicit operator int() const;
  /**
   * Addition operator.
   * Compute result of arithmetical addition {@code o1 + o2}
   *
   * @param o1 is BigInt reference to first component
   * @param o2 is BigInt reference to second component
   * @return BigInt result of arithmetical addition of to values {@param o1} and
   * {@param o2}
   */
  friend BigInt operator+(const BigInt &o1, const BigInt &o2);
  /**
   * Subtraction operator.
   * Compute result of arithmetical subtraction {@code o1 - o2}
   *
   * @param o1 is BigInt reference to first component
   * @param o2 is BigInt reference to second component
   * @return BigInt result of arithmetical subtraction of to values {@param o1}
   * and {@param o2}
   */
  friend BigInt operator-(const BigInt &o1, const BigInt &o2);
  /**
   * Multiplication operator.
   * Compute result of arithmetical multiplication {@code o1 * o2}
   *
   * @param o1 is BigInt reference to first component
   * @param o2 is BigInt reference to second component
   * @return BigInt result of arithmetical multiplication of to values {@param
   * o1} and {@param o2}
   */
  friend BigInt operator*(const BigInt &o1, const BigInt &o2);
  /**
   * Division operator.
   * Compute result of arithmetical division {@code o1 / o2}. If @param o2 is
   * equals to zero result of division will be zero.
   *
   * @param o1 is BigInt reference to dividend
   * @param o2 is BigInt reference to divisor
   * @return BigInt result of arithmetical division of to values {@param o1} and
   * {@param o2}
   */
  friend BigInt operator/(const BigInt &o1, const BigInt &o2);
  /**
   * Division with reminder operator.
   * Compute result of arithmetical division with reminder {@code o1 * o2}
   *
   * @param o1 is BigInt reference to dividend
   * @param o2 is BigInt reference to divisor
   * @return BigInt result of arithmetical division with reminder of to values
   * {@param o1} and {@param o2}
   */
  friend BigInt operator%(const BigInt &o1, const BigInt &o2);
  /**
   * Xor operator.
   * Performs bitwise 'xor' operation with each digit from {@code o1.digits} and
   * relevant digit from
   * {@code o2.digits}. If size of one of params is greater than other, assumes
   * that digits from unreachable indices in smaller o?.digits are zeros. If
   * result of operation is greater than @see kBase result stores by mod of
   * base.
   *
   * @param o1 is BigInt reference to first component
   * @param o2 is BigInt reference to second component
   * @return BigInt as result of bitwise 'xor' of @param o1 and @param o2
   */
  friend BigInt operator^(const BigInt &o1, const BigInt &o2);
  /**
   * And operator.
   * Performs bitwise 'and' operation with each digit from {@code o1.digits} and
   * relevant digit from
   * {@code o2.digits}. If size of one of params is greater than other, assumes
   * that digits from unreachable indices in smaller o?.digits are zeros
   *
   * @param o1 is BigInt reference to first component
   * @param o2 is BigInt reference to second component
   * @return BigInt as result of bitwise 'and' of @param o1 and @param o2
   */
  friend BigInt operator&(const BigInt &o1, const BigInt &o2);
  /**
   * Or operator.
   * Performs bitwise 'or' operation with each digit from {@code o1.digits} and
   * relevant digit from
   * {@code o2.digits}. If size of one of params is greater than other, assumes
   * that digits from unreachable indices in smaller o?.digits are zeros. If
   * result of operation is greater than @see kBase result stores by mod of
   * base.
   *
   * @param o1 is BigInt reference to first component
   * @param o2 is BigInt reference to second component
   * @return BigInt as result of bitwise 'or' of @param o1 and @param o2
   */
  friend BigInt operator|(const BigInt &o1, const BigInt &o2);
  /**
   * Output stream operator.
   * Writes @param i into stream. If sign of BigInt {@code i.is_negative} add
   * "-" at the beginning of output. If {@code i.digits[j]} is zero translate it
   * into "000000000".
   *
   * @param o[out] output stream reference
   * @param i BigInt value needed to be written into output stream
   * @return stream
   */
  friend std::ostream &operator<<(std::ostream &o, const BigInt &i);
};

#endif // LAB1_BIGINT_H
