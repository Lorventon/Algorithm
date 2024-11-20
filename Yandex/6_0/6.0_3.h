#ifndef TEST_2_6_0_3_H
#define TEST_2_6_0_3_H

#include "stack"
#include "iostream"
#include "vector"
#include "algorithm"

namespace SixthAlgoritms_3
{
    int taskA();
    int taskB();
    int taskC();
    int taskD();
    namespace taskE {
        void counting(const std::string&& s);
        bool isValidExpression(const std::string& expr);
        std::string trans_to_reverse_polish(const std::string& str);
        int taskE();
    }
    int taskF();
    int taskG();
    int taskH();
}

#endif //TEST_2_6_0_3_H
