#include "6.0_1.h"

namespace SixthAlgoritms {
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
}