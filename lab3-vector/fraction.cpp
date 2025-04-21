#include "fraction.h"

#include <iostream>
#include <numeric>    // std::gcd
#include <stdexcept>  // std::out_of_range

Fraction::Fraction(int numerator, int denominator)
    : numerator_(numerator), denominator_(denominator) {
  if (denominator_ == 0) {
    throw std::invalid_argument("Denominator cannot be 0");
  }
}

int Fraction::numerator() const noexcept { return numerator_; }

int Fraction::denominator() const noexcept { return denominator_; }

void Fraction::setNumerator(int numerator) { numerator_ = numerator; }

void Fraction::setDenominator(int denominator) {
  if (denominator == 0) {
    throw std::invalid_argument("Denominator cannot be 0");
  }
  denominator_ = denominator;
}

void Fraction::simplify() {
  int gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;
}

Fraction Fraction::operator+(const Fraction &other) const {
  int new_denominator = denominator_ * other.denominator();
  int new_numerator =
      numerator_ * other.denominator() + other.numerator() * denominator_;
  Fraction result(new_numerator, new_denominator);
  result.simplify();
  return result;
}

Fraction Fraction::operator*(const Fraction &other) const {
  int new_numerator = numerator_ * other.numerator();
  int new_denominator = denominator_ * other.denominator();
  Fraction result(new_numerator, new_denominator);
  result.simplify();
  return result;
}