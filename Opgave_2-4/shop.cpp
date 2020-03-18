#include "shop.h"

std::vector<Equipment> Shop::items() const
{
    return m_items;
}

std::vector<Customer> Shop::customers() const
{
    return m_customers;
}

Shop::Shop()
{
}

void Shop::AddEquipment(const Equipment& equipment)
{
    m_items.push_back(equipment);
}

void Shop::AddCustomer(const Character& customer, bool allowed)
{
    m_customers.push_back({ customer.uuid(), allowed });
}

void Shop::BuyEquipment(Character& character, uint equipmentNr)
{
    Equipment equipment = m_items.at(equipmentNr);

    // Do we own the equipment
    if (std::find(m_items.begin(), m_items.end(), equipment) == m_items.end()) {
        std::cout << "The requested equipment is not a part of this shops inventory, "
                     "so it cannot be bought here."
                  << std::endl;
        return;
    }

    // Do we know the customer and are they allowed
    Customer customer = { character.uuid(), true };
    if (std::find(m_customers.begin(), m_customers.end(), customer) == m_customers.end()) {
        // Either the customer wasn't allowed, or the customer wasn't found. We do another search to find out.
        customer.allowed = false;
        if (std::find(m_customers.begin(), m_customers.end(), customer) == m_customers.end())
            std::cout << "The customer was not found in the customerlist, so they cannot buy here." << std::endl;
        else
            std::cout << "The customer is not allowed in the store, so they cannot buy here." << std::endl;
        return;
    }

    // Can the customer afford the equipment
    if (!afford(character, equipment.getPrice())) {
        std::cout << "The customer cannot afford this item." << std::endl;
        return;
    }

    // Can the customer carry the equipment
    if (capacity(character, equipment.getWeight())) {
        std::cout << "The customer cannot carry this item, because it weighs too much." << std::endl;
        return;
    }

    // Now we can sell the equipment
    character.takeMoneyFromBalance(equipment.getPrice());
    character.addEquipment(equipment);
    m_items.erase(std::find(m_items.begin(), m_items.end(), equipment));
}

int getAllowedCustomersCount(const Shop& shop)
{
    int count = 0;
    for (const auto& customer : shop.customers())
        count += customer.allowed;
    return count;
}

int getDisallowedCustomersCount(const Shop& shop)
{
    int count = 0;
    for (const auto& customer : shop.customers())
        count += !customer.allowed;
    return count;
}

void Shop::print() const
{
    std::cout << "##### SHOP OVERVIEW #####\n";
    std::cout << "\t Allowed Customers: " << getAllowedCustomersCount(*this) << "\n";
    std::cout << "\t Disallowed Customers: " << getDisallowedCustomersCount(*this) << "\n";
    std::cout << "\t Inventory:" << std::endl;

    for (uint i = 0; i < m_items.size(); i++) {
        std::cout << "    " << i << ". ";
        m_items.at(i).print();
    }

    std::cout << "#########################" << std::endl;
}

bool operator==(const Customer& lhs, const Customer& rhs)
{
    return (lhs.id == rhs.id && lhs.allowed == rhs.allowed);
}
