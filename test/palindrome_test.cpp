//
// Created by boris on 15.09.2021.
//

#include "gtest/gtest.h"
#include "palindroms.h"


using namespace std;
TEST(PalindromTest, palindrome_my_fast) {
    Palindrome_Solution s;
    EXPECT_EQ( s.longest_palindrome_my_fast("a"), "a");
    EXPECT_EQ( s.longest_palindrome_my_fast("ax"), "a");
    EXPECT_EQ( s.longest_palindrome_my_fast("babad"), "bab");
    EXPECT_EQ( s.longest_palindrome_my_fast("aabaabab"), "abaaba");
    EXPECT_EQ( s.longest_palindrome_my_fast("ccddee"), "cc");
    EXPECT_EQ( s.longest_palindrome_my_fast("ccdddee"), "ddd");
    EXPECT_EQ( s.longest_palindrome_my_fast("accddccx"), "ccddcc");
    EXPECT_EQ( s.longest_palindrome_my_fast("bacabab"), "bacab");


}
TEST(PalindromTest, palindrome_trivial_test) {
    Palindrome_Solution s;
    EXPECT_EQ( s.longest_palindrome_trivial("a"), "a");
    EXPECT_EQ( s.longest_palindrome_trivial("ax"), "a");
    EXPECT_EQ( s.longest_palindrome_trivial("babad"), "bab");
    EXPECT_EQ( s.longest_palindrome_trivial("aabaabab"), "abaaba");
    EXPECT_EQ( s.longest_palindrome_trivial("ccddee"), "cc");
    EXPECT_EQ( s.longest_palindrome_trivial("ccdddee"), "ddd");
    EXPECT_EQ( s.longest_palindrome_trivial("accddccx"), "ccddcc");
    EXPECT_EQ( s.longest_palindrome_trivial("bacabab"), "bacab");


}
TEST(PalindromTest, palindrome_from_leetcode) {
    Palindrome_Solution s;
    /*EXPECT_EQ( s.longest_palindrome_from_leetcode("a"), "a");
    EXPECT_EQ( s.longest_palindrome_from_leetcode("ax"), "a");*/
    EXPECT_EQ( s.longest_palindrome_from_leetcode("babad"), "bab");
    /*EXPECT_EQ( s.longest_palindrome_from_leetcode("aabaabab"), "abaaba");
    EXPECT_EQ( s.longest_palindrome_from_leetcode("ccddee"), "cc");
    EXPECT_EQ( s.longest_palindrome_from_leetcode("ccdddee"), "ddd");
    EXPECT_EQ( s.longest_palindrome_from_leetcode("accddccx"), "ccddcc");
    EXPECT_EQ( s.longest_palindrome_from_leetcode("bacabab"), "bacab");
    EXPECT_EQ( s.longest_palindrome_from_leetcode("abcdefjfedcpo"), "cdefjfedc");
*/

}
TEST(PalindromTest, palindrome_MAXimal_test) {
    Palindrome_Solution s;
    EXPECT_EQ( s.longest_palindrome_from_MAXimal("babad"), "aba");

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//
// Created by boris on 15.09.2021.
//

