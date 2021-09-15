//
// Created by boris on 14.09.2021.
//

#ifndef UNTITLED_MEDIAN2VECTOR_H
#define UNTITLED_MEDIAN2VECTOR_H
#include <vector>

using namespace std;

class Median2VectorSolution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    double findKth_smallest(vector<int>& v1, vector<int>& v2, int K, bool is_even);
};

double Median2VectorSolution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int K;
    int N = nums1.size() + nums2.size();
    K = 0.5 * (N+1);
    bool is_even (N%2 == 0);
    return findKth_smallest(nums1, nums2, K,  is_even );
}

double Median2VectorSolution::findKth_smallest(vector<int> &v1, vector<int> &v2, int K, bool is_even) {
    auto i1 = v1.begin();
    auto i2 = v2.begin();
    double medianl, medianh;
    if (is_even)
        ++K;
    while (i1 != v1.end() and i2 != v2.end() and K--) {
        if (*i1 < *i2) {
            medianl = medianh;
            medianh = *i1;
            ++i1;
        } else {
            medianl = medianh;
            medianh = *i2;
            ++i2;
        }
    }
    if ( K > 0){
        auto tail = i1;
        auto &seq = v1;
        if (tail == v1.end()) {
            tail = i2;
            seq = v2;
        }
        while ( tail != seq.end() and K--) {
            medianl = medianh;
            medianh = *tail;
            ++tail;
        }
    }
    if (is_even)
        return 0.5 * (medianh + medianl);
    else
        return medianh;

 }

#endif //UNTITLED_MEDIAN2VECTOR_H
