#include "6.0_2.h"

namespace SixthAlgorithms_2
{
    //taskA is too easy;
    int taskB() {
        unsigned N, K, ans = 0, last = 1;
        std::cin >> N >> K;
        std::vector<unsigned> cars(N), prefix(N + 1);
        prefix[0] = 0;
        for (int i = 0; i < N; ++i) {
            std::cin >> cars[i];
            prefix[i + 1] = prefix[i] + cars[i];
        }

        for (unsigned first = 0; first < N; ++first) {
            while (last < N + 1 && prefix[last] - prefix[first] < K)
                ++last;
            if (prefix[last] - prefix[first] == K)
                ++ans;
        }

        std::cout << ans;

        return 0;
    }
    int taskC() {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> vec (n);

        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }
        std::sort(vec.begin(), vec.end());

        int left = 0, right = 0,max_len = 0;
        bool check = true;
        for (left = 0; left < n; ++left) {
            if (!check || max_len == n) {break;}
            while (right < n) {
                while (vec[right] - vec[left] <= k && right < n) { ++right; }
                if (right < n && vec[right] - vec[left] > k) {
                    max_len = std::max(max_len, right - left);
                    break;
                }
                else if(right == n && vec[right-1] - vec[left] <= k)
                {
                    max_len = std::max(max_len, right - left);
                    check = false;
                    break;
                }

            }
        }
        if (!max_len) {std::cout << 1;}
        else {std::cout << max_len;}
        return 0;
    }
    int taskD() {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> vec (n);

        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }
        std::sort(vec.begin(), vec.end());

        int left = 0, right = 0,max_len = 0;
        bool check = true;
        for (left = 0; left < n; ++left) {
            if (!check || max_len == n) {break;}
            while (right < n) {
                while (vec[right] - vec[left] <= k && right < n) { ++right; }
                if (right < n && vec[right] - vec[left] > k) {
                    max_len = std::max(max_len, right - left);
                    break;
                }
                else if(right == n && vec[right-1] - vec[left] <= k)
                {
                    max_len = std::max(max_len, right - left);
                    check = false;
                    break;
                }

            }
        }
        if (!max_len) {std::cout << 1;}
        else {std::cout << max_len;}
        return 0;


    }
    int taskE() {
        int n, check_n;
        std::cin >> n;
        check_n = n;
        std::vector<int> v(n);
        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        int i = 0;
        if ((v.size() % 2)) {
            ans[0] = (v[n / 2]);
            v.erase(v.begin() + n / 2);
            --n;
            ++i;
        }
        int left = n / 2 - 1, right = n / 2;
        while (right < n)
        {
            ans[i] = (v[left]);
            ans[i+1] = (v[right]);
            --left;++right;
            i += 2;
        }


        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << " ";
        }
        return 0;
    }
    using ll = long long;
    int taskG() {
        ll c, cur_c = 0;
        bool check = true;
        int n, len = 0, max_len = 0, cnt_a = 0, cnt_b = 0, cnt_another = 0, left = 0, right = 0; std::cin >> n >> c;
        std::string str; std::cin >> str;

        for (left = 0; left < n; ++left)
        {
            while (cur_c <= c && right < n)
            {
                max_len = std::max(max_len, cnt_b + cnt_a + cnt_another);
                if (str[right] == 'a') {++cnt_a;}
                else if (str[right] == 'b') {++cnt_b; cur_c += cnt_a;}
                else {++cnt_another;}
                ++right;
            }
            if (right == n && cur_c <= c) {max_len = std::max(max_len, cnt_b + cnt_a + cnt_another);break;}
            if (str[left] == 'a') {cur_c -= cnt_b; --cnt_a;}
            else if (str[left] == 'b') {--cnt_b;}
            else {--cnt_another;}
            if (right == n && (cur_c > c) && !cnt_a) {break;}
        }

        std::cout << max_len;
        return 0;
    }
    namespace taskH
    {
        using ll = unsigned long long;

        void get_sum_of_prefix_sum(std::vector <ll>& vec, const std::vector <ll>& Prefix, ll n)
        {
            vec[0] = 0;
            for (int i = 1; i < n + 1; ++i)
            {
                vec[i] = vec[i-1] + Prefix[i];
            }
        }

        // Объяснение алгоритма;
        /*//Идея состоит в том, чтобы получить два массива, один будет на основе массива префиксных сумм, а другой
        // на основе reverse массива префиксных сумм.

        //Имеем итоговые данные
        // 5
        // 5 4 3 2 1
        // prefix_sum = [0,5,9,12,14,15]
        // reverse_prefix_sum = [0,1,3,6,10,15]
        // На основе prefix_sum делаем left_sum (left_sum[i] = left_sum[i-1] + prefix_sum[i])
        // left_sum = [0,5,14,26,40,55]
        // right_sum = [0,1,4,10,20,35]
        // А далее соспоставляем начальные данные и два массива. Получается, что
        // cost[i] = LeftSum[i-1] + RightSum[n-i];
        //Таким образом за O(n) получаем стоимость перезда для каждой комнаты*/

        int TaskH_() {
            int n; std::cin >> n;
            ll min_cost = pow(2,60);
            std::vector <ll> vec(n), PrefixSum(n+1), ReversePrefixSum(n+1);
            std::vector <ll> LeftSum(n+1), RightSum(n+1);
            PrefixSum[0] = 0;
            ReversePrefixSum[0] = 0;

            //Get data and prefix_sum
            for (int i = 0; i < n; ++i) {
                std::cin >> vec[i];
                PrefixSum[i + 1] = PrefixSum[i] + vec[i];
            }

            //Get reverse prefix_sum
            int j = 1;
            for (int i = n-1; i >= 0; --i)
            {
                ReversePrefixSum[j] = ReversePrefixSum[j-1] + vec[i];
                ++j;
            }

            //Получение массивов, которые состоят из ai, где ai - это сумма bi + b(i+1) (из массива префиксных сумм)
            get_sum_of_prefix_sum(LeftSum, PrefixSum, n);
            get_sum_of_prefix_sum(RightSum, ReversePrefixSum, n);

            //Поиск минимума
            j = 0;
            ll cost;
            for (int i = 1; i < n + 1; ++i)
            {
                cost = LeftSum[i-1] + RightSum[n-i];
                min_cost = std::min(min_cost, cost);
                ++j;
            }

            std::cout << min_cost;
            return 0;
        }
    }
}