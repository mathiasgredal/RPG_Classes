#ifndef SHOP_H
#define SHOP_H

#include <algorithm>
#include <iostream>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include "character.h"
#include "equipment.h"

struct Customer {
    boost::uuids::uuid id;
    bool allowed;
};

bool operator==(const Customer& lhs, const Customer& rhs);

class Shop {

    std::vector<Equipment> m_items;
    std::vector<Customer> m_customers;

public:
    Shop();

    void AddEquipment(const Equipment& equipment);
    void AddCustomer(const Character& customer, bool allowed);

    void BuyEquipment(Character& character, uint equipmentNr);

    void print() const;

    std::vector<Equipment> items() const;
    std::vector<Customer> customers() const;
};

#endif // SHOP_H
