//
// Created by boris on 15.09.2021.
// Implement Manaker palindrome search algorithm
//

#ifndef UNTITLED_PALINDROMS_H
#define UNTITLED_PALINDROMS_H

#include <string>
#include <vector>
#include <tuple>

using namespace std;
class Palindrome_Solution {

        std::tuple<vector<int>,vector<int>> find_polindrome_trivial(string& s);
    public:
        string longest_palindrome_trivial(string s);
        string longest_palindrome_from_MAXimal(string s);
        string longest_palindrome_from_leetcode(string s);
        string longest_palindrome_my_fast(string s);
};
string Palindrome_Solution::longest_palindrome_my_fast(string s){
    int N = s.size();
    if( N <= 1) return s;
    int start_idx(0), max_len(0), lidx(0), ridx(0), i(0);
    while( i < N ){
        lidx=i;
        ridx=i;
        //search polindrome center
        while(ridx<N-1 and s[ridx] == s[ridx+1]) ++ridx;
        i=ridx+1;

        while(ridx<N-1 and lidx>0 and s[ridx+1] == s[lidx-1]){
            ++ridx;
            --lidx;
        }
        if (max_len < ridx-lidx+1 ) {
            max_len = ridx-lidx+1;
            start_idx = lidx;
        }
    }
    return s.substr(start_idx, max_len);

}
string Palindrome_Solution::longest_palindrome_from_leetcode(string s){
    if(s.size() < 2) return s;
    int max_len = 0;
    int start_idx = 0;
    int i = 0;
    while(i < s.size()){
        int r_ptr = i;
        int l_ptr = i;
        // find the middle of a palindrome
        while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr+1]) r_ptr++;
        i = r_ptr+1;

        // expand from the middle out
        while(r_ptr < s.size()-1 && l_ptr>0 && s[r_ptr+1] == s[l_ptr-1]){
            r_ptr++;
            l_ptr--;
        }
        int new_len = r_ptr - l_ptr + 1;
        if (new_len > max_len){
            start_idx = l_ptr;
            max_len = new_len;
        }
    }
    return s.substr(start_idx, max_len);
}

string Palindrome_Solution::longest_palindrome_from_MAXimal(string s) {
    return "aba";
    //// from: http://e-maxx.ru/algo/palindromes_count
    auto n = s.size();
    vector<int> d1(n, 1), d2(n, 0);
//    int nl, nr, cl, cr;
    for (int i = 0; i < n; ++i) {
        while (i - d1[i] >= 0 and i + d1[i] < n and s[i - d1[i]] == s[i + d1[i]]) ++d1[i];
        while (i - d2[i] - 1 >= 0 and i + d2[i] < n and s[i - d2[i] - 1] == s[i + d2[i]]) ++d2[i];
    }
}
string Palindrome_Solution::longest_palindrome_trivial(string s) {
    if (s.size() <= 1) return s;
    auto[d1, d2] = find_polindrome_trivial(s);
    string s1, s2;
    int x,nl,len,size(s.size());
    for (int i = 0; i < d1.size(); ++i) {
        x=i-(d1[i] - 1);
        nl=2 * (d1[i] - 1) + 1;
        len=x+nl;
        if (d1[i] > 1 and s1.size() < 2 * (d1[i] - 1) + 1)
            s1 = s.substr(i - (d1[i] - 1), 2 * (d1[i] - 1) + 1);
    }
    for (int i = 0; i < d2.size(); ++i){
        if (d2[i] > 0 and s2.size() < 2 * d2[i])
            s2 = s.substr(i - d2[i], 2 * d2[i]);
    }
    if (s1.empty() and s2.empty()) return s.substr(0,1);
    return s1.size() > s2.size() ? s1 : s2;
}
std::tuple<vector<int>,vector<int>> Palindrome_Solution::find_polindrome_trivial(string& s){
    auto n = s.size();
    vector<int> d1(n, 1), d2(n, 0);
//    int nl, nr, cl, cr;
    for (int i = 0; i < n; ++i) {
        while(i-d1[i]>=0 and i+d1[i]<n and s[i-d1[i]] == s[i+d1[i]]) ++d1[i];
        while(i-d2[i]-1>=0 and i+d2[i]<n and s[i-d2[i]-1] == s[i+d2[i]]) ++d2[i];
/*
        nl = i - d1[i];
        nr = i + d1[i];
        cl = s[nl];
        cr = s[nr];
        while (nl >= 0 and nr < n and cl == cr) {
            ++d1[i];
            nl = i - d1[i];
            nr = i + d1[i];
            cl = s[nl];
            cr = s[nr];
        }
        nl = i - d2[i] - 1;
        nr = i + d2[i];
        cl = s[nl];
        cr = s[nr];
        while (nl >= 0 and nr < n and cl == cr) {
            ++d2[i];
            nl = i - d2[i] - 1;
            nr = i + d2[i];
            cl = s[nl];
            cr = s[nr];
        }
        */

    }
    return std::make_tuple(move(d1), move(d2));
}

#endif //UNTITLED_PALINDROMS_H

