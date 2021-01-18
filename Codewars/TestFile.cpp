#include "gtest/gtest.h"
#include "Functions.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Functions, DNAStrand) {
    std::map<std::string, std::string> strings = {
            { "ATGTT", "TACAA" },
            { "A", "T" },
            { "G", "C" },
            { "GCTAATGC", "CGATTACG" }
    };

    for(auto&& pair : strings){
        ASSERT_EQ(Functions::DNAStrand(pair.first), pair.second);
    }
}

TEST(Functions, get_sum){
    ASSERT_EQ(Functions::get_sum(0, -1), -1);
    ASSERT_EQ(Functions::get_sum(0, 1), 1);
    ASSERT_EQ(Functions::get_sum(2, 5), 14);
    ASSERT_EQ(Functions::get_sum(5, 2), 14);
    ASSERT_EQ(Functions::get_sum(-1, -2), -3);
    ASSERT_EQ(Functions::get_sum(-3, -3), -3);
}

TEST(Functions, accumTest) {
    ASSERT_EQ(Functions::accum("ZpglnRxqenU"), "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
    ASSERT_EQ(Functions::accum("NyffsGeyylB"), "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
    ASSERT_EQ(Functions::accum("abcd"), "A-Bb-Ccc-Dddd");
    ASSERT_EQ(Functions::accum("RqaEzty"), "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
    ASSERT_EQ(Functions::accum("cwAt"), "C-Ww-Aaa-Tttt");
}

TEST(Functions, is_isogram){
    ASSERT_EQ(Functions::is_isogram("Dermatoglyphics"), true);
    ASSERT_EQ(Functions::is_isogram("moose"), false);
    ASSERT_EQ(Functions::is_isogram("mOose"), false);
    ASSERT_EQ(Functions::is_isogram("SomeWord"), false);
    ASSERT_EQ(Functions::is_isogram(""), false);
}

TEST(Functions, is_perfect_square){
    ASSERT_EQ(Functions::is_perfect_square(-1), false);
    ASSERT_EQ(Functions::is_perfect_square(-4), false);
    ASSERT_EQ(Functions::is_perfect_square(0), true);
    ASSERT_EQ(Functions::is_perfect_square(3), false);
    ASSERT_EQ(Functions::is_perfect_square(4), true);
    ASSERT_EQ(Functions::is_perfect_square(25), true);
    ASSERT_EQ(Functions::is_perfect_square(26), false);
}

TEST(Functions, comp){
    ASSERT_EQ(Functions::comp(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{14641, 20736, 361, 25921, 361, 20736, 361, 121}),
            true
            );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{14641, 20736, 361, 25921, 361, 20736, 362, 121}),
              false
    );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{},
            std::vector<int>{}),
            true
    );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{132, 14641, 20736, 361, 25921, 361, 20736, 361}),
              false
    );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{121, 14641, 20736, 36100, 25921, 361, 20736, 361}),
              false
    );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{121, 14641, 20736, 36100, 361, 20736, 361}),
              false
    );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{11, 11},
            std::vector<int>{121}),
              false
    );
    ASSERT_EQ(Functions::comp(
            std::vector<int>{11, 11},
            std::vector<int>{121, 121, 134}),
              false
    );
}

TEST(Functions, comp_better){
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{14641, 20736, 361, 25921, 361, 20736, 361, 121}),
              true
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{14641, 20736, 361, 25921, 361, 20736, 362, 121}),
              false
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{},
            std::vector<int>{}),
              true
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{132, 14641, 20736, 361, 25921, 361, 20736, 361}),
              false
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{121, 14641, 20736, 36100, 25921, 361, 20736, 361}),
              false
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{121, 144, 19, 161, 19, 144, 19, 11},
            std::vector<int>{121, 14641, 20736, 36100, 361, 20736, 361}),
              false
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{11, 11},
            std::vector<int>{121}),
              false
    );
    ASSERT_EQ(Functions::comp_better(
            std::vector<int>{11, 11},
            std::vector<int>{121, 121, 134}),
              false
    );
}

TEST(Functions, rowSumOddNumbers){
    ASSERT_EQ(Functions::rowSumOddNumbers(1), 1);
    ASSERT_EQ(Functions::rowSumOddNumbers(2), 8);
    ASSERT_EQ(Functions::rowSumOddNumbers(3), 27);
    ASSERT_EQ(Functions::rowSumOddNumbers(42), 74088);
}

TEST(Functions, rowSumOddNumbers_better){
    ASSERT_EQ(Functions::rowSumOddNumbers_better(1), 1);
    ASSERT_EQ(Functions::rowSumOddNumbers_better(2), 8);
    ASSERT_EQ(Functions::rowSumOddNumbers_better(3), 27);
    ASSERT_EQ(Functions::rowSumOddNumbers_better(42), 74088);
}

TEST(Functions, convertFromRoman){
    ASSERT_EQ(Functions::convertFromRoman("XXI"), 21);
    ASSERT_EQ(Functions::convertFromRoman("I"), 1);
    ASSERT_EQ(Functions::convertFromRoman("IV"), 4);
    ASSERT_EQ(Functions::convertFromRoman("VI"), 6);
    ASSERT_EQ(Functions::convertFromRoman("MMVIII"), 2008);
    ASSERT_EQ(Functions::convertFromRoman("MDCLXVI"), 1666);
    ASSERT_EQ(Functions::convertFromRoman("MCMXCIV"), 1994);
}


TEST(Functions, likes){
    auto&& names = std::vector<std::vector<std::string>>{
      {},
      {"Peter"},
      {"Jacob", "Alex"},
      {"Max", "John", "Mark"},
      {"Alex", "Jacob", "Mark", "Max"}};
    ASSERT_EQ(Functions::likes(names[0]), "no one likes this");
    ASSERT_EQ(Functions::likes(names[1]), "Peter likes this");
    ASSERT_EQ(Functions::likes(names[2]), "Jacob and Alex like this");
    ASSERT_EQ(Functions::likes(names[3]), "Max, John and Mark like this");
    ASSERT_EQ(Functions::likes(names[4]), "Alex, Jacob and 2 others like this");
}
