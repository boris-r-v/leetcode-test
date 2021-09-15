/**
 * Created by boris on 15.09.2021.
 * Расчет Z-функции строки: http://e-maxx.ru/algo/z_function
 * Есть строка ааааббc е Zfunc [0,4,3,2,1,2,3,0]
 * Определения:
 * строка - последовательность символов.
 * подстрока - последовательность подряд идущих символов в строке.
 * префикс - подстрока, начинающаяся с первого символа строки.
 * суффукс - подстрока, заканчивающаяся на последний символ строки.
 *    Z-функция от строки S - массив Z, каждый элемент которого Z[i] равен длиннейшему префиксу подстроки, начинающейся с
 * позиции i в строке S, который одновременно является и префиксом всей строки S. Значение Z-функции в нулевой позиции
 * обычно равно или нулю, или длине всей строки. Сложность: O(|S| ^ 2) или O(|S|).
 *    Префикс-функция от строки S - массив P, каждый элемент которого P[i] равен длиннейшему суффиксу подстроки,
 * начинающейся с позиции i в строке S, который одновременно является и суффиксом всей строки S. Значение P-функции в
 * нулевой позиции обычно равно или нулю, или длине всей строки. Сложность: O(|S| ^ 2) или O(|S|).
 *
 *
*/

#ifndef UNTITLED_Z_FUNC_OF_STRING_H
#define UNTITLED_Z_FUNC_OF_STRING_H
#include <string>
#include <vector>

using namespace std;
class Z_function_Solution
{
public:
    vector<int> find_z_func_trivial(string s);
    vector<int> find_z_func_On(string s);
    vector<int> find_z_func_On_from_book(string s);
};

vector<int> Z_function_Solution::find_z_func_trivial(string s) {
    auto n = s.size();
    vector<int> d (n, 0);

    for( int i=1; i< s.size(); ++i){
        while(i+d[i]<n and s[d[i]] == s[i+d[i]])
            ++d[i];
    }
    //cout << "d: {"; for (auto i : d ) cout << i << (--n ? ", " : "}\n");
    return d;
}
vector<int> Z_function_Solution::find_z_func_On(string s){
    auto n = s.size();
    vector<int> d (n, 0);

    for( int i=1, l=0, r=0; i< s.size(); ++i) {
        if (l > 0 and r > l and r > i) {
/**     Идея в том, что если нам известны значения от d[1] до d[120], и на 120 шаге r=130, l=100
 *  То это означает, то подстрока длинной 31 символ начинающиеся с 100 го символа совпадает с 31-символьным префикстом
 *  строки. Пожэтому подстрока длины 10 с позиции 121 сопадавет с подстрокой длины 10 начинающиеся с символа 22 =>
 *  d[121]=d[22].
 *          //r=130,l=100,i=121
 *          int pref_len = r - l + 1; //31 - определили длину известного префикса
 *          int suf_prev_len = r - i + 1; //10 - определили длину совпадающих подстрок с позиций 121 и 22
 *          int z_idx = pref_len - suf_prev_len + 1; //22 - нашли номер индекса в префиксе с которого должно быть совпадение
 *          d[i] = d[z_idx];    //пересохранили значения
*/
            d[i] = d[l+i+2];    //// упростили выражение r-l+1-(r-i+1) = l+i+2
            l=i;                //// вычислим новое значение l
            r=i+d[i];           //// вычислим новое значение r
            continue;
        }
        while(i+d[i]<n and s[d[i]] == s[i+d[i]])
            ++d[i];

        if(0!=d[0]) l=i, r=i+d[i];
        else l=0, r=0;
    }
    //cout << "d: {"; for (auto i : d ) cout << i << (--n ? ", " : "}\n");
    return d;
}
vector<int> Z_function_Solution::find_z_func_On_from_book(string s) {
    //// Описание алгоритма в http://e-maxx.ru/algo/z_function
    int n = s.size();
    vector<int> Z (n, 0);
    for (int k=1, l=0, r=0; k < n; ++k) {
        if (r >= k)
            Z[k] = min (r - k + 1, Z[k - l]);

        while (k + Z[k] < n && s[Z[k]] == s[k + Z[k]])
            ++Z[k];
        if (k + Z[k] - 1 > r)   //// В Строки,деревья и последов./Д.Гасфилд,Стр.29,написано: if (Z[k]>0) l=k,r=k+Z[k]-1 - таким условием тесты тоже проходят
            l = k, r = k + Z[k] - 1;
    }
    return Z;
    //cout << "Z: {"; for (auto i : Z ) cout << i << (--n ? ", " : "}\n");

}
#endif //UNTITLED_Z_FUNC_OF_STRING_H
