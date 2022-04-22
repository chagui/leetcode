#include "src/algorithm/integer-to-roman.h"

#include <iostream>
#include <map>
#include <tuple>

namespace {
    const char ROMAN_ONE = 'I';
    const char ROMAN_FIVE = 'V';
    const char ROMAN_TEN = 'X';
    const char ROMAN_FIFTY = 'L';
    const char ROMAN_HUNDRED = 'C';
    const char ROMAN_FIVE_HUNDRED = 'D';
    const char ROMAN_THOUSAND = 'M';

    using range_elements = std::tuple<const char, const char, const char>;
    const std::map<int, range_elements> rangeToElements{
        {1, {ROMAN_ONE, ROMAN_FIVE, ROMAN_TEN}},
        {10, {ROMAN_TEN, ROMAN_FIFTY, ROMAN_HUNDRED}},
        {100, {ROMAN_HUNDRED, ROMAN_FIVE_HUNDRED, ROMAN_THOUSAND}},
    };

    std::string __foo(int num, int threshold) {
        const range_elements elements = rangeToElements.at(threshold);
        const char unit = std::get<0>(elements);
        const char middle = std::get<1>(elements);
        const char upper = std::get<2>(elements);

        std::string roman;
        int nb_of_units = num / threshold;
        if (nb_of_units < 4) {
            roman = std::string(nb_of_units, unit);
        } else if (nb_of_units == 4) {
            roman.push_back(unit);
            roman.push_back(middle);
        } else if (nb_of_units == 5) {
            roman.push_back(middle);
        } else if (nb_of_units == 9) {
            roman.push_back(unit);
            roman.push_back(upper);
        } else {
            roman = middle + std::string(nb_of_units - 5, unit);
        }
        return roman;
    }
} // namespace

std::string leetcode::Solution::intToRoman(int num) {
    if (num < 4) {
        return std::string(num, ROMAN_ONE);
    }
    std::string roman;
    if (num >= 1000) {
        roman = std::string(num / 1000, ROMAN_THOUSAND);
        num %= 1000;
    }
    roman += __foo(num, 100);
    num %= 100;
    roman += __foo(num, 10);
    num %= 10;
    roman += __foo(num, 1);
    return roman;
}
