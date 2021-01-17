#include <algorithm>
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