// A. Плейлисты
#include "5.0_3.h"

//3 contest
namespace FiftAlgoritms_3 {
    void A() {
        unsigned cnt_numbers;
        unsigned all_good_songs = 0;
        std::cin >> cnt_numbers;

        std::map<std::string, unsigned> m_map;

        for (int i = 0; i < cnt_numbers; ++i) {
            unsigned int cnt_songs;
            std::string song;
            std::cin >> cnt_songs;
            for (int j = 0; j < cnt_songs; ++j) {
                std::cin >> song;
                m_map[song]++;
                if (m_map[song] == cnt_numbers) { ++all_good_songs; }
            }
        }
        std::cout << all_good_songs << std::endl;
        for (const auto &pair: m_map) {
            if (pair.second == cnt_numbers) { std::cout << pair.first << " "; }
        }
    }

    void B() {
        std::unordered_map<char, unsigned> amount_char;
        std::string str1, str2;
        std::cin >> str1 >> str2;
        for (const char &ch: str1)
            amount_char[ch]++;

        for (const char &ch: str2)
            amount_char[ch]--;

        bool check = std::all_of(amount_char.begin(), amount_char.end(),
                                 [](const auto &pair) { return pair.second == 0; });

        switch (check) {
            case true:
                std::cout << "YES";
                break;
            case false:
                std::cout << "NO";
                break;
        }
    }

    void C() {
        std::map<unsigned, unsigned> m_numbers;
        unsigned n, max_cnt = 0;
        std::cin >> n;
        bool check = true;
        for (int i = 0; i < n; ++i) {
            unsigned num;
            std::cin >> num;
            m_numbers[num]++;
        }

        std::pair<unsigned, unsigned> last, cur;
        for (const std::pair<unsigned, unsigned> &pair: m_numbers) {
            if (check) {
                last = pair;
                cur = last;
                check = false;
                continue;
            }
            last = cur;
            cur = pair;
            if (unsigned value = abs(cur.first - last.first); value == 0 || value == 1) {
                if (unsigned value = cur.second + last.second; value > max_cnt) {
                    max_cnt = value;
                }
            }
        }


        if (max_cnt == 0) {
            if (m_numbers.size() == 1) { std::cout << 0; }
            else { std::cout << n - 1; }
        } else {
            std::cout << n - max_cnt;
        }
    }

    int D() {
        std::unordered_map<int, unsigned> my_nums;
        unsigned n, k;
        std::cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            if (my_nums.find(num) == my_nums.end()) {
                my_nums[num] = i;
            } else {
                if (i - my_nums[num] <= k) {
                    std::cout << "YES";
                    return 0;
                } else {
                    my_nums[num] = i;
                }
            }
        }

        std::cout << "NO";
        return 0;
    }

    namespace TaskE {

        void add_to_set(std::set<int> &set) {
            unsigned n;
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                int num;
                std::cin >> num;
                set.insert(num);
            }
        }

        std::set<int> intersaction(std::set<int> set1, std::set<int> set2) {
            std::set<int> new_set;

            for (const auto &el: set1) {
                if (set2.find(el) != set2.end()) {
                    new_set.insert(el);
                }
            }
            return new_set;
        }

        void print_set(std::set<int> set) {
            for (const auto &el: set)
                std::cout << el << " ";
        }

        void E() {


            std::set<int> m_nums, m_nums2, m_nums3;

            add_to_set(m_nums);
            add_to_set(m_nums2);
            add_to_set(m_nums3);

            std::set<int> inter_12 = intersaction(m_nums, m_nums2);
            std::set<int> inter_13 = intersaction(m_nums, m_nums3);
            std::set<int> inter_23 = intersaction(m_nums2, m_nums3);

            inter_12.insert(inter_13.begin(), inter_13.end());
            inter_12.insert(inter_23.begin(), inter_23.end());

            print_set(inter_12);
        }
    }

    namespace TaskF {
        void print_collection(const std::unordered_set<std::string> &a) {
            for (const auto &el: a)
                std::cout << el << std::endl;
        }

        void print_collection(const std::vector<std::string> &a) {
            for (const auto &el: a)
                std::cout << el << " ";
        }

        void F() {
            std::unordered_set<std::string> dictionary;
            std::vector<std::string> words;

            {
                std::string my_str;
                std::getline(std::cin, my_str);
                std::istringstream iss(my_str);

                std::string str;

                while (iss >> str)
                    dictionary.insert(str);

                std::getline(std::cin, my_str);
                std::istringstream iss2(my_str);

                while (iss2 >> str) {
                    words.emplace_back(str);
                }
            }

            for (int i = 0; i < words.size(); ++i) {
                for (int j = 1; j < words[i].length(); ++j) {
                    std::string substr = (words[i].substr(0, j));
                    if (dictionary.find(substr) != dictionary.end()) {
                        words[i] = substr;
                        break;
                    }
                }
            }

            print_collection(words);
        }
    }
}