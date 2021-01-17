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

TEST(Functions, )