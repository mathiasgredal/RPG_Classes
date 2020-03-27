#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "money.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

enum EquipmentType { Weapon,
    Ammo,
    Armor,
    Trinket,
    Consumable };

class Equipment {
private:
    std::string m_name;
    Money m_price = Money(0);
    EquipmentType m_type;
    float m_weight;
    std::string m_description;
    bool m_ready;

public:
    Equipment(std::string name, Money price, EquipmentType type, float weight, std::string description, bool ready);

    std::string getName() const;
    Money getPrice() const;
    EquipmentType getType() const;
    std::string getTypeString() const;

    float getWeight() const;
    std::string getDescription() const;
    bool getReady() const;

    void changeEquipmentReadyState();
    void print() const;
};

bool operator==(const Equipment& lhs, const Equipment& rhs);
std::vector<Equipment> testEquipment();

#endif // EQUIPMENT_H
