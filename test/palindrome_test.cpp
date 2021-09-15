//
// Created by boris on 15.09.2021.
//

#include "gtest/gtest.h"
#include "palindroms.h"


using namespace std;

TEST(PalindromTest, palindrome_trivial_test) {
    Palindrome_Solution s;
    EXPECT_EQ( s.longest_palindrome_trivial("babad"), "aba");

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//
// Created by boris on 15.09.2021.
//

