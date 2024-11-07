#include "6.0_1.h"

namespace SixthAlgoritms_1 {
    void A() {

        double min_dist = pow(2,50), cur_dist;
        std::string side;
        int x,y,x1,x2,x3,x4,y1,y2,y3,y4;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
        x3 = x2; y3 = y1; x4 = x1; y4 = y2;
        for (int i = x4; i <= x2; ++i)
        {
            if (cur_dist = sqrt(pow(i - x, 2) + pow(y4 - y, 2)), cur_dist < min_dist)
            {
                min_dist = cur_dist;
                if (i == x4)
                    side = "NW";
                else if (i == x2)
                    side = "NE";
                else
                    side = "N";
            }
        }

        for (int i = y2; i >= y3; --i)
        {
            if (cur_dist = sqrt(pow(i - y, 2) + pow(x2 - x, 2)), cur_dist < min_dist)
            {
                min_dist = cur_dist;
                if (i == y2)
                    side = "NE";
                else if (i == y3)
                    side = "SE";
                else
                    side = "E";
            }
        }

        for (int i = x3; i >= x1; --i)
        {
            if (cur_dist = sqrt(pow(i - x, 2) + pow(y3 - y, 2)), cur_dist < min_dist)
            {
                min_dist = cur_dist;
                if (i == x3)
                    side = "SE";
                else if (i == x1)
                    side = "SW";
                else
                    side = "S";
            }
        }

        for (int i = y1; i <= y4; ++i) {
            if (cur_dist = sqrt(pow(i - y, 2) + pow(x1 - x, 2)), cur_dist < min_dist)
            {
                min_dist = cur_dist;
                if (i == y1)
                    side = "SW";
                else if (i == y4)
                    side = "NW";
                else
                    side = "W";
            }
        }

        std :: cout << side;
    }
    void B()
    {
        int A, B, C, D;
        std::cin >> A >> B >> C >> D;
        std::pair<int, int> combination, temp;
        unsigned min_sum = pow(10,9)*4, cur_sum;

        // Получаем синий  + красный комплект (Гарантированно)
        // То есть Brute Force получение синего комплекта и также красного. (Нету рандомно выпавшей вещи)
        if (cur_sum = B + 1 + D + 1, cur_sum < min_sum && (A * B * C * D != 0)) {
            min_sum = cur_sum;
            combination.first = B + 1;
            combination.second = D + 1;
        }
        if (cur_sum = A + 1 + C + 1, cur_sum < min_sum && (A * B * C * D != 0)) {
            min_sum = cur_sum;
            combination.first = A + 1;
            combination.second = C + 1;
        }

        //Если чего-то просто ноль (Один из ответа будет 1, а второй - это
        if (cur_sum = C + 2, A == 0 and cur_sum < min_sum)
        {
            min_sum = cur_sum;
            combination.first = 1; combination.second = C + 1;
        }
        if (cur_sum = D + 2, B == 0 and cur_sum < min_sum)
        {
            min_sum = cur_sum;
            combination.first = 1; combination.second = D + 1;
        }
        if (cur_sum = A + 2, C == 0 and cur_sum < min_sum)
        {
            min_sum = cur_sum;
            combination.first = A + 1; combination.second = 1;
        }
        if (cur_sum = B + 2, D == 0 and cur_sum < min_sum)
        {
            min_sum = cur_sum;
            combination.first = B+1; combination.second = 1;
        }
        if ( (A == 0 and (C == 0 || D == 0)) || (B == 0 and (C == 0 || D == 0)))
        {
            min_sum = 2;
            combination.first = 1; combination.second = 1;
        }

        //Проверка, если футболок одинаково или носков одинаково (синих и красных)
        if (A == B && (A * B * C * D != 0))
        {
            if (cur_sum = std::max(C,D) + 2, A > C and A > D and cur_sum < min_sum && (A * B * C * D != 0))
            {
                min_sum = cur_sum;
                combination.first = 1; combination.second = std::max(C,D) + 1;
            }
        }
        if (C == D && (A * B * C * D != 0))
        {
            if (cur_sum = std::max(A,B) + 2, C > A and C > B and cur_sum < min_sum && (A * B * C * D != 0))
            {
                min_sum = cur_sum;
                combination.first = std::max(A,B) + 1; combination.second = 1;
            }
        }

        //Остальные случаи
        if (cur_sum = std::max(A,B) + 2, cur_sum < min_sum && (A * B * C * D != 0))
        {
            min_sum = cur_sum;
            combination.first = std::max(A,B) + 1; combination.second = 1;
        }
        if (cur_sum = std::max(C,D) + 2, cur_sum < min_sum && (A * B * C * D != 0))
        {
            min_sum = cur_sum;
            combination.first = 1; combination.second = std::max(C,D) + 1;
        }

        std::cout << combination.first << " " << combination.second;
    }
}