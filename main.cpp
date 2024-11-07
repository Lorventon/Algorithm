#include "iostream"
#include "Yandex/6_0/6.0_2.h"
#include "vector"
#include "cmath"
#include "unordered_set"
#include "algorithm"

using u_v = std::vector <unsigned int>;

int main() {

    unsigned n; std::cin >> n;
    std::vector <u_v> reverse_interes(n, u_v(3));
    std::vector <u_v> reverse_profit(n, u_v(3));
    u_v mood(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> reverse_interes[i][0];
        reverse_interes[i][2] = i+1;
    }
    for (int i = 0; i < n; ++i)
    {
        reverse_profit[i][0] = reverse_interes[i][0];
        std::cin >> reverse_profit[i][1];
        reverse_profit[i][2] = i+1;
    }
    for (int i = 0; i < n; ++i)
    {
        reverse_interes[i][1] = reverse_profit[i][1];
    }

    std::sort(reverse_interes.begin(), reverse_interes.end(),
              [](const u_v& a,const u_v& b){return a[0] > b[0];});

    std::sort(reverse_profit.begin(), reverse_profit.end(),
              [](const u_v& a,const u_v& b){return a[1] > b[1];});

    for (int i = 0; i < n; ++i) {
        std::cin >> mood[i];
    }

    //Переделать под массив словарей  (где ключ - индекс, а значение - это пара (интенсивность, полезность)
    unsigned int min_ind = n, mood_i, max_profit, max_interes, cur_profit;
    unsigned j = 0;
    u_v ans(n);
    std::unordered_set <int> index;
    unsigned int right;
    while (index.size() != n) {
        mood_i = mood[0];
        right = 1;
        if (mood_i) {
            max_profit = reverse_profit[0][1];
            min_ind = reverse_profit[0][2];
            while (right < n && reverse_profit[right][1] == max_profit) {
                if (index.find(reverse_profit[right][2]) == index.end()) {continue;}
                else if (min_ind > reverse_profit[right][2]) {
                    min_ind = reverse_profit[right][2];
                }
                ++right;
            }
            ans[j++] = min_ind;
            index.insert(min_ind);
        } else if (!mood_i) {
            max_interes = reverse_interes[0][0];
            min_ind = reverse_interes[0][2];
            max_profit = reverse_interes[0][1];
            while (right < n && reverse_interes[right][0] == max_interes) {
                if (index.find(reverse_interes[right][2]) != index.end()) { continue;}
                else if (reverse_interes[right][1] > max_profit) {
                    min_ind = reverse_interes[right][2];
                    max_profit = reverse_interes[right][1];
                }
                ++right;
            }
            ans[j++] = min_ind;
            index.insert(min_ind);
        }
    }

    for (const auto& it : ans)
    {
        std::cout << it << " ";
    }
    return 0;
}