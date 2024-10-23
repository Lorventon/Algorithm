#ifndef TEST_2_5_0_3_H
#define TEST_2_5_0_3_H

#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

void A();
void B();
void C();
int D();

namespace TaskE
{
    void add_to_set(std::set <int> &set);

    std::set <int> intersaction(std::set <int> set1, std::set <int> set2);

    void print_set(std::set <int> set);

    void E();
}

#endif //TEST_2_5_0_3_H
