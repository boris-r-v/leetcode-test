#include "../include/quicksort.h"
#include "../include/median2vector.h"
#include <cassert>


void run_qs(){
    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3, 1};
    MytSQ myqs;
    myqs.quicksort(v, 0, v.size()-1);


    auto n = v.size();
    for (auto s : v)
        std::cout << s << (--n?", ":"\n");

    std::cout << "Swaps: " <<myqs.swaps << std::endl;
}
using namespace std;
double run_m2v(vector<int> v1, vector<int> v2)
{
    Median2VectorSolution sil;
    double ret =sil.findMedianSortedArrays(v1, v2);
    cout << "run_m2v: " << ret << std::endl;
    return ret;
}


int main()
{
//    run_qs();
    assert(run_m2v({1,3}, {2})==2);
    assert(run_m2v({1,2}, {3,4})==2.5);
    assert(run_m2v({3,4}, {1,2})==2.5);
    assert(run_m2v({11,12,13}, {1,5,7,8,9})==8.5);
    assert(run_m2v({11,12}, {1,5,7,8,9})==8.0);

    return 0;
}
