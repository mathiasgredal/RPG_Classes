#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

struct Character {
    std::string name;
    int xp;
    int level;
};

class Party {
public:
    Party();
    void read_names();
    void read_xp_level();
    void print();
    void sort();

private:
    std::vector<Character> characters;
};

#endif // PARTY_H
