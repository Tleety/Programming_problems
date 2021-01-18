#include <algorithm>
#include <set>
#include <map>
#include "Functions.h"

std::string Functions::DNAStrand(const std::string& dna)
{
    auto newString = std::string("");
    for(auto&& s : dna){
        switch (s){
            case 'A':
                newString += "T";
                break;
            case 'T':
                newString += "A";
                break;
            case 'G':
                newString += "C";
                break;
            case 'C':
                newString += "G";
                break;
            default:
                std::cout << "This is fukd. How did you end up here? |" << s << "|";
        }
    }
    //your code here
    return newString;
}

int Functions::get_sum(int a, int b) {
    if(a == b) return a;
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int sum = 0;
    for(int i = min; i <= max; i++){
        sum += i;
    }

    return sum;
}

std::string Functions::accum(const std::string &s) {
    auto count = 0;
    auto newString = std::string("");
    for(auto&& letter : s) {
        if(count > 0) {
            newString += "-";
        }
        newString += toupper(letter);
        for(int i = 0; i < count; i++) {
            newString += tolower(letter);
        }
        count++;
    }
    return newString;
}

bool Functions::is_isogram(const std::string &str) {
    auto string = std::string(str.length(),' ');
    std::transform(begin(str), end(str), begin(string), [](auto&& c){return std::tolower(c);});
    for(auto&& s : string) {
        if(std::count(begin(string), end(string), s) >= 2) {
            return false;
        }
    }
    return true;
}

bool Functions::is_perfect_square(int&& n){
    auto&& root = 0;
    while(root <= n) {
        if(root*root == n) return true;
        root++;
    }
    return false;
}

bool Functions::comp(std::vector<int>&& a, std::vector<int>&& b) {
    for(auto&& root : a) {
        if(!std::count(begin(b), end(b), root*root)) {
            return false;
        } else {
            b.erase(std::find(begin(b), end(b), root*root));
        }
    }
    return b.size() == 0;
}


bool Functions::comp_better(std::vector<int>&& a, std::vector<int>&& b) {
    for(auto&& root : a) {
        root = root*root;
    }
    std::sort(begin(a), end(a));
    std::sort(begin(b), end(b));
    return a == b;

}

long long Functions::rowSumOddNumbers(unsigned n){
    //1             = 1
    //3 5           = 8
    //7 9 11        = 27
    //13 15 17 19   = 64

    if(n == 1) return 1;
    auto nums = 0;
    std::vector<int> sums{1};
    for(int i = n; i >= 0; i--) {
        nums += i;
    }
    auto sum = 0;
    for(int ii = 1; ii < nums; ii++){
        sums.emplace_back(sums.back()+2);
        if(ii >= nums-n){
            sum += sums.back();
        }
    }
    return sum;
}

long long Functions::rowSumOddNumbers_better(unsigned int n) {
    //1^3 = 1, 2^3 = 8, 3^3 = 27 and so on..
    return n*n*n;
}

int Functions::convertFromRoman(const std::string &roman) {
    std::map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
    auto sum = 0;
    for(auto it = begin(roman); it != end(roman);){
        int valThis = values.find(*it)->second;
        int valNext = values.find(*(std::next(it)))->second;
        if(valThis < valNext) {
            sum += valNext - valThis;
            it += 2;
        } else {
            sum += valThis;
            it++;
        }
    }
    return sum;

}


std::string Functions::likes(const std::vector<std::string> &names)
{
    switch(names.size()){
        case 0:
            return "no one likes this";
        case 1:
            return names[0] + " likes this";
        case 2:
            return names[0] + " and " + names[1] + " like this";
        case 3:
            return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default:
            return names[0] + ", " + names[1] + " and " + std::to_string(names.size()-2) + " others like this";
    }
}