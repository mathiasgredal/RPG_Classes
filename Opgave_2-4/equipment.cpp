#include "equipment.h"

Equipment::Equipment(std::string name, float price, EquipmentType type, float weight, std::string description, bool ready)
{
    boost::trim(name);

    assert(("Name cannot be empty", name == ""));

    m_name = name;
    m_price = price;
    m_type = type;
    m_weight = weight;
    m_description = description;
    m_ready = ready;
}

std::string Equipment::getName() const
{
    return m_name;
}

float Equipment::getPrice() const
{
    return m_price;
}

EquipmentType Equipment::getType() const
{
    return m_type;
}

float Equipment::getWeight() const
{
    return m_weight;
}

std::string Equipment::getDescription() const
{
    return m_description;
}

bool Equipment::getReady() const
{
    return m_ready;
}

void Equipment::changeEquipmentReadyState()
{
    m_ready = !m_ready;
}
