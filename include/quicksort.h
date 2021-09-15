#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

class MytSQ {

public:
    static int swaps;
    void swap(std::vector<int> &a, int i, int j) {
        std::cout << "\t\tswap " << i << ":" << j << " : ";

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int c = a[i];
        a[i] = a[j];
        a[j] = c;

        auto n = a.size();
        for (auto s: a)
            std::cout << s << (--n ? ", " : "\n");
    }

    int partition(std::vector<int> &a, int l, int r) {
        auto n = a.size();
        std::cout << "\tpr: ";
        for (auto s: a)
            std::cout << s << (--n ? ", " : "\n");
        int v = a[r - 1];//a[(l+r)/2];
        std::cout << "\tpr idx: " << r - 1 << std::endl;
        int i = l;
        int j = r;
        while (i <= j) {
            while (a[i] < v)
                ++i;
            while (a[j] > v)
                --j;
            if (i >= j)
                break;
            swap(a, i++, j--);
        }
        return j;
    }

    void quicksort(std::vector<int> &a, int l, int r) {
        if (l == r) return;
        auto n = a.size();
        std::cout << "qs(" << l << ":" << r << "):";
        for (auto s: a)
            std::cout << s << (--n ? ", " : "\n");
        if (l < r) {
            int q = partition(a, l, r);
            std::cout << "qs par idx: " << q << "\n";
            quicksort(a, l, q);
            quicksort(a, q + 1, r);
        }
    }
};//MySQ
int MytSQ::swaps;

