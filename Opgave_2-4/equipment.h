#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

enum EquipmentType { Weapon,
    Ammo,
    Armor,
    Trinket,
    Consumable };

class Equipment {
private:
    std::string m_name;
    float m_price;
    EquipmentType m_type;
    float m_weight;
    std::string m_description;
    bool m_ready;

public:
    Equipment(std::string name, float price, EquipmentType type, float weight, std::string description, bool ready);

    std::string getName() const;
    float getPrice() const;
    EquipmentType getType() const;
    float getWeight() const;
    std::string getDescription() const;
    bool getReady() const;

    void changeEquipmentReadyState();
};

#endif // EQUIPMENT_H
