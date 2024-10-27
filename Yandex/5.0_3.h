#ifndef TEST_2_5_0_3_H
#define TEST_2_5_0_3_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <iostream>

namespace FiftAlgoritms {
    void A();

    void B();

    void C();

    int D();

    namespace TaskE {
        void add_to_set(std::set<int> &set);

        std::set<int> intersaction(std::set<int> set1, std::set<int> set2);

        void print_set(std::set<int> set);

        void E();
    }

    namespace TaskF {
        void print_collection(const std::unordered_set<std::string> &a);

        void print_collection(const std::vector<std::string> &a);

        void F();
    }
}

#endif //TEST_2_5_0_3_H
