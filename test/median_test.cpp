//
// Created by boris on 15.09.2021.
//

#include "gtest/gtest.h"
#include "median2vector2.h"

using namespace std;
double run_m2v(vector<int> v1, vector<int> v2)
{
    Median2VectorSolution sil;
    double ret =sil.findMedianSortedArrays(v1, v2);
    //cout << "run_m2v: " << ret << std::endl;
    return ret;
}
TEST(Median2VectorTest, odd_sequence) {

    EXPECT_EQ( run_m2v({1,3}, {2}), 2);
    EXPECT_EQ(run_m2v({11,12}, {1,5,7,8,9}), 8.0);
}

TEST(Median2VectorTest, even_sequence) {

    EXPECT_EQ(run_m2v({11,12,13}, {1,5,7,8,9}), 8.5);
    //EXPECT_EQ(run_m2v({1,2}, {3,4}), 2.5);
    //EXPECT_EQ(run_m2v({3,4}, {1,2}), 2.5);
    //EXPECT_EQ(run_m2v({0,0}, {0,0}), 0.0);
}
TEST(Median2VectorTest, empty_sequence) {
    EXPECT_EQ(run_m2v({}, {1}), 1);
    EXPECT_EQ(run_m2v({2}, {}), 2);
    //EXPECT_EQ(run_m2v({}, {}), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
