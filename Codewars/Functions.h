#ifndef PROGRAMMING_PROBLEMS_FUNCTIONS_H
#define PROGRAMMING_PROBLEMS_FUNCTIONS_H

#include <iostream>
#include <vector>

namespace Functions {
    std::string DNAStrand(const std::string& dna);
    int get_sum(int a, int b);
    std::string accum(const std::string &s);
    bool is_isogram(const std::string& str);
    bool is_perfect_square(int&& n);
    bool comp(std::vector<int>&& a, std::vector<int>&& b);
    bool comp_better(std::vector<int>&& a, std::vector<int>&& b);
    long long rowSumOddNumbers(unsigned n);
    long long rowSumOddNumbers_better(unsigned n);
    int convertFromRoman(const std::string& roman);
    std::string likes(const std::vector<std::string> &names);
}

#endif //PROGRAMMING_PROBLEMS_FUNCTIONS_H
