//
// Created by boris on 15.09.2021.
//

#include "gtest/gtest.h"
#include "palindroms.h"


using namespace std;
string run_pol(string s)
{
    Solution solution;
    return solution.longestPalindrome( s );

}

TEST(PalindromTest, leetcode_test) {
    EXPECT_EQ( run_pol("babad"), "aba");

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//
// Created by boris on 15.09.2021.
//

