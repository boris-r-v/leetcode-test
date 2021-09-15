//
// Created by boris on 15.09.2021.
//
#include <algorithm>
#include <climits>
#include <vector>

#ifndef UNTITLED_MEDIAN2VECTOR2_H
#define UNTITLED_MEDIAN2VECTOR2_H
using namespace std;

class Median2VectorSolution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2);
};
double Median2VectorSolution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
        nums1.swap(nums2);

    int n1 = nums1.size(), n2 = nums2.size();

    int l = 0, h = n1;
    //h - size vector with less size

    while (l <= h) {

        int i1 = (l + h) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int max1 = (i1 == 0 ? INT_MIN : nums1[i1 - 1]);
        int max2 = (i2 == 0 ? INT_MIN : nums2[i2 - 1]);

        int min1 = (i1 == n1 ? INT_MAX : nums1[i1]);
        int min2 = (i2 == n2 ? INT_MAX : nums2[i2]);

        double maxl = max(max1, max2);
        double minr = min(min1, min2);

        if (maxl <= minr) {
            if ((n1 + n2) % 2 == 0)
                return (maxl + minr) / 2;
            return maxl;
        } else if (min1 < max2)
            l = i1 + 1;
        else
            h = i1 - 1;
    }
    return 0;
}

double Median2VectorSolution::findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
    vector<float> num(nums1.size()+nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), num.begin() );
    //auto n = num.size();    cout <<"num: {";     for (auto i : num ) cout << i << (--n ? ", " : "}\n");
    return num.size()%2 != 0 ? /*odd*/ num[(num.size())/2] : /*even*/ 0.5*( num[-1+num.size()/2] + num[num.size()/2] );
}

#endif //UNTITLED_MEDIAN2VECTOR2_H
/*
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
*/