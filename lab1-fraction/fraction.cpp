#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

#include "fraction.h"

#ifdef UNIMPLEMENTED_classFraction
#ifdef _MSC_FULL_VER  // if Visual Studio Compiler
#pragma message( \
    "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#else
#warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#endif  // #ifdef _MSC_FULL_VER
#endif  // #ifdef UNIMPLEMENTED_classFraction

Fraction::Fraction(const int& numerator, const int& denominator,
                   const std::string& fractionName)
    : numerator_{numerator},
      denominator_{denominator},
      fractionName_{fractionName} {}

Fraction::Fraction() : numerator_{0}, denominator_{defaultDenominatorValue} {};

Fraction::~Fraction() { ++removedFractions_; };

int Fraction::removedFractions_ = 0;

int Fraction::removedFractions() { return removedFractions_; }

int Fraction::getNumerator() const { return numerator_; }

void Fraction::setNumerator(const int& numerator) { numerator_ = numerator; }

int Fraction::getInvalidDenominatorValue() { return invalidDenominatorValue; }

int Fraction::getDefaultDenominatorValue() { return defaultDenominatorValue; }

int Fraction::getDenominator() const { return denominator_; }

void Fraction::setDenominator(const int& denominator) {
  denominator_ = denominator;
}

string Fraction::getFractionName() const { return fractionName_; }

void Fraction::print() const {
  cout << numerator_ << "/" << denominator_ << endl;
}

void Fraction::save(ostream& os) const {
  os << numerator_ << '/' << denominator_;
}

void Fraction::load(istream& is) {
  is >> numerator_;
  is.ignore();
  is >> denominator_;
}