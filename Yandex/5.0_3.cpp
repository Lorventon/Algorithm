// A. Плейлисты
#include "5.0_3.h"

//3 contest

void A()
{
    unsigned cnt_numbers;
    unsigned all_good_songs = 0;
    std::cin >> cnt_numbers;

    std::map<std::string, unsigned> m_map;

    for (int i = 0; i < cnt_numbers; ++i)
    {
        unsigned int cnt_songs;
        std::string song;
        std::cin >> cnt_songs;
        for (int j = 0; j < cnt_songs; ++j) {
            std::cin >> song;
            m_map[song]++;
            if (m_map[song] == cnt_numbers) {++all_good_songs;}
        }
    }
    std::cout << all_good_songs << std::endl;
    for (const auto& pair : m_map)
    {
        if (pair.second == cnt_numbers) {std::cout << pair.first << " ";}
    }
}

void B()
{
    std::unordered_map<char, unsigned> amount_char;
    std::string str1, str2; std::cin >> str1 >> str2;
    for (const char &ch: str1)
        amount_char[ch]++;

    for (const char &ch :str2)
        amount_char[ch]--;

    bool check = std::all_of(amount_char.begin(), amount_char.end(),
    [](const auto& pair) {return pair.second == 0;});

    switch (check) {
        case true:
            std::cout << "YES";
            break;
        case false:
            std::cout << "NO";
            break;
    }
}

void C()
{
    std::map <unsigned, unsigned> m_numbers;
    unsigned n, max_cnt = 0; std::cin >> n;
    bool check = true;
    for (int i = 0; i < n; ++i) {
        unsigned num;
        std::cin >> num;
        m_numbers[num]++;
    }

    std::pair <unsigned, unsigned> last, cur;
    for (const std::pair<unsigned, unsigned> &pair: m_numbers) {
        if (check) {
            last = pair;
            cur = last;
            check = false;
            continue;
        }
        last = cur;
        cur = pair;
        if (unsigned value = abs(cur.first - last.first); value == 0 || value == 1)
        {
            if (unsigned value = cur.second + last.second; value > max_cnt)
            {
                max_cnt = value;
            }
        }
    }

    if (max_cnt == 0)
    {
        if (m_numbers.size() == 1) {std::cout << 0;}
        else {std::cout << n - 1;}
    }
    else
    {
        std::cout << n - max_cnt;
    }
}