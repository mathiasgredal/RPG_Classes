#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>

// Used to generate UUIDs for characters
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

// Used for trimming strings
#include <boost/algorithm/string.hpp>

#include "equipment.h"
#include "money.h"

class Character {
private:
    std::string m_name;
    boost::uuids::uuid m_uuid;
    Money m_moneyBalance = Money(0);
    float m_maxLoad;
    std::vector<Equipment> m_equipment;

public:
    Character(std::string name, Money moneyBalance = Money(0), float maxLoad = 25, std::vector<Equipment> equipment = {}, boost::uuids::uuid uuid = boost::uuids::random_generator()());
    void print();

    // Getters
    std::string name() const;
    boost::uuids::uuid uuid() const;
    Money moneyBalance() const;
    float maxLoad() const;
    float currentLoad() const;
    std::vector<Equipment> getEquipment() const;

    // Setters
    void addMoneyToBalance(Money money);
    void takeMoneyFromBalance(Money moneyBalance);
    void setMaxLoad(float maxLoad);
    void addEquipment(Equipment equipment);
};

bool afford(const Character& character, Money money);
bool capacity(const Character& character, float extraweight);

#endif // CHARACTER_H
